#pragma once
#include <string>

// ============================================================================
// OOP CONCEPT: Abstraction & Encapsulation
// MediaItem is an Abstract Base Class that encapsulates attributes common to 
// all streaming content (movies, TV series, etc.).
// ============================================================================
class MediaItem {
protected:
    int id;
    std::string title;
    std::string contentType; // "Movie" or "TV Series"
    int releaseYear;
    std::string genre;
    std::string director;
    std::string synopsis;
    float imdbRating;
    std::string posterPath;

public:
    MediaItem()
        : id(0), releaseYear(0), imdbRating(0.0f) {}

    MediaItem(int id, const std::string& title, const std::string& contentType,
              int releaseYear, const std::string& genre, const std::string& director,
              const std::string& synopsis, float imdbRating, const std::string& posterPath)
        : id(id), title(title), contentType(contentType), releaseYear(releaseYear),
          genre(genre), director(director), synopsis(synopsis),
          imdbRating(imdbRating), posterPath(posterPath) {}

    // Virtual destructor for safe polymorphic deletion
    virtual ~MediaItem() {}

    // ---- Getters (Encapsulation) ----
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getContentType() const { return contentType; }
    int getReleaseYear() const { return releaseYear; }
    std::string getGenre() const { return genre; }
    std::string getDirector() const { return director; }
    std::string getSynopsis() const { return synopsis; }
    float getImdbRating() const { return imdbRating; }
    std::string getPosterPath() const { return posterPath; }

    // ---- Setters (Encapsulation) ----
    void setId(int newId) { id = newId; }
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setContentType(const std::string& newType) { contentType = newType; }
    void setReleaseYear(int year) { releaseYear = year; }
    void setGenre(const std::string& newGenre) { genre = newGenre; }
    void setDirector(const std::string& newDirector) { director = newDirector; }
    void setSynopsis(const std::string& newSynopsis) { synopsis = newSynopsis; }
    void setImdbRating(float rating) { imdbRating = rating; }
    void setPosterPath(const std::string& path) { posterPath = path; }

    // ============================================================================
    // OOP CONCEPT: Polymorphism (Pure Virtual Methods)
    // Derived classes MUST provide their own implementation of how duration
    // is measured (e.g. minutes for movies vs seasons/episodes for TV series).
    // ============================================================================
    virtual std::string getDurationDisplay() const = 0;
    virtual std::string getBadge() const = 0;

    // Virtual helper method that can be overridden by derived classes
    virtual std::string getFormattedSummary() const {
        return title + " (" + std::to_string(releaseYear) + ") - " + genre + " [" + getDurationDisplay() + "]";
    }
};
