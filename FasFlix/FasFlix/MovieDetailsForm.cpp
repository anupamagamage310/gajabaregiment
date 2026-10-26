#include "MovieDetailsForm.h"
#include "DBmanager.h"
#include "StringHelper.h"

namespace FasFlix {

    using namespace System::IO;

    MovieDetailsForm::MovieDetailsForm(void)
    {
        this->contentId = 1;
        this->currentUser = L"User";
        this->isAdmin = false;
        this->isBookmarked = false;
        this->currentUserRating = 0.0f;

        InitializeComponent();
        PopulateRatingItems();
    }

    MovieDetailsForm::MovieDetailsForm(System::Int32 contentId, System::String^ currentUser, System::Boolean isAdmin)
    {
        this->contentId = contentId;
        this->currentUser = currentUser;
        this->isAdmin = isAdmin;
        this->isBookmarked = false;
        this->currentUserRating = 0.0f;

        InitializeComponent();
        PopulateRatingItems();
        LoadMediaDetails();
    }

    MovieDetailsForm::~MovieDetailsForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void MovieDetailsForm::PopulateRatingItems()
    {
        this->cmbRating->Items->Clear();
        for (int r = 10; r >= 1; --r) {
            this->cmbRating->Items->Add(String::Format(L"{0}.0", r));
        }
        if (this->cmbRating->Items->Count > 0) {
            this->cmbRating->SelectedIndex = 0;
        }
    }

    void MovieDetailsForm::LoadMediaDetails()
    {
        DBmanager db;
        std::shared_ptr<MediaItem> item = db.getContentById(contentId);
        if (!item) {
            MessageBox::Show(L"Content not found!", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            this->Close();
            return;
        }

        // Polymorphic calls
        this->lblTitle->Text = StringHelper::ToManaged(item->getTitle());
        this->lblBadgeType->Text = StringHelper::ToManaged(item->getBadge());
        this->lblYear->Text = item->getReleaseYear().ToString();
        this->lblDuration->Text = StringHelper::ToManaged(item->getDurationDisplay());
        this->lblImdb->Text = String::Format(L"IMDb: {0:F1}", item->getImdbRating());
        this->lblGenre->Text = L"Genre: " + StringHelper::ToManaged(item->getGenre());
        this->lblDirector->Text = L"Director: " + StringHelper::ToManaged(item->getDirector());
        this->txtSynopsis->Text = StringHelper::ToManaged(item->getSynopsis());

        // Load poster image
        String^ posterFilename = StringHelper::ToManaged(item->getPosterPath());
        String^ assetPath = FindAssetPath(posterFilename);
        if (File::Exists(assetPath)) {
            try {
                this->picPoster->Image = Image::FromFile(assetPath);
            }
            catch (...) {}
        }

        // Check watchlist status
        std::string userStr = StringHelper::ToStd(currentUser);
        this->isBookmarked = db.isInWatchlist(userStr, contentId);
        UpdateWatchlistButtonState();

        // Load user rating if present
        this->currentUserRating = db.getUserRating(userStr, contentId);
        if (this->currentUserRating > 0.0f) {
            this->lblFeedback->Text = String::Format(L"Your saved rating: {0:F1}/10", this->currentUserRating);
            int index = 10 - static_cast<int>(Math::Round(this->currentUserRating));
            if (index >= 0 && index < this->cmbRating->Items->Count) {
                this->cmbRating->SelectedIndex = index;
            }
        }
    }

    System::String^ MovieDetailsForm::FindAssetPath(System::String^ filename)
    {
        String^ appDir = Application::StartupPath;
        array<String^>^ possible = {
            Path::Combine(appDir, "assets\\" + filename),
            Path::Combine(appDir, "..\\..\\FasFlix\\assets\\" + filename),
            Path::Combine(appDir, "..\\assets\\" + filename),
            "c:\\Users\\LENOVO\\Desktop\\OOP Project\\FasFlix\\FasFlix\\assets\\" + filename
        };
        for each (String^ p in possible) {
            if (File::Exists(p)) return p;
        }
        return "";
    }

    void MovieDetailsForm::UpdateWatchlistButtonState()
    {
        if (isBookmarked) {
            this->btnWatchlistToggle->Text = L"In Watchlist (Remove)";
            this->btnWatchlistToggle->BackColor = System::Drawing::Color::FromArgb(39, 174, 96); // Green
        }
        else {
            this->btnWatchlistToggle->Text = L"+ Add to Watchlist";
            this->btnWatchlistToggle->BackColor = System::Drawing::Color::FromArgb(45, 45, 45);
        }
    }

    System::Void MovieDetailsForm::btnClose_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    System::Void MovieDetailsForm::btnWatchNow_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show(
            L"Streaming has started for:\n\n" + this->lblTitle->Text + 
            L"\n\nEnjoy your cinema experience on FASFLIX Ultra HD!",
            L"FASFLIX Player", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void MovieDetailsForm::btnWatchlistToggle_Click(System::Object^ sender, System::EventArgs^ e)
    {
        DBmanager db;
        std::string userStr = StringHelper::ToStd(currentUser);

        if (isBookmarked) {
            if (db.removeFromWatchlist(userStr, contentId)) {
                isBookmarked = false;
                UpdateWatchlistButtonState();
                this->lblFeedback->Text = L"Removed from your Watchlist.";
                this->lblFeedback->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
            }
        }
        else {
            if (db.addToWatchlist(userStr, contentId)) {
                isBookmarked = true;
                UpdateWatchlistButtonState();
                this->lblFeedback->Text = L"Added to your Watchlist!";
                this->lblFeedback->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113);
            }
        }
    }

    System::Void MovieDetailsForm::btnSaveRating_Click(System::Object^ sender, System::EventArgs^ e)
    {
        DBmanager db;
        std::string userStr = StringHelper::ToStd(currentUser);

        int selectedScore = 10 - this->cmbRating->SelectedIndex;
        float rating = static_cast<float>(selectedScore);

        if (db.setRating(userStr, contentId, rating)) {
            this->isBookmarked = true; // Rating also adds/updates in watchlist
            UpdateWatchlistButtonState();
            this->lblFeedback->Text = String::Format(L"Rating saved: {0:F1}/10. Thank you for your review!", rating);
            this->lblFeedback->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113);
        }
        else {
            this->lblFeedback->Text = L"Could not save rating. Please check database connection.";
            this->lblFeedback->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
        }
    }

}
