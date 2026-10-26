#pragma once

namespace FasFlix {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AdminCatalogForm : public System::Windows::Forms::Form
    {
    public:
        AdminCatalogForm(void);

    protected:
        ~AdminCatalogForm();

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ lblHeader;
        System::Windows::Forms::Label^ lblSubHeader;
        System::Windows::Forms::DataGridView^ dgvCatalog;
        System::Windows::Forms::Panel^ pnlEditor;
        System::Windows::Forms::Label^ lblId;
        System::Windows::Forms::TextBox^ txtId;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::TextBox^ txtTitle;
        System::Windows::Forms::Label^ lblType;
        System::Windows::Forms::ComboBox^ cmbType;
        System::Windows::Forms::Label^ lblYear;
        System::Windows::Forms::TextBox^ txtYear;
        System::Windows::Forms::Label^ lblDuration;
        System::Windows::Forms::TextBox^ txtDuration;
        System::Windows::Forms::Label^ lblGenre;
        System::Windows::Forms::TextBox^ txtGenre;
        System::Windows::Forms::Label^ lblDirector;
        System::Windows::Forms::TextBox^ txtDirector;
        System::Windows::Forms::Label^ lblRating;
        System::Windows::Forms::TextBox^ txtRating;
        System::Windows::Forms::Label^ lblPoster;
        System::Windows::Forms::TextBox^ txtPoster;
        System::Windows::Forms::Label^ lblSynopsis;
        System::Windows::Forms::TextBox^ txtSynopsis;

        System::Windows::Forms::Button^ btnInsert;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::Label^ lblStatus;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->lblHeader = (gcnew System::Windows::Forms::Label());
            this->lblSubHeader = (gcnew System::Windows::Forms::Label());
            this->dgvCatalog = (gcnew System::Windows::Forms::DataGridView());
            this->pnlEditor = (gcnew System::Windows::Forms::Panel());
            this->lblId = (gcnew System::Windows::Forms::Label());
            this->txtId = (gcnew System::Windows::Forms::TextBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->txtTitle = (gcnew System::Windows::Forms::TextBox());
            this->lblType = (gcnew System::Windows::Forms::Label());
            this->cmbType = (gcnew System::Windows::Forms::ComboBox());
            this->lblYear = (gcnew System::Windows::Forms::Label());
            this->txtYear = (gcnew System::Windows::Forms::TextBox());
            this->lblDuration = (gcnew System::Windows::Forms::Label());
            this->txtDuration = (gcnew System::Windows::Forms::TextBox());
            this->lblGenre = (gcnew System::Windows::Forms::Label());
            this->txtGenre = (gcnew System::Windows::Forms::TextBox());
            this->lblDirector = (gcnew System::Windows::Forms::Label());
            this->txtDirector = (gcnew System::Windows::Forms::TextBox());
            this->lblRating = (gcnew System::Windows::Forms::Label());
            this->txtRating = (gcnew System::Windows::Forms::TextBox());
            this->lblPoster = (gcnew System::Windows::Forms::Label());
            this->txtPoster = (gcnew System::Windows::Forms::TextBox());
            this->lblSynopsis = (gcnew System::Windows::Forms::Label());
            this->txtSynopsis = (gcnew System::Windows::Forms::TextBox());
            this->btnInsert = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->lblStatus = (gcnew System::Windows::Forms::Label());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->BeginInit();
            this->pnlEditor->SuspendLayout();
            this->SuspendLayout();
            // 
            // lblHeader
            // 
            this->lblHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(235)));
            this->lblHeader->Location = System::Drawing::Point(25, 18);
            this->lblHeader->Name = L"lblHeader";
            this->lblHeader->Size = System::Drawing::Size(600, 32);
            this->lblHeader->TabIndex = 0;
            this->lblHeader->Text = L"FASFLIX - CONTENT CATALOG MANAGER (ADMIN)";
            this->lblHeader->Click += gcnew System::EventHandler(this, &AdminCatalogForm::lblHeader_Click);
            // 
            // lblSubHeader
            // 
            this->lblSubHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblSubHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(170)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lblSubHeader->Location = System::Drawing::Point(27, 52);
            this->lblSubHeader->Name = L"lblSubHeader";
            this->lblSubHeader->Size = System::Drawing::Size(600, 20);
            this->lblSubHeader->TabIndex = 1;
            this->lblSubHeader->Text = L"Add new movies/series, update existing media information, or remove titles from t"
                L"he catalog.";
            // 
            // dgvCatalog
            // 
            this->dgvCatalog->AllowUserToAddRows = false;
            this->dgvCatalog->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
                static_cast<System::Int32>(static_cast<System::Byte>(28)));
            this->dgvCatalog->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dgvCatalog->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
                static_cast<System::Int32>(static_cast<System::Byte>(28)));
            dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            dataGridViewCellStyle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
                static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(220)));
            dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
                static_cast<System::Int32>(static_cast<System::Byte>(9)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
            dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
            dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dgvCatalog->DefaultCellStyle = dataGridViewCellStyle3;
            this->dgvCatalog->EnableHeadersVisualStyles = false;
            this->dgvCatalog->Location = System::Drawing::Point(25, 85);
            this->dgvCatalog->MultiSelect = false;
            this->dgvCatalog->Name = L"dgvCatalog";
            this->dgvCatalog->ReadOnly = true;
            this->dgvCatalog->RowHeadersVisible = false;
            this->dgvCatalog->RowHeadersWidth = 51;
            this->dgvCatalog->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvCatalog->Size = System::Drawing::Size(620, 545);
            this->dgvCatalog->TabIndex = 3;
            this->dgvCatalog->SelectionChanged += gcnew System::EventHandler(this, &AdminCatalogForm::dgvCatalog_SelectionChanged);
            // 
            // pnlEditor
            // 
            this->pnlEditor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
                static_cast<System::Int32>(static_cast<System::Byte>(25)));
            this->pnlEditor->Controls->Add(this->lblId);
            this->pnlEditor->Controls->Add(this->txtId);
            this->pnlEditor->Controls->Add(this->lblTitle);
            this->pnlEditor->Controls->Add(this->txtTitle);
            this->pnlEditor->Controls->Add(this->lblType);
            this->pnlEditor->Controls->Add(this->cmbType);
            this->pnlEditor->Controls->Add(this->lblYear);
            this->pnlEditor->Controls->Add(this->txtYear);
            this->pnlEditor->Controls->Add(this->lblDuration);
            this->pnlEditor->Controls->Add(this->txtDuration);
            this->pnlEditor->Controls->Add(this->lblGenre);
            this->pnlEditor->Controls->Add(this->txtGenre);
            this->pnlEditor->Controls->Add(this->lblDirector);
            this->pnlEditor->Controls->Add(this->txtDirector);
            this->pnlEditor->Controls->Add(this->lblRating);
            this->pnlEditor->Controls->Add(this->txtRating);
            this->pnlEditor->Controls->Add(this->lblPoster);
            this->pnlEditor->Controls->Add(this->txtPoster);
            this->pnlEditor->Controls->Add(this->lblSynopsis);
            this->pnlEditor->Controls->Add(this->txtSynopsis);
            this->pnlEditor->Controls->Add(this->btnInsert);
            this->pnlEditor->Controls->Add(this->btnUpdate);
            this->pnlEditor->Controls->Add(this->btnDelete);
            this->pnlEditor->Controls->Add(this->btnClear);
            this->pnlEditor->Controls->Add(this->lblStatus);
            this->pnlEditor->Location = System::Drawing::Point(660, 85);
            this->pnlEditor->Name = L"pnlEditor";
            this->pnlEditor->Size = System::Drawing::Size(415, 545);
            this->pnlEditor->TabIndex = 4;
            // 
            // lblId
            // 
            this->lblId->ForeColor = System::Drawing::Color::Silver;
            this->lblId->Location = System::Drawing::Point(15, 15);
            this->lblId->Name = L"lblId";
            this->lblId->Size = System::Drawing::Size(100, 20);
            this->lblId->TabIndex = 0;
            this->lblId->Text = L"Content ID:";
            // 
            // txtId
            // 
            this->txtId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->txtId->ForeColor = System::Drawing::Color::DarkGray;
            this->txtId->Location = System::Drawing::Point(120, 12);
            this->txtId->Name = L"txtId";
            this->txtId->ReadOnly = true;
            this->txtId->Size = System::Drawing::Size(100, 22);
            this->txtId->TabIndex = 1;
            // 
            // lblTitle
            // 
            this->lblTitle->ForeColor = System::Drawing::Color::Silver;
            this->lblTitle->Location = System::Drawing::Point(15, 63);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(100, 20);
            this->lblTitle->TabIndex = 2;
            this->lblTitle->Text = L"Title:";
            // 
            // txtTitle
            // 
            this->txtTitle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtTitle->ForeColor = System::Drawing::Color::White;
            this->txtTitle->Location = System::Drawing::Point(120, 60);
            this->txtTitle->Name = L"txtTitle";
            this->txtTitle->Size = System::Drawing::Size(275, 22);
            this->txtTitle->TabIndex = 3;
            // 
            // lblType
            // 
            this->lblType->ForeColor = System::Drawing::Color::Silver;
            this->lblType->Location = System::Drawing::Point(15, 111);
            this->lblType->Name = L"lblType";
            this->lblType->Size = System::Drawing::Size(100, 20);
            this->lblType->TabIndex = 4;
            this->lblType->Text = L"Type:";
            // 
            // cmbType
            // 
            this->cmbType->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->cmbType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbType->ForeColor = System::Drawing::Color::White;
            this->cmbType->FormattingEnabled = true;
            this->cmbType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Movie", L"TV Series" });
            this->cmbType->Location = System::Drawing::Point(120, 108);
            this->cmbType->Name = L"cmbType";
            this->cmbType->Size = System::Drawing::Size(140, 24);
            this->cmbType->TabIndex = 5;
            // 
            // lblYear
            // 
            this->lblYear->ForeColor = System::Drawing::Color::Silver;
            this->lblYear->Location = System::Drawing::Point(15, 159);
            this->lblYear->Name = L"lblYear";
            this->lblYear->Size = System::Drawing::Size(45, 20);
            this->lblYear->TabIndex = 6;
            this->lblYear->Text = L"Year:";
            // 
            // txtYear
            // 
            this->txtYear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtYear->ForeColor = System::Drawing::Color::White;
            this->txtYear->Location = System::Drawing::Point(65, 156);
            this->txtYear->Name = L"txtYear";
            this->txtYear->Size = System::Drawing::Size(65, 22);
            this->txtYear->TabIndex = 7;
            // 
            // lblDuration
            // 
            this->lblDuration->ForeColor = System::Drawing::Color::Silver;
            this->lblDuration->Location = System::Drawing::Point(145, 159);
            this->lblDuration->Name = L"lblDuration";
            this->lblDuration->Size = System::Drawing::Size(65, 20);
            this->lblDuration->TabIndex = 8;
            this->lblDuration->Text = L"Duration:";
            // 
            // txtDuration
            // 
            this->txtDuration->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtDuration->ForeColor = System::Drawing::Color::White;
            this->txtDuration->Location = System::Drawing::Point(215, 156);
            this->txtDuration->Name = L"txtDuration";
            this->txtDuration->Size = System::Drawing::Size(180, 22);
            this->txtDuration->TabIndex = 9;
            // 
            // lblGenre
            // 
            this->lblGenre->ForeColor = System::Drawing::Color::Silver;
            this->lblGenre->Location = System::Drawing::Point(15, 207);
            this->lblGenre->Name = L"lblGenre";
            this->lblGenre->Size = System::Drawing::Size(100, 20);
            this->lblGenre->TabIndex = 10;
            this->lblGenre->Text = L"Genre:";
            // 
            // txtGenre
            // 
            this->txtGenre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtGenre->ForeColor = System::Drawing::Color::White;
            this->txtGenre->Location = System::Drawing::Point(120, 204);
            this->txtGenre->Name = L"txtGenre";
            this->txtGenre->Size = System::Drawing::Size(275, 22);
            this->txtGenre->TabIndex = 11;
            // 
            // lblDirector
            // 
            this->lblDirector->ForeColor = System::Drawing::Color::Silver;
            this->lblDirector->Location = System::Drawing::Point(15, 255);
            this->lblDirector->Name = L"lblDirector";
            this->lblDirector->Size = System::Drawing::Size(100, 20);
            this->lblDirector->TabIndex = 12;
            this->lblDirector->Text = L"Director:";
            // 
            // txtDirector
            // 
            this->txtDirector->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtDirector->ForeColor = System::Drawing::Color::White;
            this->txtDirector->Location = System::Drawing::Point(120, 252);
            this->txtDirector->Name = L"txtDirector";
            this->txtDirector->Size = System::Drawing::Size(275, 22);
            this->txtDirector->TabIndex = 13;
            // 
            // lblRating
            // 
            this->lblRating->ForeColor = System::Drawing::Color::Silver;
            this->lblRating->Location = System::Drawing::Point(15, 303);
            this->lblRating->Name = L"lblRating";
            this->lblRating->Size = System::Drawing::Size(50, 20);
            this->lblRating->TabIndex = 14;
            this->lblRating->Text = L"Rating:";
            // 
            // txtRating
            // 
            this->txtRating->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtRating->ForeColor = System::Drawing::Color::White;
            this->txtRating->Location = System::Drawing::Point(70, 300);
            this->txtRating->Name = L"txtRating";
            this->txtRating->Size = System::Drawing::Size(60, 22);
            this->txtRating->TabIndex = 15;
            // 
            // lblPoster
            // 
            this->lblPoster->ForeColor = System::Drawing::Color::Silver;
            this->lblPoster->Location = System::Drawing::Point(145, 303);
            this->lblPoster->Name = L"lblPoster";
            this->lblPoster->Size = System::Drawing::Size(55, 20);
            this->lblPoster->TabIndex = 16;
            this->lblPoster->Text = L"Poster:";
            // 
            // txtPoster
            // 
            this->txtPoster->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtPoster->ForeColor = System::Drawing::Color::White;
            this->txtPoster->Location = System::Drawing::Point(205, 300);
            this->txtPoster->Name = L"txtPoster";
            this->txtPoster->Size = System::Drawing::Size(190, 22);
            this->txtPoster->TabIndex = 17;
            // 
            // lblSynopsis
            // 
            this->lblSynopsis->ForeColor = System::Drawing::Color::Silver;
            this->lblSynopsis->Location = System::Drawing::Point(15, 351);
            this->lblSynopsis->Name = L"lblSynopsis";
            this->lblSynopsis->Size = System::Drawing::Size(100, 20);
            this->lblSynopsis->TabIndex = 18;
            this->lblSynopsis->Text = L"Synopsis:";
            // 
            // txtSynopsis
            // 
            this->txtSynopsis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->txtSynopsis->ForeColor = System::Drawing::Color::White;
            this->txtSynopsis->Location = System::Drawing::Point(120, 348);
            this->txtSynopsis->Multiline = true;
            this->txtSynopsis->Name = L"txtSynopsis";
            this->txtSynopsis->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->txtSynopsis->Size = System::Drawing::Size(275, 65);
            this->txtSynopsis->TabIndex = 19;
            // 
            // btnInsert
            // 
            this->btnInsert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
                static_cast<System::Int32>(static_cast<System::Byte>(96)));
            this->btnInsert->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnInsert->FlatAppearance->BorderSize = 0;
            this->btnInsert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnInsert->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnInsert->ForeColor = System::Drawing::Color::White;
            this->btnInsert->Location = System::Drawing::Point(15, 430);
            this->btnInsert->Name = L"btnInsert";
            this->btnInsert->Size = System::Drawing::Size(185, 38);
            this->btnInsert->TabIndex = 20;
            this->btnInsert->Text = L"Insert Content";
            this->btnInsert->UseVisualStyleBackColor = false;
            this->btnInsert->Click += gcnew System::EventHandler(this, &AdminCatalogForm::btnInsert_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(185)));
            this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnUpdate->FlatAppearance->BorderSize = 0;
            this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnUpdate->ForeColor = System::Drawing::Color::White;
            this->btnUpdate->Location = System::Drawing::Point(215, 430);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(180, 38);
            this->btnUpdate->TabIndex = 21;
            this->btnUpdate->Text = L"Update Content";
            this->btnUpdate->UseVisualStyleBackColor = false;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &AdminCatalogForm::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnDelete->FlatAppearance->BorderSize = 0;
            this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnDelete->ForeColor = System::Drawing::Color::White;
            this->btnDelete->Location = System::Drawing::Point(15, 476);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(185, 38);
            this->btnDelete->TabIndex = 22;
            this->btnDelete->Text = L"Delete Selected";
            this->btnDelete->UseVisualStyleBackColor = false;
            this->btnDelete->Click += gcnew System::EventHandler(this, &AdminCatalogForm::btnDelete_Click);
            // 
            // btnClear
            // 
            this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClear->FlatAppearance->BorderSize = 0;
            this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnClear->ForeColor = System::Drawing::Color::White;
            this->btnClear->Location = System::Drawing::Point(215, 476);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(180, 38);
            this->btnClear->TabIndex = 23;
            this->btnClear->Text = L"Clear Fields";
            this->btnClear->UseVisualStyleBackColor = false;
            this->btnClear->Click += gcnew System::EventHandler(this, &AdminCatalogForm::btnClear_Click);
            // 
            // lblStatus
            // 
            this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic));
            this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
                static_cast<System::Int32>(static_cast<System::Byte>(113)));
            this->lblStatus->Location = System::Drawing::Point(15, 518);
            this->lblStatus->Name = L"lblStatus";
            this->lblStatus->Size = System::Drawing::Size(380, 22);
            this->lblStatus->TabIndex = 24;
            this->lblStatus->Text = L"Ready.";
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
            this->btnClose->Location = System::Drawing::Point(1045, 15);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(38, 38);
            this->btnClose->TabIndex = 2;
            this->btnClose->Text = L"X";
            this->btnClose->UseVisualStyleBackColor = false;
            this->btnClose->Click += gcnew System::EventHandler(this, &AdminCatalogForm::btnClose_Click);
            // 
            // AdminCatalogForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
                static_cast<System::Int32>(static_cast<System::Byte>(18)));
            this->ClientSize = System::Drawing::Size(1100, 680);
            this->Controls->Add(this->pnlEditor);
            this->Controls->Add(this->dgvCatalog);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->lblSubHeader);
            this->Controls->Add(this->lblHeader);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"AdminCatalogForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"FASFLIX - Admin Catalog Management";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->EndInit();
            this->pnlEditor->ResumeLayout(false);
            this->pnlEditor->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        void SetupGridColumns();
        void LoadCatalogData();
        void FillFormFromRow(System::Windows::Forms::DataGridViewRow^ row);
        System::Void dgvCatalog_SelectionChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnInsert_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void lblHeader_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
