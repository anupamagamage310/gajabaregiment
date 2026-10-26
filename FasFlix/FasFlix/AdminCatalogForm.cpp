#include "AdminCatalogForm.h"
#include "DBmanager.h"
#include "StringHelper.h"

namespace FasFlix {

    AdminCatalogForm::AdminCatalogForm(void)
    {
        InitializeComponent();
        SetupGridColumns();
        LoadCatalogData();
    }

    AdminCatalogForm::~AdminCatalogForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void AdminCatalogForm::SetupGridColumns()
    {
        this->dgvCatalog->Columns->Clear();
        this->dgvCatalog->Columns->Add(L"colId", L"ID");
        this->dgvCatalog->Columns[0]->Width = 45;
        this->dgvCatalog->Columns->Add(L"colTitle", L"Title");
        this->dgvCatalog->Columns[1]->Width = 170;
        this->dgvCatalog->Columns->Add(L"colType", L"Type");
        this->dgvCatalog->Columns[2]->Width = 85;
        this->dgvCatalog->Columns->Add(L"colYear", L"Year");
        this->dgvCatalog->Columns[3]->Width = 55;
        this->dgvCatalog->Columns->Add(L"colDuration", L"Duration/Seasons");
        this->dgvCatalog->Columns[4]->Width = 115;
        this->dgvCatalog->Columns->Add(L"colRating", L"Rating");
        this->dgvCatalog->Columns[5]->Width = 65;
        this->dgvCatalog->Columns->Add(L"colGenre", L"Genre");
        this->dgvCatalog->Columns[6]->Width = 85;
    }

    void AdminCatalogForm::LoadCatalogData()
    {
        this->dgvCatalog->Rows->Clear();
        DBmanager db;
        std::vector<std::shared_ptr<MediaItem>> items = db.getAllContent();

        for (const auto& item : items) {
            int rowIndex = this->dgvCatalog->Rows->Add();
            DataGridViewRow^ row = this->dgvCatalog->Rows[rowIndex];
            row->Cells[0]->Value = item->getId().ToString();
            row->Cells[1]->Value = StringHelper::ToManaged(item->getTitle());
            row->Cells[2]->Value = StringHelper::ToManaged(item->getContentType());
            row->Cells[3]->Value = item->getReleaseYear().ToString();
            row->Cells[4]->Value = StringHelper::ToManaged(item->getDurationDisplay());
            row->Cells[5]->Value = String::Format(L"{0:F1}", item->getImdbRating());
            row->Cells[6]->Value = StringHelper::ToManaged(item->getGenre());
        }

        if (this->dgvCatalog->Rows->Count > 0) {
            this->dgvCatalog->Rows[0]->Selected = true;
            FillFormFromRow(this->dgvCatalog->Rows[0]);
        }
    }

    void AdminCatalogForm::FillFormFromRow(DataGridViewRow^ row)
    {
        if (row == nullptr) return;
        try {
            int id = Int32::Parse(row->Cells[0]->Value->ToString());
            DBmanager db;
            std::shared_ptr<MediaItem> item = db.getContentById(id);
            if (item) {
                this->txtId->Text = item->getId().ToString();
                this->txtTitle->Text = StringHelper::ToManaged(item->getTitle());
                this->cmbType->SelectedItem = StringHelper::ToManaged(item->getContentType());
                this->txtYear->Text = item->getReleaseYear().ToString();
                this->txtDuration->Text = StringHelper::ToManaged(item->getDurationDisplay());
                this->txtGenre->Text = StringHelper::ToManaged(item->getGenre());
                this->txtDirector->Text = StringHelper::ToManaged(item->getDirector());
                this->txtRating->Text = String::Format(L"{0:F1}", item->getImdbRating());
                this->txtPoster->Text = StringHelper::ToManaged(item->getPosterPath());
                this->txtSynopsis->Text = StringHelper::ToManaged(item->getSynopsis());
            }
        }
        catch (...) {}
    }

    System::Void AdminCatalogForm::dgvCatalog_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->dgvCatalog->SelectedRows->Count > 0) {
            FillFormFromRow(this->dgvCatalog->SelectedRows[0]);
        }
    }

    System::Void AdminCatalogForm::btnClose_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    System::Void AdminCatalogForm::btnClear_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->txtId->Text = L"";
        this->txtTitle->Text = L"";
        this->cmbType->SelectedIndex = 0;
        this->txtYear->Text = L"";
        this->txtDuration->Text = L"";
        this->txtGenre->Text = L"";
        this->txtDirector->Text = L"";
        this->txtRating->Text = L"";
        this->txtPoster->Text = L"";
        this->txtSynopsis->Text = L"";
        this->lblStatus->Text = L"Fields cleared for new entry.";
        this->lblStatus->ForeColor = System::Drawing::Color::LightGray;
    }

    System::Void AdminCatalogForm::btnInsert_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(this->txtTitle->Text)) {
            MessageBox::Show(L"Please enter a valid title.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        try {
            DBmanager db;
            std::string title = StringHelper::ToStd(this->txtTitle->Text->Trim());
            std::string type = StringHelper::ToStd(this->cmbType->SelectedItem->ToString());
            int year = Int32::Parse(this->txtYear->Text->Trim());
            std::string duration = StringHelper::ToStd(this->txtDuration->Text->Trim());
            std::string genre = StringHelper::ToStd(this->txtGenre->Text->Trim());
            std::string director = StringHelper::ToStd(this->txtDirector->Text->Trim());
            std::string synopsis = StringHelper::ToStd(this->txtSynopsis->Text->Trim());
            float rating = Single::Parse(this->txtRating->Text->Trim());
            std::string poster = StringHelper::ToStd(this->txtPoster->Text->Trim());

            if (db.insertContent(title, type, year, duration, genre, director, synopsis, rating, poster)) {
                this->lblStatus->Text = L"Content successfully added to catalog!";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113);
                LoadCatalogData();
            }
            else {
                this->lblStatus->Text = L"Error: Failed to insert content.";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(L"Input error: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void AdminCatalogForm::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(this->txtId->Text)) {
            MessageBox::Show(L"Please select a record from the table to update.", L"Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        try {
            int id = Int32::Parse(this->txtId->Text);
            DBmanager db;
            std::string title = StringHelper::ToStd(this->txtTitle->Text->Trim());
            std::string type = StringHelper::ToStd(this->cmbType->SelectedItem->ToString());
            int year = Int32::Parse(this->txtYear->Text->Trim());
            std::string duration = StringHelper::ToStd(this->txtDuration->Text->Trim());
            std::string genre = StringHelper::ToStd(this->txtGenre->Text->Trim());
            std::string director = StringHelper::ToStd(this->txtDirector->Text->Trim());
            std::string synopsis = StringHelper::ToStd(this->txtSynopsis->Text->Trim());
            float rating = Single::Parse(this->txtRating->Text->Trim());
            std::string poster = StringHelper::ToStd(this->txtPoster->Text->Trim());

            if (db.updateContent(id, title, type, year, duration, genre, director, synopsis, rating, poster)) {
                this->lblStatus->Text = L"Content ID " + id + L" successfully updated!";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113);
                LoadCatalogData();
            }
            else {
                this->lblStatus->Text = L"Error: Update failed.";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(L"Input error: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void AdminCatalogForm::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(this->txtId->Text)) {
            MessageBox::Show(L"Please select a record from the table to delete.", L"Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        int id = Int32::Parse(this->txtId->Text);
        System::Windows::Forms::DialogResult res = MessageBox::Show(
            L"Are you sure you want to permanently delete '" + this->txtTitle->Text + L"' from the catalog?",
            L"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (res == System::Windows::Forms::DialogResult::Yes) {
            DBmanager db;
            if (db.deleteContent(id)) {
                this->lblStatus->Text = L"Content ID " + id + L" deleted.";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
                LoadCatalogData();
                btnClear_Click(sender, e);
            }
            else {
                this->lblStatus->Text = L"Error: Could not delete content.";
                this->lblStatus->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60);
            }
        }
    }

}
