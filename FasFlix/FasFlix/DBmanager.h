#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/statement.h"
#include "cppconn/resultset.h"
#include "cppconn/prepared_statement.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "mysql_connection.h"
#include "mysql_driver.h"

#include "MediaItem.h"
#include "Movie.h"
#include "TVSeries.h"
#include "WatchlistEntry.h"

// ============================================================================
// OOP CONCEPT: Inheritance & Abstraction
// Database acts as a base connection manager.
// DBmanager inherits Database and provides high-level business queries.
// ============================================================================
class Database {
public:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    Database();
    virtual ~Database();
    bool isConnected() const { return con != nullptr; }
};

class DBmanager : public Database {
public:
    // ---- User Authentication ----
    bool authenticateUser(std::string username, std::string password);

    // ---- Content Retrieval (Polymorphic collections) ----
    std::vector<std::shared_ptr<MediaItem>> getAllContent();
    std::vector<std::shared_ptr<MediaItem>> getContentByType(const std::string& type);
    std::vector<std::shared_ptr<MediaItem>> searchContent(const std::string& keyword);
    std::shared_ptr<MediaItem> getContentById(int id);

    // ---- Admin Catalog CRUD Operations ----
    bool insertContent(const std::string& title, const std::string& type, int releaseYear,
                       const std::string& durationOrSeasons, const std::string& genre,
                       const std::string& director, const std::string& synopsis,
                       float imdbRating, const std::string& posterPath);

    bool updateContent(int id, const std::string& title, const std::string& type, int releaseYear,
                       const std::string& durationOrSeasons, const std::string& genre,
                       const std::string& director, const std::string& synopsis,
                       float imdbRating, const std::string& posterPath);

    bool deleteContent(int id);

    // ---- User Watchlist & Rating Management ----
    std::vector<WatchlistEntry> getUserWatchlist(const std::string& username);
    bool addToWatchlist(const std::string& username, int contentId);
    bool removeFromWatchlist(const std::string& username, int contentId);
    bool isInWatchlist(const std::string& username, int contentId);
    bool setRating(const std::string& username, int contentId, float rating);
    float getUserRating(const std::string& username, int contentId);
};

#endif
