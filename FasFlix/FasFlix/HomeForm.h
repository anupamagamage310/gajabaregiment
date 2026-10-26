#pragma once

namespace FasFlix {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for HomeForm
    /// </summary>
    public ref class HomeForm : public System::Windows::Forms::Form
    {
    public:
        HomeForm(void);
        HomeForm(System::String^ username, System::Boolean admin);

    protected:
        ~HomeForm();

    private:
        System::String^ currentUser;
        System::Boolean isAdmin;
        System::Boolean isLoggingOut;

        // Top Navigation Bar
        System::Windows::Forms::Panel^ pnlNavBar;
        System::Windows::Forms::Label^ lblLogo;
        System::Windows::Forms::Button^ btnNavHome;
        System::Windows::Forms::Button^ btnNavMovies;
        System::Windows::Forms::Button^ btnNavSeries;
        System::Windows::Forms::Button^ btnNavWatchlist;
        System::Windows::Forms::Button^ btnNavAdmin;
        System::Windows::Forms::Panel^ pnlSearchBox;
        System::Windows::Forms::Label^ lblSearchIcon;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Label^ lblUserBadge;
        System::Windows::Forms::Button^ btnSignOut;

        // Main Scrollable Area
        System::Windows::Forms::Panel^ pnlMainContainer;

        // Hero Banner Section
        System::Windows::Forms::Panel^ pnlHero;
        System::Windows::Forms::PictureBox^ picHeroBg;
        System::Windows::Forms::Label^ lblHeroTitle;
        System::Windows::Forms::Label^ lblHeroMeta;
        System::Windows::Forms::Label^ lblHeroDesc;
        System::Windows::Forms::Button^ btnHeroPlay;
        System::Windows::Forms::Button^ btnHeroDetails;

        // Content Section
        System::Windows::Forms::Label^ lblSectionTitle;
        System::Windows::Forms::FlowLayoutPanel^ pnlFilterChips;
        System::Windows::Forms::Button^ btnFilterAll;
        System::Windows::Forms::Button^ btnFilterAction;
        System::Windows::Forms::Button^ btnFilterSciFi;
        System::Windows::Forms::Button^ btnFilterDrama;
        System::Windows::Forms::Button^ btnFilterCrime;
        System::Windows::Forms::Button^ btnFilterAnimation;

        // Catalog Flow Panel
        System::Windows::Forms::FlowLayoutPanel^ flowCatalog;
        System::Windows::Forms::Label^ lblNoResults;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeForm::typeid));
            this->pnlNavBar = (gcnew System::Windows::Forms::Panel());
            this->lblLogo = (gcnew System::Windows::Forms::Label());
            this->btnNavHome = (gcnew System::Windows::Forms::Button());
            this->btnNavMovies = (gcnew System::Windows::Forms::Button());
            this->btnNavSeries = (gcnew System::Windows::Forms::Button());
            this->btnNavWatchlist = (gcnew System::Windows::Forms::Button());
            this->btnNavAdmin = (gcnew System::Windows::Forms::Button());
            this->pnlSearchBox = (gcnew System::Windows::Forms::Panel());
            this->lblSearchIcon = (gcnew System::Windows::Forms::Label());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->lblUserBadge = (gcnew System::Windows::Forms::Label());
            this->btnSignOut = (gcnew System::Windows::Forms::Button());
            this->pnlMainContainer = (gcnew System::Windows::Forms::Panel());
            this->pnlHero = (gcnew System::Windows::Forms::Panel());
            this->picHeroBg = (gcnew System::Windows::Forms::PictureBox());
            this->lblHeroTitle = (gcnew System::Windows::Forms::Label());
            this->lblHeroMeta = (gcnew System::Windows::Forms::Label());
            this->lblHeroDesc = (gcnew System::Windows::Forms::Label());
            this->btnHeroPlay = (gcnew System::Windows::Forms::Button());
            this->btnHeroDetails = (gcnew System::Windows::Forms::Button());
            this->lblSectionTitle = (gcnew System::Windows::Forms::Label());
            this->pnlFilterChips = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->btnFilterAll = (gcnew System::Windows::Forms::Button());
            this->btnFilterAction = (gcnew System::Windows::Forms::Button());
            this->btnFilterDrama = (gcnew System::Windows::Forms::Button());
            this->btnFilterCrime = (gcnew System::Windows::Forms::Button());
            this->btnFilterAnimation = (gcnew System::Windows::Forms::Button());
            this->btnFilterSciFi = (gcnew System::Windows::Forms::Button());
            this->flowCatalog = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->lblNoResults = (gcnew System::Windows::Forms::Label());
            this->pnlNavBar->SuspendLayout();
            this->pnlSearchBox->SuspendLayout();
            this->pnlMainContainer->SuspendLayout();
            this->pnlHero->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHeroBg))->BeginInit();
            this->picHeroBg->SuspendLayout();
            this->pnlFilterChips->SuspendLayout();
            this->flowCatalog->SuspendLayout();
            this->SuspendLayout();
            // 
            // pnlNavBar
            // 
            this->pnlNavBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(10)));
            this->pnlNavBar->Controls->Add(this->lblLogo);
            this->pnlNavBar->Controls->Add(this->btnNavHome);
            this->pnlNavBar->Controls->Add(this->btnNavMovies);
            this->pnlNavBar->Controls->Add(this->btnNavSeries);
            this->pnlNavBar->Controls->Add(this->btnNavWatchlist);
            this->pnlNavBar->Controls->Add(this->btnNavAdmin);
            this->pnlNavBar->Controls->Add(this->pnlSearchBox);
            this->pnlNavBar->Controls->Add(this->lblUserBadge);
            this->pnlNavBar->Controls->Add(this->btnSignOut);
            this->pnlNavBar->Dock = System::Windows::Forms::DockStyle::Top;
            this->pnlNavBar->Location = System::Drawing::Point(0, 0);
            this->pnlNavBar->Name = L"pnlNavBar";
            this->pnlNavBar->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
            this->pnlNavBar->Size = System::Drawing::Size(1348, 65);
            this->pnlNavBar->TabIndex = 0;
            // 
            // lblLogo
            // 
            this->lblLogo->Cursor = System::Windows::Forms::Cursors::Hand;
            this->lblLogo->Font = (gcnew System::Drawing::Font(L"Impact", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblLogo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(235)));
            this->lblLogo->Location = System::Drawing::Point(20, 14);
            this->lblLogo->Name = L"lblLogo";
            this->lblLogo->Size = System::Drawing::Size(130, 36);
            this->lblLogo->TabIndex = 0;
            this->lblLogo->Text = L"FASFLIX";
            this->lblLogo->Click += gcnew System::EventHandler(this, &HomeForm::btnNavHome_Click);
            // 
            // btnNavHome
            // 
            this->btnNavHome->BackColor = System::Drawing::Color::Transparent;
            this->btnNavHome->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavHome->FlatAppearance->BorderSize = 0;
            this->btnNavHome->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavHome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnNavHome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(210)));
            this->btnNavHome->Location = System::Drawing::Point(160, 17);
            this->btnNavHome->Name = L"btnNavHome";
            this->btnNavHome->Size = System::Drawing::Size(70, 32);
            this->btnNavHome->TabIndex = 1;
            this->btnNavHome->Text = L"Home";
            this->btnNavHome->UseVisualStyleBackColor = false;
            this->btnNavHome->Click += gcnew System::EventHandler(this, &HomeForm::btnNavHome_Click);
            // 
            // btnNavMovies
            // 
            this->btnNavMovies->BackColor = System::Drawing::Color::Transparent;
            this->btnNavMovies->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavMovies->FlatAppearance->BorderSize = 0;
            this->btnNavMovies->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavMovies->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnNavMovies->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(210)));
            this->btnNavMovies->Location = System::Drawing::Point(240, 17);
            this->btnNavMovies->Name = L"btnNavMovies";
            this->btnNavMovies->Size = System::Drawing::Size(75, 32);
            this->btnNavMovies->TabIndex = 2;
            this->btnNavMovies->Text = L"Movies";
            this->btnNavMovies->UseVisualStyleBackColor = false;
            this->btnNavMovies->Click += gcnew System::EventHandler(this, &HomeForm::btnNavMovies_Click);
            // 
            // btnNavSeries
            // 
            this->btnNavSeries->BackColor = System::Drawing::Color::Transparent;
            this->btnNavSeries->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavSeries->FlatAppearance->BorderSize = 0;
            this->btnNavSeries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavSeries->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnNavSeries->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(210)));
            this->btnNavSeries->Location = System::Drawing::Point(325, 17);
            this->btnNavSeries->Name = L"btnNavSeries";
            this->btnNavSeries->Size = System::Drawing::Size(90, 32);
            this->btnNavSeries->TabIndex = 3;
            this->btnNavSeries->Text = L"TV Shows";
            this->btnNavSeries->UseVisualStyleBackColor = false;
            this->btnNavSeries->Click += gcnew System::EventHandler(this, &HomeForm::btnNavSeries_Click);
            // 
            // btnNavWatchlist
            // 
            this->btnNavWatchlist->BackColor = System::Drawing::Color::Transparent;
            this->btnNavWatchlist->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavWatchlist->FlatAppearance->BorderSize = 0;
            this->btnNavWatchlist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavWatchlist->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnNavWatchlist->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
                static_cast<System::Int32>(static_cast<System::Byte>(210)));
            this->btnNavWatchlist->Location = System::Drawing::Point(425, 17);
            this->btnNavWatchlist->Name = L"btnNavWatchlist";
            this->btnNavWatchlist->Size = System::Drawing::Size(95, 32);
            this->btnNavWatchlist->TabIndex = 4;
            this->btnNavWatchlist->Text = L"My List";
            this->btnNavWatchlist->UseVisualStyleBackColor = false;
            this->btnNavWatchlist->Click += gcnew System::EventHandler(this, &HomeForm::btnNavWatchlist_Click);
            // 
            // btnNavAdmin
            // 
            this->btnNavAdmin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(235)));
            this->btnNavAdmin->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnNavAdmin->FlatAppearance->BorderSize = 0;
            this->btnNavAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnNavAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnNavAdmin->ForeColor = System::Drawing::Color::White;
            this->btnNavAdmin->Location = System::Drawing::Point(530, 15);
            this->btnNavAdmin->Name = L"btnNavAdmin";
            this->btnNavAdmin->Size = System::Drawing::Size(150, 34);
            this->btnNavAdmin->TabIndex = 5;
            this->btnNavAdmin->Text = L"Catalog Manager";
            this->btnNavAdmin->UseVisualStyleBackColor = false;
            this->btnNavAdmin->Visible = false;
            this->btnNavAdmin->Click += gcnew System::EventHandler(this, &HomeForm::btnNavAdmin_Click);
            // 
            // pnlSearchBox
            // 
            this->pnlSearchBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->pnlSearchBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->pnlSearchBox->Controls->Add(this->lblSearchIcon);
            this->pnlSearchBox->Controls->Add(this->txtSearch);
            this->pnlSearchBox->Location = System::Drawing::Point(861, 15);
            this->pnlSearchBox->Name = L"pnlSearchBox";
            this->pnlSearchBox->Size = System::Drawing::Size(215, 35);
            this->pnlSearchBox->TabIndex = 6;
            // 
            // lblSearchIcon
            // 
            this->lblSearchIcon->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblSearchIcon->ForeColor = System::Drawing::Color::Gray;
            this->lblSearchIcon->Location = System::Drawing::Point(8, 7);
            this->lblSearchIcon->Name = L"lblSearchIcon";
            this->lblSearchIcon->Size = System::Drawing::Size(24, 20);
            this->lblSearchIcon->TabIndex = 0;
            // 
            // txtSearch
            // 
            this->txtSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->txtSearch->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtSearch->ForeColor = System::Drawing::Color::White;
            this->txtSearch->Location = System::Drawing::Point(35, 8);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(170, 22);
            this->txtSearch->TabIndex = 1;
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &HomeForm::txtSearch_TextChanged);
            // 
            // lblUserBadge
            // 
            this->lblUserBadge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->lblUserBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblUserBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
                static_cast<System::Int32>(static_cast<System::Byte>(113)));
            this->lblUserBadge->Location = System::Drawing::Point(1084, 18);
            this->lblUserBadge->Name = L"lblUserBadge";
            this->lblUserBadge->Size = System::Drawing::Size(140, 28);
            this->lblUserBadge->TabIndex = 7;
            this->lblUserBadge->Text = L"User";
            this->lblUserBadge->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // btnSignOut
            // 
            this->btnSignOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnSignOut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->btnSignOut->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSignOut->FlatAppearance->BorderSize = 0;
            this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSignOut->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnSignOut->ForeColor = System::Drawing::Color::White;
            this->btnSignOut->Location = System::Drawing::Point(1231, 15);
            this->btnSignOut->Name = L"btnSignOut";
            this->btnSignOut->Size = System::Drawing::Size(95, 34);
            this->btnSignOut->TabIndex = 8;
            this->btnSignOut->Text = L"Logout";
            this->btnSignOut->UseVisualStyleBackColor = false;
            this->btnSignOut->Click += gcnew System::EventHandler(this, &HomeForm::btnSignOut_Click);
            // 
            // pnlMainContainer
            // 
            this->pnlMainContainer->AutoScroll = true;
            this->pnlMainContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
                static_cast<System::Int32>(static_cast<System::Byte>(14)));
            this->pnlMainContainer->Controls->Add(this->pnlHero);
            this->pnlMainContainer->Controls->Add(this->lblSectionTitle);
            this->pnlMainContainer->Controls->Add(this->pnlFilterChips);
            this->pnlMainContainer->Controls->Add(this->flowCatalog);
            this->pnlMainContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->pnlMainContainer->Location = System::Drawing::Point(0, 65);
            this->pnlMainContainer->Name = L"pnlMainContainer";
            this->pnlMainContainer->Size = System::Drawing::Size(1348, 713);
            this->pnlMainContainer->TabIndex = 1;
            // 
            // pnlHero
            // 
            this->pnlHero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
                static_cast<System::Int32>(static_cast<System::Byte>(18)));
            this->pnlHero->Controls->Add(this->picHeroBg);
            this->pnlHero->Location = System::Drawing::Point(0, 0);
            this->pnlHero->Name = L"pnlHero";
            this->pnlHero->Size = System::Drawing::Size(1160, 360);
            this->pnlHero->TabIndex = 0;
            // 
            // picHeroBg
            // 
            this->picHeroBg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
                static_cast<System::Int32>(static_cast<System::Byte>(18)));
            this->picHeroBg->Controls->Add(this->lblHeroTitle);
            this->picHeroBg->Controls->Add(this->lblHeroMeta);
            this->picHeroBg->Controls->Add(this->lblHeroDesc);
            this->picHeroBg->Controls->Add(this->btnHeroPlay);
            this->picHeroBg->Controls->Add(this->btnHeroDetails);
            this->picHeroBg->Dock = System::Windows::Forms::DockStyle::Fill;
            this->picHeroBg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picHeroBg.Image")));
            this->picHeroBg->Location = System::Drawing::Point(0, 0);
            this->picHeroBg->Name = L"picHeroBg";
            this->picHeroBg->Size = System::Drawing::Size(1160, 360);
            this->picHeroBg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picHeroBg->TabIndex = 0;
            this->picHeroBg->TabStop = false;
            this->picHeroBg->Click += gcnew System::EventHandler(this, &HomeForm::picHeroBg_Click);
            // 
            // lblHeroTitle
            // 
            this->lblHeroTitle->BackColor = System::Drawing::Color::Transparent;
            this->lblHeroTitle->Font = (gcnew System::Drawing::Font(L"Impact", 26, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblHeroTitle->ForeColor = System::Drawing::Color::White;
            this->lblHeroTitle->Location = System::Drawing::Point(45, 120);
            this->lblHeroTitle->Name = L"lblHeroTitle";
            this->lblHeroTitle->Size = System::Drawing::Size(750, 45);
            this->lblHeroTitle->TabIndex = 0;
            this->lblHeroTitle->Text = L"SPIDER-MAN: ACROSS THE SPIDER-VERSE";
            // 
            // lblHeroMeta
            // 
            this->lblHeroMeta->BackColor = System::Drawing::Color::Transparent;
            this->lblHeroMeta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblHeroMeta->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
                static_cast<System::Int32>(static_cast<System::Byte>(24)));
            this->lblHeroMeta->Location = System::Drawing::Point(47, 172);
            this->lblHeroMeta->Name = L"lblHeroMeta";
            this->lblHeroMeta->Size = System::Drawing::Size(600, 22);
            this->lblHeroMeta->TabIndex = 1;
            this->lblHeroMeta->Text = L"IMDb 8.7   |   2023   |   140 min   |   Animation / Action / Sci-Fi";
            // 
            // lblHeroDesc
            // 
            this->lblHeroDesc->BackColor = System::Drawing::Color::Transparent;
            this->lblHeroDesc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblHeroDesc->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(220)),
                static_cast<System::Int32>(static_cast<System::Byte>(220)));
            this->lblHeroDesc->Location = System::Drawing::Point(47, 202);
            this->lblHeroDesc->Name = L"lblHeroDesc";
            this->lblHeroDesc->Size = System::Drawing::Size(620, 55);
            this->lblHeroDesc->TabIndex = 2;
            this->lblHeroDesc->Text = L"Miles Morales catapults across the Multiverse, encountering a society of Spider-P"
                L"eople charged with protecting its very existence. Watch in Ultra HD.";
            // 
            // btnHeroPlay
            // 
            this->btnHeroPlay->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(9)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->btnHeroPlay->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnHeroPlay->FlatAppearance->BorderSize = 0;
            this->btnHeroPlay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnHeroPlay->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnHeroPlay->ForeColor = System::Drawing::Color::White;
            this->btnHeroPlay->Location = System::Drawing::Point(47, 270);
            this->btnHeroPlay->Name = L"btnHeroPlay";
            this->btnHeroPlay->Size = System::Drawing::Size(150, 42);
            this->btnHeroPlay->TabIndex = 3;
            this->btnHeroPlay->Text = L"Play Now";
            this->btnHeroPlay->UseVisualStyleBackColor = false;
            this->btnHeroPlay->Click += gcnew System::EventHandler(this, &HomeForm::btnHeroPlay_Click);
            // 
            // btnHeroDetails
            // 
            this->btnHeroDetails->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
                static_cast<System::Int32>(static_cast<System::Byte>(60)));
            this->btnHeroDetails->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnHeroDetails->FlatAppearance->BorderSize = 0;
            this->btnHeroDetails->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnHeroDetails->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnHeroDetails->ForeColor = System::Drawing::Color::White;
            this->btnHeroDetails->Location = System::Drawing::Point(212, 270);
            this->btnHeroDetails->Name = L"btnHeroDetails";
            this->btnHeroDetails->Size = System::Drawing::Size(160, 42);
            this->btnHeroDetails->TabIndex = 4;
            this->btnHeroDetails->Text = L"More Info / Rate";
            this->btnHeroDetails->UseVisualStyleBackColor = false;
            this->btnHeroDetails->Click += gcnew System::EventHandler(this, &HomeForm::btnHeroDetails_Click);
            // 
            // lblSectionTitle
            // 
            this->lblSectionTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblSectionTitle->ForeColor = System::Drawing::Color::White;
            this->lblSectionTitle->Location = System::Drawing::Point(48, 379);
            this->lblSectionTitle->Name = L"lblSectionTitle";
            this->lblSectionTitle->Size = System::Drawing::Size(300, 30);
            this->lblSectionTitle->TabIndex = 1;
            this->lblSectionTitle->Text = L"TRENDING NOW";
            // 
            // pnlFilterChips
            // 
            this->pnlFilterChips->BackColor = System::Drawing::Color::Transparent;
            this->pnlFilterChips->Controls->Add(this->btnFilterAll);
            this->pnlFilterChips->Controls->Add(this->btnFilterAction);
            this->pnlFilterChips->Controls->Add(this->btnFilterDrama);
            this->pnlFilterChips->Controls->Add(this->btnFilterCrime);
            this->pnlFilterChips->Controls->Add(this->btnFilterAnimation);
            this->pnlFilterChips->Controls->Add(this->btnFilterSciFi);
            this->pnlFilterChips->Location = System::Drawing::Point(40, 421);
            this->pnlFilterChips->Name = L"pnlFilterChips";
            this->pnlFilterChips->Size = System::Drawing::Size(1080, 40);
            this->pnlFilterChips->TabIndex = 2;
            // 
            // btnFilterAll
            // 
            this->btnFilterAll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterAll->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterAll->FlatAppearance->BorderSize = 0;
            this->btnFilterAll->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterAll->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterAll->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterAll->Location = System::Drawing::Point(0, 0);
            this->btnFilterAll->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterAll->Name = L"btnFilterAll";
            this->btnFilterAll->Size = System::Drawing::Size(90, 30);
            this->btnFilterAll->TabIndex = 0;
            this->btnFilterAll->Text = L"All";
            this->btnFilterAll->UseVisualStyleBackColor = false;
            this->btnFilterAll->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterAll_Click);
            // 
            // btnFilterAction
            // 
            this->btnFilterAction->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterAction->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterAction->FlatAppearance->BorderSize = 0;
            this->btnFilterAction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterAction->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterAction->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterAction->Location = System::Drawing::Point(98, 0);
            this->btnFilterAction->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterAction->Name = L"btnFilterAction";
            this->btnFilterAction->Size = System::Drawing::Size(90, 30);
            this->btnFilterAction->TabIndex = 1;
            this->btnFilterAction->Text = L"Action";
            this->btnFilterAction->UseVisualStyleBackColor = false;
            this->btnFilterAction->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterAction_Click);
            // 
            // btnFilterDrama
            // 
            this->btnFilterDrama->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterDrama->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterDrama->FlatAppearance->BorderSize = 0;
            this->btnFilterDrama->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterDrama->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterDrama->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterDrama->Location = System::Drawing::Point(196, 0);
            this->btnFilterDrama->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterDrama->Name = L"btnFilterDrama";
            this->btnFilterDrama->Size = System::Drawing::Size(90, 30);
            this->btnFilterDrama->TabIndex = 3;
            this->btnFilterDrama->Text = L"Drama";
            this->btnFilterDrama->UseVisualStyleBackColor = false;
            this->btnFilterDrama->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterDrama_Click);
            // 
            // btnFilterCrime
            // 
            this->btnFilterCrime->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterCrime->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterCrime->FlatAppearance->BorderSize = 0;
            this->btnFilterCrime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterCrime->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterCrime->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterCrime->Location = System::Drawing::Point(294, 0);
            this->btnFilterCrime->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterCrime->Name = L"btnFilterCrime";
            this->btnFilterCrime->Size = System::Drawing::Size(90, 30);
            this->btnFilterCrime->TabIndex = 4;
            this->btnFilterCrime->Text = L"Crime";
            this->btnFilterCrime->UseVisualStyleBackColor = false;
            this->btnFilterCrime->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterCrime_Click);
            // 
            // btnFilterAnimation
            // 
            this->btnFilterAnimation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterAnimation->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterAnimation->FlatAppearance->BorderSize = 0;
            this->btnFilterAnimation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterAnimation->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterAnimation->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterAnimation->Location = System::Drawing::Point(392, 0);
            this->btnFilterAnimation->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterAnimation->Name = L"btnFilterAnimation";
            this->btnFilterAnimation->Size = System::Drawing::Size(90, 30);
            this->btnFilterAnimation->TabIndex = 5;
            this->btnFilterAnimation->Text = L"Animation";
            this->btnFilterAnimation->UseVisualStyleBackColor = false;
            this->btnFilterAnimation->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterAnimation_Click);
            // 
            // btnFilterSciFi
            // 
            this->btnFilterSciFi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->btnFilterSciFi->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFilterSciFi->FlatAppearance->BorderSize = 0;
            this->btnFilterSciFi->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnFilterSciFi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnFilterSciFi->ForeColor = System::Drawing::Color::Silver;
            this->btnFilterSciFi->Location = System::Drawing::Point(490, 0);
            this->btnFilterSciFi->Margin = System::Windows::Forms::Padding(0, 0, 8, 0);
            this->btnFilterSciFi->Name = L"btnFilterSciFi";
            this->btnFilterSciFi->Size = System::Drawing::Size(90, 30);
            this->btnFilterSciFi->TabIndex = 2;
            this->btnFilterSciFi->Text = L"Sci-Fi";
            this->btnFilterSciFi->UseVisualStyleBackColor = false;
            this->btnFilterSciFi->Click += gcnew System::EventHandler(this, &HomeForm::btnFilterSciFi_Click);
            // 
            // flowCatalog
            // 
            this->flowCatalog->AutoScroll = true;
            this->flowCatalog->BackColor = System::Drawing::Color::Transparent;
            this->flowCatalog->Controls->Add(this->lblNoResults);
            this->flowCatalog->Location = System::Drawing::Point(40, 479);
            this->flowCatalog->Name = L"flowCatalog";
            this->flowCatalog->Padding = System::Windows::Forms::Padding(5);
            this->flowCatalog->Size = System::Drawing::Size(1279, 482);
            this->flowCatalog->TabIndex = 3;
            this->flowCatalog->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HomeForm::flowCatalog_Paint);
            // 
            // lblNoResults
            // 
            this->lblNoResults->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblNoResults->ForeColor = System::Drawing::Color::Gray;
            this->lblNoResults->Location = System::Drawing::Point(8, 5);
            this->lblNoResults->Name = L"lblNoResults";
            this->lblNoResults->Size = System::Drawing::Size(800, 60);
            this->lblNoResults->TabIndex = 0;
            this->lblNoResults->Text = L"No movies or series found matching your search.";
            this->lblNoResults->Visible = false;
            this->lblNoResults->Click += gcnew System::EventHandler(this, &HomeForm::lblNoResults_Click);
            // 
            // HomeForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
                static_cast<System::Int32>(static_cast<System::Byte>(14)));
            this->ClientSize = System::Drawing::Size(1348, 778);
            this->Controls->Add(this->pnlMainContainer);
            this->Controls->Add(this->pnlNavBar);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MinimumSize = System::Drawing::Size(1100, 700);
            this->Name = L"HomeForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"FASFLIX - Streaming Entertainment";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &HomeForm::HomeForm_FormClosing);
            this->Load += gcnew System::EventHandler(this, &HomeForm::HomeForm_Load);
            this->pnlNavBar->ResumeLayout(false);
            this->pnlSearchBox->ResumeLayout(false);
            this->pnlSearchBox->PerformLayout();
            this->pnlMainContainer->ResumeLayout(false);
            this->pnlHero->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHeroBg))->EndInit();
            this->picHeroBg->ResumeLayout(false);
            this->pnlFilterChips->ResumeLayout(false);
            this->flowCatalog->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void HomeForm_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void HomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
        System::Void btnNavHome_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnNavMovies_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnNavSeries_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnNavWatchlist_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnNavAdmin_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnHeroPlay_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnHeroDetails_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterAll_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterAction_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterSciFi_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterDrama_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterCrime_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnFilterAnimation_Click(System::Object^ sender, System::EventArgs^ e);
    public:
        System::Void Card_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void Card_MouseEnter(System::Object^ sender, System::EventArgs^ e);
        System::Void Card_MouseLeave(System::Object^ sender, System::EventArgs^ e);
        System::String^ FindAssetPath(System::String^ filename);

    private:
        void SetupCustomUI();
        void LoadAllContent();
        void LoadContentByType(System::String^ type);
        void SearchAndDisplay(System::String^ query);

private: System::Void flowCatalog_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void lblNoResults_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void picHeroBg_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
