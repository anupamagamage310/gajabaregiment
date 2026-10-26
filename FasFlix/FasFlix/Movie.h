#pragma once
#include "MediaItem.h"

// ============================================================================
// OOP CONCEPT: Inheritance & Polymorphism
// Movie inherits from MediaItem and specializes duration as running time in minutes.
// ============================================================================
class Movie : public MediaItem {
private:
    std::string duration; // e.g., "140 min"

public:
    Movie() : MediaItem(), duration("") {
        contentType = "Movie";
    }

    Movie(int id, const std::string& title, int releaseYear, const std::string& duration,
          const std::string& genre, const std::string& director, const std::string& synopsis,
          float imdbRating, const std::string& posterPath)
        : MediaItem(id, title, "Movie", releaseYear, genre, director, synopsis, imdbRating, posterPath),
          duration(duration) {}

    virtual ~Movie() {}

    std::string getDuration() const { return duration; }
    void setDuration(const std::string& d) { duration = d; }

    // Polymorphic implementation
    std::string getDurationDisplay() const override {
        return duration;
    }

    std::string getBadge() const override {
        return "MOVIE";
    }

    std::string getFormattedSummary() const override {
        return "[Feature Film] " + title + " (" + std::to_string(releaseYear) + ") - Runtime: " + duration;
    }
};
