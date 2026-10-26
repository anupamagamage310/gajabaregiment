#pragma once
#include "MediaItem.h"

// ============================================================================
// OOP CONCEPT: Inheritance & Polymorphism
// TVSeries inherits from MediaItem and specializes duration as Seasons / Episodes count.
// ============================================================================
class TVSeries : public MediaItem {
private:
    std::string seasons; // e.g., "4 Seasons"

public:
    TVSeries() : MediaItem(), seasons("") {
        contentType = "TV Series";
    }

    TVSeries(int id, const std::string& title, int releaseYear, const std::string& seasons,
             const std::string& genre, const std::string& director, const std::string& synopsis,
             float imdbRating, const std::string& posterPath)
        : MediaItem(id, title, "TV Series", releaseYear, genre, director, synopsis, imdbRating, posterPath),
          seasons(seasons) {}

    virtual ~TVSeries() {}

    std::string getSeasons() const { return seasons; }
    void setSeasons(const std::string& s) { seasons = s; }

    // Polymorphic implementation
    std::string getDurationDisplay() const override {
        return seasons;
    }

    std::string getBadge() const override {
        return "SERIES";
    }

    std::string getFormattedSummary() const override {
        return "[Television Series] " + title + " (" + std::to_string(releaseYear) + ") - " + seasons;
    }
};
