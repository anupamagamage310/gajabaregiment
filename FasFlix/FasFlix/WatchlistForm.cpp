#include "WatchlistForm.h"
#include "DBmanager.h"
#include "MovieDetailsForm.h"
#include "StringHelper.h"

namespace FasFlix {

    using namespace System::IO;

    WatchlistForm::WatchlistForm(void)
    {
        this->currentUser = L"User";
        InitializeComponent();
        this->lblHeader->Text = L"MY WATCHLIST (" + currentUser->ToUpper() + L")";
        LoadWatchlist();
    }

    WatchlistForm::WatchlistForm(System::String^ username)
    {
        this->currentUser = username;
        InitializeComponent();
        this->lblHeader->Text = L"MY WATCHLIST (" + currentUser->ToUpper() + L")";
        LoadWatchlist();
    }

    WatchlistForm::~WatchlistForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void WatchlistForm::LoadWatchlist()
    {
        this->flowWatchlist->Controls->Clear();
        DBmanager db;
        std::string userStr = StringHelper::ToStd(currentUser);
        std::vector<WatchlistEntry> entries = db.getUserWatchlist(userStr);

        if (entries.empty()) {
            this->lblEmpty->Visible = true;
            this->flowWatchlist->Controls->Add(this->lblEmpty);
            return;
        }

        for (const auto& entry : entries) {
            std::shared_ptr<MediaItem> item = entry.getItem();
            if (!item) continue;

            // Card panel
            Panel^ pnlItem = gcnew Panel();
            pnlItem->Size = System::Drawing::Size(880, 110);
            pnlItem->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
            pnlItem->Margin = System::Windows::Forms::Padding(5, 5, 5, 12);

            // Poster
            PictureBox^ pic = gcnew PictureBox();
            pic->Location = System::Drawing::Point(8, 8);
            pic->Size = System::Drawing::Size(70, 94);
            pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pic->BackColor = System::Drawing::Color::FromArgb(45, 45, 45);

            String^ posterName = StringHelper::ToManaged(item->getPosterPath());
            String^ fullPath = FindAssetPath(posterName);
            if (File::Exists(fullPath)) {
                try { pic->Image = Image::FromFile(fullPath); } catch (...) {}
            }
            pnlItem->Controls->Add(pic);

            // Title
            Label^ lblItemTitle = gcnew Label();
            lblItemTitle->Location = System::Drawing::Point(90, 10);
            lblItemTitle->Size = System::Drawing::Size(380, 24);
            lblItemTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold);
            lblItemTitle->ForeColor = System::Drawing::Color::White;
            lblItemTitle->Text = StringHelper::ToManaged(item->getTitle());
            pnlItem->Controls->Add(lblItemTitle);

            // Details (Type, Year, Duration, Genre) - Polymorphic!
            Label^ lblInfo = gcnew Label();
            lblInfo->Location = System::Drawing::Point(90, 36);
            lblInfo->Size = System::Drawing::Size(450, 20);
            lblInfo->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f);
            lblInfo->ForeColor = System::Drawing::Color::FromArgb(180, 180, 180);
            lblInfo->Text = String::Format(L"{0}  |  {1}  |  {2}  |  {3}",
                StringHelper::ToManaged(item->getBadge()),
                item->getReleaseYear(),
                StringHelper::ToManaged(item->getDurationDisplay()),
                StringHelper::ToManaged(item->getGenre()));
            pnlItem->Controls->Add(lblInfo);

            // User Rating & IMDb Rating
            Label^ lblRatings = gcnew Label();
            lblRatings->Location = System::Drawing::Point(90, 62);
            lblRatings->Size = System::Drawing::Size(450, 20);
            lblRatings->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
            lblRatings->ForeColor = System::Drawing::Color::FromArgb(245, 197, 24); // Gold

            float uRating = entry.getUserRating();
            String^ ratingText = (uRating > 0.0f) 
                ? String::Format(L"Your Rating: {0:F1}/10    (IMDb: {1:F1})", uRating, item->getImdbRating())
                : String::Format(L"Your Rating: Not rated yet    (IMDb: {0:F1})", item->getImdbRating());
            lblRatings->Text = ratingText;
            pnlItem->Controls->Add(lblRatings);

            // Buttons container
            int cid = item->getId();

            // Button: Details
            Button^ btnDetails = gcnew Button();
            btnDetails->Location = System::Drawing::Point(555, 35);
            btnDetails->Size = System::Drawing::Size(90, 34);
            btnDetails->Text = L"Details";
            btnDetails->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f, System::Drawing::FontStyle::Bold);
            btnDetails->BackColor = System::Drawing::Color::FromArgb(50, 50, 50);
            btnDetails->ForeColor = System::Drawing::Color::White;
            btnDetails->FlatStyle = FlatStyle::Flat;
            btnDetails->FlatAppearance->BorderSize = 0;
            btnDetails->Cursor = Cursors::Hand;
            btnDetails->Tag = cid;
            btnDetails->Click += gcnew EventHandler(this, &WatchlistForm::btnItemDetails_Click);
            pnlItem->Controls->Add(btnDetails);

            // Button: Watch Now
            Button^ btnWatch = gcnew Button();
            btnWatch->Location = System::Drawing::Point(655, 35);
            btnWatch->Size = System::Drawing::Size(100, 34);
            btnWatch->Text = L"Watch";
            btnWatch->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f, System::Drawing::FontStyle::Bold);
            btnWatch->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
            btnWatch->ForeColor = System::Drawing::Color::White;
            btnWatch->FlatStyle = FlatStyle::Flat;
            btnWatch->FlatAppearance->BorderSize = 0;
            btnWatch->Cursor = Cursors::Hand;
            btnWatch->Tag = StringHelper::ToManaged(item->getTitle());
            btnWatch->Click += gcnew EventHandler(this, &WatchlistForm::btnItemWatch_Click);
            pnlItem->Controls->Add(btnWatch);

            // Button: Remove / Drop
            Button^ btnDrop = gcnew Button();
            btnDrop->Location = System::Drawing::Point(765, 35);
            btnDrop->Size = System::Drawing::Size(95, 34);
            btnDrop->Text = L"Drop";
            btnDrop->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f, System::Drawing::FontStyle::Bold);
            btnDrop->BackColor = System::Drawing::Color::FromArgb(65, 30, 30);
            btnDrop->ForeColor = System::Drawing::Color::FromArgb(250, 140, 140);
            btnDrop->FlatStyle = FlatStyle::Flat;
            btnDrop->FlatAppearance->BorderSize = 0;
            btnDrop->Cursor = Cursors::Hand;
            btnDrop->Tag = cid;
            btnDrop->Click += gcnew EventHandler(this, &WatchlistForm::btnItemDrop_Click);
            pnlItem->Controls->Add(btnDrop);

            this->flowWatchlist->Controls->Add(pnlItem);
        }
    }

    System::String^ WatchlistForm::FindAssetPath(System::String^ filename)
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

    System::Void WatchlistForm::btnClose_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    System::Void WatchlistForm::btnItemDetails_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Button^ b = safe_cast<Button^>(sender);
        int cid = safe_cast<int>(b->Tag);
        MovieDetailsForm^ details = gcnew MovieDetailsForm(cid, currentUser, false);
        details->ShowDialog(this);
        LoadWatchlist(); // Refresh upon return
    }

    System::Void WatchlistForm::btnItemWatch_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Button^ b = safe_cast<Button^>(sender);
        String^ title = safe_cast<String^>(b->Tag);
        MessageBox::Show(L"Now Streaming:\n\n" + title + L"\n\nEnjoy on FASFLIX Cinema Player!",
            L"FASFLIX Player", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void WatchlistForm::btnItemDrop_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Button^ b = safe_cast<Button^>(sender);
        int cid = safe_cast<int>(b->Tag);
        DBmanager db;
        std::string userStr = StringHelper::ToStd(currentUser);
        if (db.removeFromWatchlist(userStr, cid)) {
            LoadWatchlist();
        }
    }

}
