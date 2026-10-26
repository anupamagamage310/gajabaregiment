#include "DBmanager.h"
#include <iostream>

Database::Database() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "isuruthebest");
        con->setSchema("fasflix");
        con->setAutoCommit(true);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error connecting to the database: " << e.what() << std::endl;
        con = nullptr;
    }
}

Database::~Database() {
    if (con != nullptr) {
        try {
            con->commit();
        }
        catch (...) {}
        delete con;
        con = nullptr;
    }
}

bool DBmanager::authenticateUser(std::string username, std::string password) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT 1 FROM user WHERE Username = ? AND Password = ? LIMIT 1"));
        ps->setString(1, username);
        ps->setString(2, password);

        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        return res->next();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in authenticateUser: " << e.what() << std::endl;
        return false;
    }
}

// Helper factory to create Movie or TVSeries dynamically (Polymorphism)
static std::shared_ptr<MediaItem> createMediaFromRow(sql::ResultSet* res) {
    int id = 0;
    try {
        id = res->getInt("id");
    }
    catch (...) {
        try {
            id = res->getInt("cid");
        }
        catch (...) {
            try {
                id = res->getInt("content_id");
            }
            catch (...) {
                id = 0;
            }
        }
    }
    std::string title = res->getString("title");
    std::string type = res->getString("content_type");
    int year = res->getInt("release_year");
    std::string duration = res->getString("duration");
    std::string genre = res->getString("genre");
    std::string director = res->getString("director");
    std::string synopsis = res->getString("synopsis");
    float rating = static_cast<float>(res->getDouble("imdb_rating"));
    std::string poster = res->getString("poster_path");

    if (type == "TV Series") {
        return std::make_shared<TVSeries>(id, title, year, duration, genre, director, synopsis, rating, poster);
    }
    else {
        return std::make_shared<Movie>(id, title, year, duration, genre, director, synopsis, rating, poster);
    }
}

std::vector<std::shared_ptr<MediaItem>> DBmanager::getAllContent() {
    std::vector<std::shared_ptr<MediaItem>> items;
    if (!con) return items;

    try {
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM contents ORDER BY imdb_rating DESC"));
        while (res->next()) {
            items.push_back(createMediaFromRow(res.get()));
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in getAllContent: " << e.what() << std::endl;
    }
    return items;
}

std::vector<std::shared_ptr<MediaItem>> DBmanager::getContentByType(const std::string& type) {
    std::vector<std::shared_ptr<MediaItem>> items;
    if (!con) return items;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT * FROM contents WHERE content_type = ? ORDER BY imdb_rating DESC"));
        ps->setString(1, type);
        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        while (res->next()) {
            items.push_back(createMediaFromRow(res.get()));
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in getContentByType: " << e.what() << std::endl;
    }
    return items;
}

std::vector<std::shared_ptr<MediaItem>> DBmanager::searchContent(const std::string& keyword) {
    std::vector<std::shared_ptr<MediaItem>> items;
    if (!con) return items;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT * FROM contents WHERE title LIKE ? OR genre LIKE ? ORDER BY imdb_rating DESC"));
        std::string pattern = "%" + keyword + "%";
        ps->setString(1, pattern);
        ps->setString(2, pattern);

        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        while (res->next()) {
            items.push_back(createMediaFromRow(res.get()));
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in searchContent: " << e.what() << std::endl;
    }
    return items;
}

std::shared_ptr<MediaItem> DBmanager::getContentById(int id) {
    if (!con) return nullptr;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT * FROM contents WHERE id = ? LIMIT 1"));
        ps->setInt(1, id);

        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        if (res->next()) {
            return createMediaFromRow(res.get());
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in getContentById: " << e.what() << std::endl;
    }
    return nullptr;
}

bool DBmanager::insertContent(const std::string& title, const std::string& type, int releaseYear,
                             const std::string& durationOrSeasons, const std::string& genre,
                             const std::string& director, const std::string& synopsis,
                             float imdbRating, const std::string& posterPath) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement(
                "INSERT INTO contents (title, content_type, release_year, duration, genre, director, synopsis, imdb_rating, poster_path) "
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)"));
        ps->setString(1, title);
        ps->setString(2, type);
        ps->setInt(3, releaseYear);
        ps->setString(4, durationOrSeasons);
        ps->setString(5, genre);
        ps->setString(6, director);
        ps->setString(7, synopsis);
        ps->setDouble(8, static_cast<double>(imdbRating));
        ps->setString(9, posterPath);

        ps->executeUpdate();
        con->commit();

        // Also insert into legacy movies table if it is a Movie
        if (type == "Movie") {
            try {
                std::unique_ptr<sql::PreparedStatement> psMovie(
                    con->prepareStatement(
                        "INSERT INTO movies (Movie_ID, Title, Released_year, Duration, Language, Genre, IMDB_Rating) "
                        "VALUES (?, ?, ?, ?, 'English', ?, ?) ON DUPLICATE KEY UPDATE Title = VALUES(Title)"));
                psMovie->setString(1, std::to_string(rand() % 9000 + 1000));
                psMovie->setString(2, title);
                psMovie->setInt(3, releaseYear);
                psMovie->setString(4, durationOrSeasons);
                psMovie->setString(5, genre);
                psMovie->setDouble(6, static_cast<double>(imdbRating));
                psMovie->executeUpdate();
                con->commit();
            }
            catch (...) {}
        }

        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in insertContent: " << e.what() << std::endl;
        return false;
    }
}

bool DBmanager::updateContent(int id, const std::string& title, const std::string& type, int releaseYear,
                             const std::string& durationOrSeasons, const std::string& genre,
                             const std::string& director, const std::string& synopsis,
                             float imdbRating, const std::string& posterPath) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement(
                "UPDATE contents SET title = ?, content_type = ?, release_year = ?, duration = ?, "
                "genre = ?, director = ?, synopsis = ?, imdb_rating = ?, poster_path = ? WHERE id = ?"));
        ps->setString(1, title);
        ps->setString(2, type);
        ps->setInt(3, releaseYear);
        ps->setString(4, durationOrSeasons);
        ps->setString(5, genre);
        ps->setString(6, director);
        ps->setString(7, synopsis);
        ps->setDouble(8, static_cast<double>(imdbRating));
        ps->setString(9, posterPath);
        ps->setInt(10, id);

        ps->executeUpdate();
        con->commit();

        // Also update legacy movies table if it is a Movie
        if (type == "Movie") {
            try {
                std::unique_ptr<sql::PreparedStatement> psMovie(
                    con->prepareStatement(
                        "UPDATE movies SET Released_year = ?, Duration = ?, Genre = ?, IMDB_Rating = ? WHERE Title = ?"));
                psMovie->setInt(1, releaseYear);
                psMovie->setString(2, durationOrSeasons);
                psMovie->setString(3, genre);
                psMovie->setDouble(4, static_cast<double>(imdbRating));
                psMovie->setString(5, title);
                psMovie->executeUpdate();
                con->commit();
            }
            catch (...) {}
        }

        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in updateContent: " << e.what() << std::endl;
        return false;
    }
}

bool DBmanager::deleteContent(int id) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("DELETE FROM contents WHERE id = ?"));
        ps->setInt(1, id);
        ps->executeUpdate();
        con->commit();
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in deleteContent: " << e.what() << std::endl;
        return false;
    }
}

std::vector<WatchlistEntry> DBmanager::getUserWatchlist(const std::string& username) {
    std::vector<WatchlistEntry> list;
    if (!con) return list;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement(
                "SELECT w.id AS wid, w.username, w.content_id, w.user_rating, w.added_at, "
                "c.id AS id, c.id AS cid, c.title, c.content_type, c.release_year, c.duration, c.genre, "
                "c.director, c.synopsis, c.imdb_rating, c.poster_path "
                "FROM watchlist w JOIN contents c ON w.content_id = c.id "
                "WHERE w.username = ? ORDER BY w.added_at DESC"));
        ps->setString(1, username);

        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        while (res->next()) {
            int wid = res->getInt("wid");
            std::string user = res->getString("username");
            int cid = res->getInt("content_id");
            float userRating = res->isNull("user_rating") ? 0.0f : static_cast<float>(res->getDouble("user_rating"));
            std::string addedAt = res->getString("added_at");

            std::shared_ptr<MediaItem> item = createMediaFromRow(res.get());
            list.emplace_back(wid, user, cid, userRating, addedAt, item);
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in getUserWatchlist: " << e.what() << std::endl;
    }
    return list;
}

bool DBmanager::addToWatchlist(const std::string& username, int contentId) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement(
                "INSERT INTO watchlist (username, content_id) VALUES (?, ?) "
                "ON DUPLICATE KEY UPDATE content_id = VALUES(content_id)"));
        ps->setString(1, username);
        ps->setInt(2, contentId);
        ps->executeUpdate();
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in addToWatchlist: " << e.what() << std::endl;
        return false;
    }
}

bool DBmanager::removeFromWatchlist(const std::string& username, int contentId) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("DELETE FROM watchlist WHERE username = ? AND content_id = ?"));
        ps->setString(1, username);
        ps->setInt(2, contentId);
        return ps->executeUpdate() > 0;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in removeFromWatchlist: " << e.what() << std::endl;
        return false;
    }
}

bool DBmanager::isInWatchlist(const std::string& username, int contentId) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT 1 FROM watchlist WHERE username = ? AND content_id = ? LIMIT 1"));
        ps->setString(1, username);
        ps->setInt(2, contentId);
        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        return res->next();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in isInWatchlist: " << e.what() << std::endl;
        return false;
    }
}

bool DBmanager::setRating(const std::string& username, int contentId, float rating) {
    if (!con) return false;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement(
                "INSERT INTO watchlist (username, content_id, user_rating) VALUES (?, ?, ?) "
                "ON DUPLICATE KEY UPDATE user_rating = ?"));
        ps->setString(1, username);
        ps->setInt(2, contentId);
        ps->setDouble(3, static_cast<double>(rating));
        ps->setDouble(4, static_cast<double>(rating));
        ps->executeUpdate();
        return true;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in setRating: " << e.what() << std::endl;
        return false;
    }
}

float DBmanager::getUserRating(const std::string& username, int contentId) {
    if (!con) return 0.0f;

    try {
        std::unique_ptr<sql::PreparedStatement> ps(
            con->prepareStatement("SELECT user_rating FROM watchlist WHERE username = ? AND content_id = ? LIMIT 1"));
        ps->setString(1, username);
        ps->setInt(2, contentId);
        std::unique_ptr<sql::ResultSet> res(ps->executeQuery());
        if (res->next() && !res->isNull("user_rating")) {
            return static_cast<float>(res->getDouble("user_rating"));
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error in getUserRating: " << e.what() << std::endl;
    }
    return 0.0f;
}