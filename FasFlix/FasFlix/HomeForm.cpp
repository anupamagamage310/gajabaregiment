#include "HomeForm.h"
#include "DBmanager.h"
#include "MovieDetailsForm.h"
#include "AdminCatalogForm.h"
#include "WatchlistForm.h"
#include "LoginForm.h"
#include "StringHelper.h"

namespace FasFlix {

    using namespace System::IO;

    HomeForm::HomeForm(void)
    {
        this->currentUser = L"admin";
        this->isAdmin = true;
        this->isLoggingOut = false;

        InitializeComponent();
        SetupCustomUI();
    }

    HomeForm::HomeForm(System::String^ username, System::Boolean admin)
    {
        this->currentUser = username;
        this->isAdmin = admin;
        this->isLoggingOut = false;

        InitializeComponent();
        SetupCustomUI();
    }

    HomeForm::~HomeForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void HomeForm::SetupCustomUI()
    {
        // Setup User Badge
        if (this->lblUserBadge != nullptr) {
            this->lblUserBadge->Text = (isAdmin ? L"ADMIN: " : L"USER: ") + currentUser;
            this->lblUserBadge->ForeColor = isAdmin 
                ? System::Drawing::Color::FromArgb(229, 9, 20) 
                : System::Drawing::Color::FromArgb(46, 204, 113);
        }

        // Setup Admin Button Visibility
        if (this->btnNavAdmin != nullptr) {
            this->btnNavAdmin->Visible = isAdmin;
        }

        // Load Hero Image
        if (this->picHeroBg != nullptr) {
            String^ heroPath = FindAssetPath(L"hero_spiderman.jpg");
            if (File::Exists(heroPath)) {
                try {
                    this->picHeroBg->Image = Image::FromFile(heroPath);
                }
                catch (...) {}
            }
        }
    }

    System::Void HomeForm::HomeForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        LoadAllContent();
    }

    System::Void HomeForm::HomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
    {
        if (!isLoggingOut) {
            Application::Exit();
        }
    }

    System::Void HomeForm::btnNavHome_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->txtSearch->Text = L"";
        this->btnFilterAll_Click(sender, e);
    }

    System::Void HomeForm::btnNavMovies_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->txtSearch->Text = L"";
        this->lblSectionTitle->Text = L"Movies";
        LoadContentByType(L"Movie");
    }

    System::Void HomeForm::btnNavSeries_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->txtSearch->Text = L"";
        this->lblSectionTitle->Text = L"TV Series";
        LoadContentByType(L"TV Series");
    }

    System::Void HomeForm::btnNavWatchlist_Click(System::Object^ sender, System::EventArgs^ e)
    {
        WatchlistForm^ wf = gcnew WatchlistForm(this->currentUser);
        wf->ShowDialog(this);
    }

    System::Void HomeForm::btnNavAdmin_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (!isAdmin) return;
        AdminCatalogForm^ af = gcnew AdminCatalogForm();
        af->ShowDialog(this);
        // Refresh catalog when admin finishes editing
        LoadAllContent();
    }

    System::Void HomeForm::btnSignOut_Click(System::Object^ sender, System::EventArgs^ e)
    {
        System::Windows::Forms::DialogResult res = MessageBox::Show(
            L"Are you sure you want to log out of FASFLIX?",
            L"Confirm Sign Out", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (res == System::Windows::Forms::DialogResult::Yes) {
            this->isLoggingOut = true;

            // Search for existing hidden LoginForm
            bool found = false;
            for (int i = 0; i < Application::OpenForms->Count; i++) {
                LoginForm^ lf = dynamic_cast<LoginForm^>(Application::OpenForms[i]);
                if (lf != nullptr) {
                    lf->Show();
                    found = true;
                    break;
                }
            }

            if (!found) {
                LoginForm^ lf = gcnew LoginForm();
                lf->Show();
            }

            this->Close();
        }
    }

    System::Void HomeForm::btnHeroPlay_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show(
            L"Streaming has started for:\n\nSpider-Man: Across the Spider-Verse\n\nEnjoy in 4K Ultra HD on FASFLIX Cinema Player!",
            L"FASFLIX Player", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void HomeForm::btnHeroDetails_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Spider-Man Across the Spider-Verse is content ID 1
        MovieDetailsForm^ details = gcnew MovieDetailsForm(1, currentUser, isAdmin);
        details->ShowDialog(this);
    }

    System::Void HomeForm::txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
        String^ query = this->txtSearch->Text->Trim();
        if (query->Length == 0) {
            this->lblSectionTitle->Text = L"Trending Now";
            LoadAllContent();
        }
        else {
            this->lblSectionTitle->Text = L"Search Results for \"" + query + L"\"";
            SearchAndDisplay(query);
        }
    }

    void ResetFilterStyles(System::Windows::Forms::FlowLayoutPanel^ pnl)
    {
        if (pnl == nullptr) return;
        for (int i = 0; i < pnl->Controls->Count; i++) {
            Button^ b = dynamic_cast<Button^>(pnl->Controls[i]);
            if (b != nullptr) {
                b->BackColor = System::Drawing::Color::FromArgb(40, 40, 40);
                b->ForeColor = System::Drawing::Color::FromArgb(180, 180, 180);
            }
        }
    }

    System::Void HomeForm::btnFilterAll_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterAll->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterAll->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Trending Now";
        LoadAllContent();
    }

    void FilterByGenre(System::Windows::Forms::FlowLayoutPanel^ flow, System::Windows::Forms::Label^ lblNoResults, String^ genreKey)
    {
        flow->SuspendLayout();
        int visibleCount = 0;

        for (int i = 0; i < flow->Controls->Count; i++) {
            Panel^ card = dynamic_cast<Panel^>(flow->Controls[i]);
            if (card != nullptr) {
                // Find genre from card children
                bool matches = false;
                for (int j = 0; j < card->Controls->Count; j++) {
                    Label^ lbl = dynamic_cast<Label^>(card->Controls[j]);
                    if (lbl != nullptr && lbl->Text->Contains(genreKey)) {
                        matches = true;
                        break;
                    }
                }
                card->Visible = matches;
                if (matches) visibleCount++;
            }
        }

        if (lblNoResults != nullptr) {
            lblNoResults->Visible = (visibleCount == 0);
        }
        flow->ResumeLayout(true);
    }

    System::Void HomeForm::btnFilterAction_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterAction->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterAction->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Action Content";
        LoadAllContent();
        FilterByGenre(this->flowCatalog, this->lblNoResults, L"Action");
    }

    System::Void HomeForm::btnFilterSciFi_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterSciFi->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterSciFi->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Sci-Fi Content";
        LoadAllContent();
        FilterByGenre(this->flowCatalog, this->lblNoResults, L"Sci-Fi");
    }

    System::Void HomeForm::btnFilterDrama_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterDrama->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterDrama->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Drama Content";
        LoadAllContent();
        FilterByGenre(this->flowCatalog, this->lblNoResults, L"Drama");
    }

    System::Void HomeForm::btnFilterCrime_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterCrime->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterCrime->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Crime Content";
        LoadAllContent();
        FilterByGenre(this->flowCatalog, this->lblNoResults, L"Crime");
    }

    System::Void HomeForm::btnFilterAnimation_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ResetFilterStyles(this->pnlFilterChips);
        this->btnFilterAnimation->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
        this->btnFilterAnimation->ForeColor = System::Drawing::Color::White;
        this->lblSectionTitle->Text = L"Animation Content";
        LoadAllContent();
        FilterByGenre(this->flowCatalog, this->lblNoResults, L"Animation");
    }

    void PopulateCatalog(System::Windows::Forms::FlowLayoutPanel^ flow, 
                          System::Windows::Forms::Label^ lblNoResults, 
                          const std::vector<std::shared_ptr<MediaItem>>& items, 
                          HomeForm^ form)
    {
        flow->SuspendLayout();
        flow->Controls->Clear();

        if (lblNoResults != nullptr) {
            lblNoResults->Visible = items.empty();
            flow->Controls->Add(lblNoResults);
        }

        for (const auto& item : items) {
            int cid = item->getId();

            Panel^ card = gcnew Panel();
            card->Size = System::Drawing::Size(175, 290);
            card->BackColor = System::Drawing::Color::FromArgb(26, 26, 26);
            card->Margin = System::Windows::Forms::Padding(8, 8, 8, 12);
            card->Cursor = Cursors::Hand;
            card->Tag = cid;

            PictureBox^ pic = gcnew PictureBox();
            pic->Location = System::Drawing::Point(0, 0);
            pic->Size = System::Drawing::Size(175, 218);
            pic->SizeMode = PictureBoxSizeMode::StretchImage;
            pic->BackColor = System::Drawing::Color::FromArgb(40, 40, 40);
            pic->Tag = cid;

            String^ posterName = StringHelper::ToManaged(item->getPosterPath());
            String^ fullPath = form->FindAssetPath(posterName);
            if (File::Exists(fullPath)) {
                try { pic->Image = Image::FromFile(fullPath); } catch (...) {}
            }

            Label^ lblBadge = gcnew Label();
            lblBadge->Location = System::Drawing::Point(6, 6);
            lblBadge->Size = System::Drawing::Size(item->getContentType() == "Movie" ? 52 : 64, 20);
            lblBadge->BackColor = item->getContentType() == "Movie" 
                ? System::Drawing::Color::FromArgb(229, 9, 20) 
                : System::Drawing::Color::FromArgb(0, 120, 215);
            lblBadge->ForeColor = System::Drawing::Color::White;
            lblBadge->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5f, System::Drawing::FontStyle::Bold);
            lblBadge->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            lblBadge->Text = StringHelper::ToManaged(item->getBadge());
            lblBadge->Tag = cid;
            pic->Controls->Add(lblBadge);

            Label^ lblTitle = gcnew Label();
            lblTitle->Location = System::Drawing::Point(6, 222);
            lblTitle->Size = System::Drawing::Size(163, 22);
            lblTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0f, System::Drawing::FontStyle::Bold);
            lblTitle->ForeColor = System::Drawing::Color::White;
            lblTitle->AutoEllipsis = true;
            lblTitle->Text = StringHelper::ToManaged(item->getTitle());
            lblTitle->Tag = cid;

            Label^ lblInfo = gcnew Label();
            lblInfo->Location = System::Drawing::Point(6, 244);
            lblInfo->Size = System::Drawing::Size(163, 18);
            lblInfo->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0f);
            lblInfo->ForeColor = System::Drawing::Color::FromArgb(170, 170, 170);
            lblInfo->AutoEllipsis = true;
            lblInfo->Text = String::Format(L"{0} • {1}", item->getReleaseYear(), StringHelper::ToManaged(item->getDurationDisplay()));
            lblInfo->Tag = cid;

            Label^ lblRating = gcnew Label();
            lblRating->Location = System::Drawing::Point(6, 264);
            lblRating->Size = System::Drawing::Size(163, 20);
            lblRating->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0f, System::Drawing::FontStyle::Bold);
            lblRating->ForeColor = System::Drawing::Color::FromArgb(245, 197, 24);
            lblRating->AutoEllipsis = true;
            lblRating->Text = String::Format(L"Rating: {0:F1}  ({1})", item->getImdbRating(), StringHelper::ToManaged(item->getGenre()));
            lblRating->Tag = cid;

            // Wire events
            card->Click += gcnew EventHandler(form, &HomeForm::Card_Click);
            pic->Click += gcnew EventHandler(form, &HomeForm::Card_Click);
            lblBadge->Click += gcnew EventHandler(form, &HomeForm::Card_Click);
            lblTitle->Click += gcnew EventHandler(form, &HomeForm::Card_Click);
            lblInfo->Click += gcnew EventHandler(form, &HomeForm::Card_Click);
            lblRating->Click += gcnew EventHandler(form, &HomeForm::Card_Click);

            card->MouseEnter += gcnew EventHandler(form, &HomeForm::Card_MouseEnter);
            card->MouseLeave += gcnew EventHandler(form, &HomeForm::Card_MouseLeave);
            pic->MouseEnter += gcnew EventHandler(form, &HomeForm::Card_MouseEnter);
            pic->MouseLeave += gcnew EventHandler(form, &HomeForm::Card_MouseLeave);

            card->Controls->Add(pic);
            card->Controls->Add(lblTitle);
            card->Controls->Add(lblInfo);
            card->Controls->Add(lblRating);

            flow->Controls->Add(card);
        }

        flow->ResumeLayout(true);
    }

    void HomeForm::LoadAllContent()
    {
        DBmanager db;
        std::vector<std::shared_ptr<MediaItem>> items = db.getAllContent();
        PopulateCatalog(this->flowCatalog, this->lblNoResults, items, this);
    }

    void HomeForm::LoadContentByType(System::String^ type)
    {
        DBmanager db;
        std::string t = StringHelper::ToStd(type);
        std::vector<std::shared_ptr<MediaItem>> all = db.getAllContent();
        std::vector<std::shared_ptr<MediaItem>> filtered;

        for (const auto& item : all) {
            if (item->getContentType() == t) {
                filtered.push_back(item);
            }
        }

        PopulateCatalog(this->flowCatalog, this->lblNoResults, filtered, this);
    }

    void HomeForm::SearchAndDisplay(System::String^ query)
    {
        DBmanager db;
        std::string q = StringHelper::ToStd(query);
        std::vector<std::shared_ptr<MediaItem>> results = db.searchContent(q);
        PopulateCatalog(this->flowCatalog, this->lblNoResults, results, this);
    }

    System::Void HomeForm::Card_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Control^ c = dynamic_cast<Control^>(sender);
        if (c != nullptr && c->Tag != nullptr) {
            int id = Convert::ToInt32(c->Tag);
            MovieDetailsForm^ details = gcnew MovieDetailsForm(id, this->currentUser, this->isAdmin);
            details->ShowDialog(this);
        }
    }

    System::Void HomeForm::Card_MouseEnter(System::Object^ sender, System::EventArgs^ e)
    {
        Control^ c = dynamic_cast<Control^>(sender);
        Panel^ pnl = dynamic_cast<Panel^>(c);
        if (pnl == nullptr && c != nullptr && c->Parent != nullptr) {
            pnl = dynamic_cast<Panel^>(c->Parent);
        }
        if (pnl != nullptr) {
            pnl->BackColor = System::Drawing::Color::FromArgb(45, 45, 45);
        }
    }

    System::Void HomeForm::Card_MouseLeave(System::Object^ sender, System::EventArgs^ e)
    {
        Control^ c = dynamic_cast<Control^>(sender);
        Panel^ pnl = dynamic_cast<Panel^>(c);
        if (pnl == nullptr && c != nullptr && c->Parent != nullptr) {
            pnl = dynamic_cast<Panel^>(c->Parent);
        }
        if (pnl != nullptr) {
            pnl->BackColor = System::Drawing::Color::FromArgb(26, 26, 26);
        }
    }

    System::String^ HomeForm::FindAssetPath(System::String^ filename)
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

}
