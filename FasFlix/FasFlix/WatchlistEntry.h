#pragma once
#include "MediaItem.h"
#include <memory>
#include <string>

// ============================================================================
// OOP CONCEPT: Encapsulation & Composition
// WatchlistEntry encapsulates a user's bookmark, personal rating, and reference
// to the polymorphic MediaItem.
// ============================================================================
class WatchlistEntry {
private:
    int id;
    std::string username;
    int contentId;
    float userRating;
    std::string addedAt;
    std::shared_ptr<MediaItem> item;

public:
    WatchlistEntry()
        : id(0), contentId(0), userRating(0.0f), item(nullptr) {}

    WatchlistEntry(int id, const std::string& username, int contentId, float userRating,
                   const std::string& addedAt, std::shared_ptr<MediaItem> item = nullptr)
        : id(id), username(username), contentId(contentId), userRating(userRating),
          addedAt(addedAt), item(item) {}

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    int getContentId() const { return contentId; }
    float getUserRating() const { return userRating; }
    std::string getAddedAt() const { return addedAt; }
    std::shared_ptr<MediaItem> getItem() const { return item; }

    void setId(int newId) { id = newId; }
    void setUsername(const std::string& u) { username = u; }
    void setContentId(int cid) { contentId = cid; }
    void setUserRating(float r) { userRating = r; }
    void setAddedAt(const std::string& d) { addedAt = d; }
    void setItem(std::shared_ptr<MediaItem> newItem) { item = newItem; }
};
