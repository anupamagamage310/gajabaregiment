#pragma once

namespace FasFlix {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::IO;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();

			eyeOpen = DrawEyeIcon(false);    // shown when password is visible
			eyeClosed = DrawEyeIcon(true);   // shown when password is hidden (*)
			passwordVisible = false;

			// Start hidden: characters appear as *
			this->txtPassword->PasswordChar = L'*';
			this->picEye->Image = eyeClosed;
		}

	protected:
		~LoginForm()
		{
			if (eyeOpen != nullptr) delete eyeOpen;
			if (eyeClosed != nullptr) delete eyeClosed;
			if (components)
			{
				delete components;
			}
		}

	private:
		// ---- state ----
		System::Drawing::Bitmap^ eyeOpen;
		System::Drawing::Bitmap^ eyeClosed;
		bool passwordVisible;

		// ---- controls ----
		System::Windows::Forms::PictureBox^ picPoster1;
		System::Windows::Forms::PictureBox^ picPoster2;
		System::Windows::Forms::PictureBox^ picPoster3;
		System::Windows::Forms::PictureBox^ picPoster4;
		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::Panel^ pnlUsername;
		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::Panel^ pnlPassword;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::PictureBox^ picEye;
		System::Windows::Forms::Button^ btnContinue;
		System::Windows::Forms::Label^ lblCaptcha;
	private: System::Windows::Forms::Label^ Errorlbl1;
	private: System::Windows::Forms::Label^ Errorlbl2;
	private: System::Windows::Forms::Button^ btnexit;




		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->picPoster1 = (gcnew System::Windows::Forms::PictureBox());
			this->picPoster2 = (gcnew System::Windows::Forms::PictureBox());
			this->picPoster3 = (gcnew System::Windows::Forms::PictureBox());
			this->picPoster4 = (gcnew System::Windows::Forms::PictureBox());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->pnlUsername = (gcnew System::Windows::Forms::Panel());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->pnlPassword = (gcnew System::Windows::Forms::Panel());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->picEye = (gcnew System::Windows::Forms::PictureBox());
			this->btnContinue = (gcnew System::Windows::Forms::Button());
			this->lblCaptcha = (gcnew System::Windows::Forms::Label());
			this->Errorlbl1 = (gcnew System::Windows::Forms::Label());
			this->Errorlbl2 = (gcnew System::Windows::Forms::Label());
			this->btnexit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster4))->BeginInit();
			this->pnlUsername->SuspendLayout();
			this->pnlPassword->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEye))->BeginInit();
			this->SuspendLayout();
			// 
			// picPoster1
			// 
			this->picPoster1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->picPoster1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPoster1.Image")));
			this->picPoster1->Location = System::Drawing::Point(43, 37);
			this->picPoster1->Name = L"picPoster1";
			this->picPoster1->Size = System::Drawing::Size(105, 644);
			this->picPoster1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPoster1->TabIndex = 12;
			this->picPoster1->TabStop = false;
			this->picPoster1->Click += gcnew System::EventHandler(this, &LoginForm::picPoster1_Click);
			// 
			// picPoster2
			// 
			this->picPoster2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->picPoster2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPoster2.Image")));
			this->picPoster2->Location = System::Drawing::Point(165, 103);
			this->picPoster2->Name = L"picPoster2";
			this->picPoster2->Size = System::Drawing::Size(105, 578);
			this->picPoster2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPoster2->TabIndex = 11;
			this->picPoster2->TabStop = false;
			// 
			// picPoster3
			// 
			this->picPoster3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->picPoster3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPoster3.Image")));
			this->picPoster3->Location = System::Drawing::Point(285, 37);
			this->picPoster3->Name = L"picPoster3";
			this->picPoster3->Size = System::Drawing::Size(105, 644);
			this->picPoster3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPoster3->TabIndex = 10;
			this->picPoster3->TabStop = false;
			// 
			// picPoster4
			// 
			this->picPoster4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->picPoster4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPoster4.Image")));
			this->picPoster4->Location = System::Drawing::Point(406, 105);
			this->picPoster4->Name = L"picPoster4";
			this->picPoster4->Size = System::Drawing::Size(105, 578);
			this->picPoster4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPoster4->TabIndex = 9;
			this->picPoster4->TabStop = false;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->BackColor = System::Drawing::Color::Transparent;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Impact", 44));
			this->lblBrand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblBrand->Location = System::Drawing::Point(128, 516);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(255, 91);
			this->lblBrand->TabIndex = 8;
			this->lblBrand->Text = L"FASFLIX";
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 26));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(680, 128);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(140, 60);
			this->lblTitle->TabIndex = 7;
			this->lblTitle->Text = L"Log in";
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->lblUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->lblUsername->Location = System::Drawing::Point(686, 198);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(121, 32);
			this->lblUsername->TabIndex = 6;
			this->lblUsername->Text = L"Username";
			// 
			// pnlUsername
			// 
			this->pnlUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->pnlUsername->Controls->Add(this->txtUsername);
			this->pnlUsername->Location = System::Drawing::Point(686, 244);
			this->pnlUsername->Name = L"pnlUsername";
			this->pnlUsername->Size = System::Drawing::Size(558, 60);
			this->pnlUsername->TabIndex = 1;
			this->pnlUsername->Click += gcnew System::EventHandler(this, &LoginForm::pnlUsername_Click);
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->txtUsername->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->txtUsername->ForeColor = System::Drawing::Color::White;
			this->txtUsername->Location = System::Drawing::Point(16, 15);
			this->txtUsername->MaxLength = 20;
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(526, 32);
			this->txtUsername->TabIndex = 0;
			this->txtUsername->TextChanged += gcnew System::EventHandler(this, &LoginForm::txtUsername_TextChanged);
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->lblPassword->Location = System::Drawing::Point(686, 316);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(111, 32);
			this->lblPassword->TabIndex = 4;
			this->lblPassword->Text = L"Password";
			// 
			// pnlPassword
			// 
			this->pnlPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->pnlPassword->Controls->Add(this->txtPassword);
			this->pnlPassword->Controls->Add(this->picEye);
			this->pnlPassword->Location = System::Drawing::Point(686, 361);
			this->pnlPassword->Name = L"pnlPassword";
			this->pnlPassword->Size = System::Drawing::Size(558, 60);
			this->pnlPassword->TabIndex = 2;
			this->pnlPassword->Click += gcnew System::EventHandler(this, &LoginForm::pnlPassword_Click);
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->txtPassword->ForeColor = System::Drawing::Color::White;
			this->txtPassword->Location = System::Drawing::Point(16, 15);
			this->txtPassword->MaxLength = 12;
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(469, 32);
			this->txtPassword->TabIndex = 0;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &LoginForm::txtPassword_TextChanged);
			// 
			// picEye
			// 
			this->picEye->BackColor = System::Drawing::Color::Transparent;
			this->picEye->Cursor = System::Windows::Forms::Cursors::Hand;
			this->picEye->Location = System::Drawing::Point(501, 15);
			this->picEye->Name = L"picEye";
			this->picEye->Size = System::Drawing::Size(41, 34);
			this->picEye->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picEye->TabIndex = 2;
			this->picEye->TabStop = false;
			this->picEye->Click += gcnew System::EventHandler(this, &LoginForm::picEye_Click);
			// 
			// btnContinue
			// 
			this->btnContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->btnContinue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnContinue->FlatAppearance->BorderSize = 0;
			this->btnContinue->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->btnContinue->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnContinue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold));
			this->btnContinue->ForeColor = System::Drawing::Color::White;
			this->btnContinue->Location = System::Drawing::Point(847, 516);
			this->btnContinue->Name = L"btnContinue";
			this->btnContinue->Size = System::Drawing::Size(255, 60);
			this->btnContinue->TabIndex = 3;
			this->btnContinue->Text = L"CONTINUE";
			this->btnContinue->UseVisualStyleBackColor = false;
			this->btnContinue->Click += gcnew System::EventHandler(this, &LoginForm::btnContinue_Click);
			// 
			// lblCaptcha
			// 
			this->lblCaptcha->AutoSize = true;
			this->lblCaptcha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblCaptcha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->lblCaptcha->Location = System::Drawing::Point(690, 597);
			this->lblCaptcha->Name = L"lblCaptcha";
			this->lblCaptcha->Size = System::Drawing::Size(570, 23);
			this->lblCaptcha->TabIndex = 0;
			this->lblCaptcha->Text = L"This page is protected by Pandula reCAPTCHA to ensure you\'re not a bot.";
			// 
			// Errorlbl1
			// 
			this->Errorlbl1->AutoSize = true;
			this->Errorlbl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->Errorlbl1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Errorlbl1->Location = System::Drawing::Point(890, 198);
			this->Errorlbl1->Name = L"Errorlbl1";
			this->Errorlbl1->Size = System::Drawing::Size(354, 32);
			this->Errorlbl1->TabIndex = 13;
			this->Errorlbl1->Text = L"*Wrong User Name or Password";
			this->Errorlbl1->Visible = false;
			this->Errorlbl1->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click);
			// 
			// Errorlbl2
			// 
			this->Errorlbl2->AutoSize = true;
			this->Errorlbl2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->Errorlbl2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Errorlbl2->Location = System::Drawing::Point(890, 316);
			this->Errorlbl2->Name = L"Errorlbl2";
			this->Errorlbl2->Size = System::Drawing::Size(354, 32);
			this->Errorlbl2->TabIndex = 14;
			this->Errorlbl2->Text = L"*Wrong User Name or Password";
			this->Errorlbl2->Visible = false;
			// 
			// btnexit
			// 
			this->btnexit->BackColor = System::Drawing::SystemColors::GrayText;
			this->btnexit->FlatAppearance->BorderSize = 0;
			this->btnexit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnexit->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnexit->Location = System::Drawing::Point(1280, 37);
			this->btnexit->Name = L"btnexit";
			this->btnexit->Size = System::Drawing::Size(42, 30);
			this->btnexit->TabIndex = 15;
			this->btnexit->Text = L"x";
			this->btnexit->UseVisualStyleBackColor = false;
			this->btnexit->Click += gcnew System::EventHandler(this, &LoginForm::btnexit_Click);
			this->btnexit->MouseCaptureChanged += gcnew System::EventHandler(this, &LoginForm::btnexit_MouseCaptureChanged);
			this->btnexit->MouseEnter += gcnew System::EventHandler(this, &LoginForm::btnexit_MouseEnter);
			this->btnexit->MouseLeave += gcnew System::EventHandler(this, &LoginForm::btnexit_MouseLeave);
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnContinue;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->ClientSize = System::Drawing::Size(1371, 720);
			this->Controls->Add(this->btnexit);
			this->Controls->Add(this->Errorlbl2);
			this->Controls->Add(this->Errorlbl1);
			this->Controls->Add(this->lblCaptcha);
			this->Controls->Add(this->btnContinue);
			this->Controls->Add(this->pnlPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->pnlUsername);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblBrand);
			this->Controls->Add(this->picPoster4);
			this->Controls->Add(this->picPoster3);
			this->Controls->Add(this->picPoster2);
			this->Controls->Add(this->picPoster1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FASFLIX - Log in";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPoster4))->EndInit();
			this->pnlUsername->ResumeLayout(false);
			this->pnlUsername->PerformLayout();
			this->pnlPassword->ResumeLayout(false);
			this->pnlPassword->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEye))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// ---- Eye icon toggle ----
		System::Void picEye_Click(System::Object^ sender, System::EventArgs^ e)
		{
			passwordVisible = !passwordVisible;

			// L'\0' = no masking (plain text), L'*' = masked
			this->txtPassword->PasswordChar = passwordVisible ? L'\0' : L'*';
			this->picEye->Image = passwordVisible ? eyeOpen : eyeClosed;

			this->txtPassword->Focus();
			this->txtPassword->SelectionStart = this->txtPassword->TextLength;
		}

		// ---- Clicking the dark box focuses the textbox ----
		System::Void pnlUsername_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->txtUsername->Focus();
		}

		System::Void pnlPassword_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->txtPassword->Focus();
		}

		// ---- Continue ----
		System::Void btnContinue_Click(System::Object^ sender, System::EventArgs^ e);

		// ---- Draws the blue eye / slashed-eye icon with GDI+ (no image files needed) ----
		static Bitmap^ DrawEyeIcon(bool slashed)
		{
			Bitmap^ bmp = gcnew Bitmap(32, 32);
			Graphics^ g = Graphics::FromImage(bmp);
			g->SmoothingMode = SmoothingMode::AntiAlias;
			g->Clear(Color::Transparent);

			Color blue = Color::FromArgb(37, 99, 235);
			Pen^ pen = gcnew Pen(blue, 2.4F);
			pen->StartCap = LineCap::Round;
			pen->EndCap = LineCap::Round;
			SolidBrush^ brush = gcnew SolidBrush(blue);

			// eye outline (two curves meeting at the corners)
			g->DrawBezier(pen, 3.0F, 16.0F, 9.0F, 6.0F, 23.0F, 6.0F, 29.0F, 16.0F);
			g->DrawBezier(pen, 3.0F, 16.0F, 9.0F, 26.0F, 23.0F, 26.0F, 29.0F, 16.0F);

			// pupil
			g->FillEllipse(brush, 11.5F, 11.5F, 9.0F, 9.0F);

			if (slashed)
			{
				// dark gap behind the slash so it reads clearly on the dark box
				Pen^ gap = gcnew Pen(Color::FromArgb(30, 30, 30), 5.0F);
				gap->StartCap = LineCap::Round;
				gap->EndCap = LineCap::Round;
				g->DrawLine(gap, 6.0F, 27.0F, 26.0F, 5.0F);
				g->DrawLine(pen, 6.0F, 27.0F, 26.0F, 5.0F);
				delete gap;
			}

			delete brush;
			delete pen;
			delete g;
			return bmp;
		}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void txtPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtUsername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnexit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void btnexit_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnexit_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	this ->btnexit->BackColor = System::Drawing::Color::Red;
}
private: System::Void btnexit_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->btnexit->BackColor = System::Drawing::SystemColors::GrayText;

}
private: System::Void picPoster1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
