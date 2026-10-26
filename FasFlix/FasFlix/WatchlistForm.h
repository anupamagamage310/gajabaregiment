#pragma once

namespace FasFlix {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class WatchlistForm : public System::Windows::Forms::Form
    {
    public:
        WatchlistForm(void);
        WatchlistForm(System::String^ username);

    protected:
        ~WatchlistForm();

    private:
        System::String^ currentUser;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ lblHeader;
        System::Windows::Forms::Label^ lblSubHeader;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::FlowLayoutPanel^ flowWatchlist;
        System::Windows::Forms::Label^ lblEmpty;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblHeader = (gcnew System::Windows::Forms::Label());
            this->lblSubHeader = (gcnew System::Windows::Forms::Label());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->flowWatchlist = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->lblEmpty = (gcnew System::Windows::Forms::Label());
            this->flowWatchlist->SuspendLayout();
            this->SuspendLayout();
            // 
            // lblHeader
            // 
            this->lblHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblHeader->ForeColor = System::Drawing::Color::White;
            this->lblHeader->Location = System::Drawing::Point(30, 20);
            this->lblHeader->Name = L"lblHeader";
            this->lblHeader->Size = System::Drawing::Size(600, 32);
            this->lblHeader->TabIndex = 0;
            this->lblHeader->Text = L"MY WATCHLIST";
            // 
            // lblSubHeader
            // 
            this->lblSubHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblSubHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(170)), 
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lblSubHeader->Location = System::Drawing::Point(32, 54);
            this->lblSubHeader->Name = L"lblSubHeader";
            this->lblSubHeader->Size = System::Drawing::Size(600, 20);
            this->lblSubHeader->TabIndex = 1;
            this->lblSubHeader->Text = L"Manage your saved movies and TV series, watch instantly, or update your personal ratings.";
            // 
            // btnClose
            // 
            this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), 
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::White;
            this->btnClose->Location = System::Drawing::Point(925, 18);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(36, 36);
            this->btnClose->TabIndex = 2;
            this->btnClose->Text = L"X";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &WatchlistForm::btnClose_Click);
            // 
            // flowWatchlist
            // 
            this->flowWatchlist->AutoScroll = true;
            this->flowWatchlist->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(22)), 
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->flowWatchlist->Controls->Add(this->lblEmpty);
            this->flowWatchlist->Location = System::Drawing::Point(30, 90);
            this->flowWatchlist->Name = L"flowWatchlist";
            this->flowWatchlist->Padding = System::Windows::Forms::Padding(10);
            this->flowWatchlist->Size = System::Drawing::Size(920, 500);
            this->flowWatchlist->TabIndex = 3;
            // 
            // lblEmpty
            // 
            this->lblEmpty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic));
            this->lblEmpty->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(130)), 
                static_cast<System::Int32>(static_cast<System::Byte>(130)));
            this->lblEmpty->Location = System::Drawing::Point(13, 10);
            this->lblEmpty->Name = L"lblEmpty";
            this->lblEmpty->Size = System::Drawing::Size(520, 80);
            this->lblEmpty->TabIndex = 0;
            this->lblEmpty->Text = L"Your Watchlist is empty.\nBrowse the catalog and click \'＋ Add to Watchlist\' on an" 
                L"y title!";
            this->lblEmpty->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblEmpty->Visible = false;
            // 
            // WatchlistForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)), 
                static_cast<System::Int32>(static_cast<System::Byte>(18)));
            this->ClientSize = System::Drawing::Size(980, 620);
            this->Controls->Add(this->flowWatchlist);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->lblSubHeader);
            this->Controls->Add(this->lblHeader);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"WatchlistForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"FASFLIX - My Watchlist";
            this->flowWatchlist->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        void LoadWatchlist();
        System::String^ FindAssetPath(System::String^ filename);
        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnItemDetails_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnItemWatch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnItemDrop_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
