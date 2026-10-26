#pragma once

namespace FasFlix {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MovieDetailsForm : public System::Windows::Forms::Form
    {
    public:
        MovieDetailsForm(void);
        MovieDetailsForm(System::Int32 contentId, System::String^ currentUser, System::Boolean isAdmin);

    protected:
        ~MovieDetailsForm();

    private:
        System::Int32 contentId;
        System::String^ currentUser;
        System::Boolean isAdmin;
        System::Boolean isBookmarked;
        System::Single currentUserRating;

        System::ComponentModel::Container^ components;
        System::Windows::Forms::PictureBox^ picPoster;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblBadgeType;
        System::Windows::Forms::Label^ lblYear;
        System::Windows::Forms::Label^ lblDuration;
        System::Windows::Forms::Label^ lblImdb;
        System::Windows::Forms::Label^ lblGenre;
        System::Windows::Forms::Label^ lblDirector;
        System::Windows::Forms::TextBox^ txtSynopsis;
        System::Windows::Forms::Button^ btnWatchNow;
        System::Windows::Forms::Button^ btnWatchlistToggle;
        System::Windows::Forms::Label^ lblYourRating;
        System::Windows::Forms::ComboBox^ cmbRating;
        System::Windows::Forms::Button^ btnSaveRating;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::Label^ lblFeedback;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->picPoster = (gcnew System::Windows::Forms::PictureBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblBadgeType = (gcnew System::Windows::Forms::Label());
            this->lblYear = (gcnew System::Windows::Forms::Label());
            this->lblDuration = (gcnew System::Windows::Forms::Label());
            this->lblImdb = (gcnew System::Windows::Forms::Label());
            this->lblGenre = (gcnew System::Windows::Forms::Label());
            this->lblDirector = (gcnew System::Windows::Forms::Label());
            this->txtSynopsis = (gcnew System::Windows::Forms::TextBox());
            this->btnWatchNow = (gcnew System::Windows::Forms::Button());
            this->btnWatchlistToggle = (gcnew System::Windows::Forms::Button());
            this->lblYourRating = (gcnew System::Windows::Forms::Label());
            this->cmbRating = (gcnew System::Windows::Forms::ComboBox());
            this->btnSaveRating = (gcnew System::Windows::Forms::Button());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->lblFeedback = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster))->BeginInit();
            this->SuspendLayout();
            // 
            // picPoster
            // 
            this->picPoster->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->picPoster->Location = System::Drawing::Point(25, 25);
            this->picPoster->Name = L"picPoster";
            this->picPoster->Size = System::Drawing::Size(200, 290);
            this->picPoster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picPoster->TabIndex = 0;
            this->picPoster->TabStop = false;
            // 
            // lblTitle
            // 
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->Location = System::Drawing::Point(245, 25);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(370, 60);
            this->lblTitle->TabIndex = 1;
            this->lblTitle->Text = L"Movie Title";
            // 
            // lblBadgeType
            // 
            this->lblBadgeType->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(9)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->lblBadgeType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lblBadgeType->ForeColor = System::Drawing::Color::White;
            this->lblBadgeType->Location = System::Drawing::Point(245, 90);
            this->lblBadgeType->Name = L"lblBadgeType";
            this->lblBadgeType->Size = System::Drawing::Size(75, 24);
            this->lblBadgeType->TabIndex = 2;
            this->lblBadgeType->Text = L"MOVIE";
            this->lblBadgeType->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblYear
            // 
            this->lblYear->AutoSize = true;
            this->lblYear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblYear->ForeColor = System::Drawing::Color::Silver;
            this->lblYear->Location = System::Drawing::Point(330, 93);
            this->lblYear->Name = L"lblYear";
            this->lblYear->Size = System::Drawing::Size(41, 20);
            this->lblYear->TabIndex = 3;
            this->lblYear->Text = L"2023";
            // 
            // lblDuration
            // 
            this->lblDuration->AutoSize = true;
            this->lblDuration->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblDuration->ForeColor = System::Drawing::Color::Silver;
            this->lblDuration->Location = System::Drawing::Point(385, 93);
            this->lblDuration->Name = L"lblDuration";
            this->lblDuration->Size = System::Drawing::Size(62, 20);
            this->lblDuration->TabIndex = 4;
            this->lblDuration->Text = L"140 min";
            // 
            // lblImdb
            // 
            this->lblImdb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
                static_cast<System::Int32>(static_cast<System::Byte>(24)));
            this->lblImdb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblImdb->ForeColor = System::Drawing::Color::Black;
            this->lblImdb->Location = System::Drawing::Point(470, 91);
            this->lblImdb->Name = L"lblImdb";
            this->lblImdb->Size = System::Drawing::Size(68, 22);
            this->lblImdb->TabIndex = 5;
            this->lblImdb->Text = L"8.7";
            this->lblImdb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblImdb->Click += gcnew System::EventHandler(this, &MovieDetailsForm::lblImdb_Click);
            // 
            // lblGenre
            // 
            this->lblGenre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblGenre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(180)));
            this->lblGenre->Location = System::Drawing::Point(245, 125);
            this->lblGenre->Name = L"lblGenre";
            this->lblGenre->Size = System::Drawing::Size(400, 22);
            this->lblGenre->TabIndex = 6;
            this->lblGenre->Text = L"Genre: Action / Sci-Fi";
            // 
            // lblDirector
            // 
            this->lblDirector->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblDirector->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
                static_cast<System::Int32>(static_cast<System::Byte>(180)));
            this->lblDirector->Location = System::Drawing::Point(245, 150);
            this->lblDirector->Name = L"lblDirector";
            this->lblDirector->Size = System::Drawing::Size(400, 22);
            this->lblDirector->TabIndex = 7;
            this->lblDirector->Text = L"Director: Christopher Nolan";
            // 
            // txtSynopsis
            // 
            this->txtSynopsis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
                static_cast<System::Int32>(static_cast<System::Byte>(28)));
            this->txtSynopsis->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtSynopsis->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->txtSynopsis->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(220)),
                static_cast<System::Int32>(static_cast<System::Byte>(220)));
            this->txtSynopsis->Location = System::Drawing::Point(245, 180);
            this->txtSynopsis->Multiline = true;
            this->txtSynopsis->Name = L"txtSynopsis";
            this->txtSynopsis->ReadOnly = true;
            this->txtSynopsis->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->txtSynopsis->Size = System::Drawing::Size(410, 135);
            this->txtSynopsis->TabIndex = 8;
            // 
            // btnWatchNow
            // 
            this->btnWatchNow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(9)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->btnWatchNow->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnWatchNow->FlatAppearance->BorderSize = 0;
            this->btnWatchNow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnWatchNow->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->btnWatchNow->ForeColor = System::Drawing::Color::White;
            this->btnWatchNow->Location = System::Drawing::Point(25, 335);
            this->btnWatchNow->Name = L"btnWatchNow";
            this->btnWatchNow->Size = System::Drawing::Size(200, 42);
            this->btnWatchNow->TabIndex = 9;
            this->btnWatchNow->Text = L"Watch Now";
            this->btnWatchNow->UseVisualStyleBackColor = false;
            this->btnWatchNow->Click += gcnew System::EventHandler(this, &MovieDetailsForm::btnWatchNow_Click);
            // 
            // btnWatchlistToggle
            // 
            this->btnWatchlistToggle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->btnWatchlistToggle->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnWatchlistToggle->FlatAppearance->BorderSize = 0;
            this->btnWatchlistToggle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnWatchlistToggle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnWatchlistToggle->ForeColor = System::Drawing::Color::White;
            this->btnWatchlistToggle->Location = System::Drawing::Point(26, 390);
            this->btnWatchlistToggle->Name = L"btnWatchlistToggle";
            this->btnWatchlistToggle->Size = System::Drawing::Size(200, 40);
            this->btnWatchlistToggle->TabIndex = 10;
            this->btnWatchlistToggle->Text = L"Add to Watchlist";
            this->btnWatchlistToggle->UseVisualStyleBackColor = false;
            this->btnWatchlistToggle->Click += gcnew System::EventHandler(this, &MovieDetailsForm::btnWatchlistToggle_Click);
            // 
            // lblYourRating
            // 
            this->lblYourRating->AutoSize = true;
            this->lblYourRating->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblYourRating->ForeColor = System::Drawing::Color::White;
            this->lblYourRating->Location = System::Drawing::Point(245, 335);
            this->lblYourRating->Name = L"lblYourRating";
            this->lblYourRating->Size = System::Drawing::Size(151, 23);
            this->lblYourRating->TabIndex = 11;
            this->lblYourRating->Text = L"Rate this content:";
            // 
            // cmbRating
            // 
            this->cmbRating->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->cmbRating->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbRating->ForeColor = System::Drawing::Color::White;
            this->cmbRating->FormattingEnabled = true;
            this->cmbRating->Location = System::Drawing::Point(245, 365);
            this->cmbRating->Name = L"cmbRating";
            this->cmbRating->Size = System::Drawing::Size(130, 24);
            this->cmbRating->TabIndex = 12;
            // 
            // btnSaveRating
            // 
            this->btnSaveRating->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)));
            this->btnSaveRating->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSaveRating->FlatAppearance->BorderSize = 0;
            this->btnSaveRating->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSaveRating->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnSaveRating->ForeColor = System::Drawing::Color::White;
            this->btnSaveRating->Location = System::Drawing::Point(390, 363);
            this->btnSaveRating->Name = L"btnSaveRating";
            this->btnSaveRating->Size = System::Drawing::Size(120, 32);
            this->btnSaveRating->TabIndex = 13;
            this->btnSaveRating->Text = L"Save Rating";
            this->btnSaveRating->UseVisualStyleBackColor = false;
            this->btnSaveRating->Click += gcnew System::EventHandler(this, &MovieDetailsForm::btnSaveRating_Click);
            // 
            // btnClose
            // 
            this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
                static_cast<System::Int32>(static_cast<System::Byte>(200)));
            this->btnClose->Location = System::Drawing::Point(635, 12);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(33, 33);
            this->btnClose->TabIndex = 14;
            this->btnClose->Text = L"X";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &MovieDetailsForm::btnClose_Click);
            // 
            // lblFeedback
            // 
            this->lblFeedback->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic));
            this->lblFeedback->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
                static_cast<System::Int32>(static_cast<System::Byte>(113)));
            this->lblFeedback->Location = System::Drawing::Point(245, 410);
            this->lblFeedback->Name = L"lblFeedback";
            this->lblFeedback->Size = System::Drawing::Size(380, 25);
            this->lblFeedback->TabIndex = 15;
            // 
            // MovieDetailsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->ClientSize = System::Drawing::Size(680, 520);
            this->Controls->Add(this->lblFeedback);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->btnSaveRating);
            this->Controls->Add(this->cmbRating);
            this->Controls->Add(this->lblYourRating);
            this->Controls->Add(this->btnWatchlistToggle);
            this->Controls->Add(this->btnWatchNow);
            this->Controls->Add(this->txtSynopsis);
            this->Controls->Add(this->lblDirector);
            this->Controls->Add(this->lblGenre);
            this->Controls->Add(this->lblImdb);
            this->Controls->Add(this->lblDuration);
            this->Controls->Add(this->lblYear);
            this->Controls->Add(this->lblBadgeType);
            this->Controls->Add(this->lblTitle);
            this->Controls->Add(this->picPoster);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MovieDetailsForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"FASFLIX - Content Details";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void PopulateRatingItems();
        void LoadMediaDetails();
        void UpdateWatchlistButtonState();
        System::String^ FindAssetPath(System::String^ filename);
        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnWatchNow_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnWatchlistToggle_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSaveRating_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void lblImdb_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
