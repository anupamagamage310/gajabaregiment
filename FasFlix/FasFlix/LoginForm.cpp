#include "LoginForm.h"
#include "HomeForm.h"
#include "DBmanager.h"
#include "StringHelper.h"

namespace FasFlix {

    System::Void LoginForm::btnContinue_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ username = this->txtUsername->Text->Trim();
        String^ password = this->txtPassword->Text;

        if (username->Length == 0 || password->Length == 0)
        {
            Errorlbl1->Visible = true;
            Errorlbl2->Visible = true;
            return;
        }
        else if (username == L"admin" && password == L"admin") {
            Errorlbl1->Visible = false;
            Errorlbl2->Visible = false;
            HomeForm^ hf1 = gcnew HomeForm(L"admin", true);
            hf1->Show();
            this->Hide();
        }
        else {
            DBmanager db2;
            std::string username1 = StringHelper::ToStd(this->txtUsername->Text);
            std::string password1 = StringHelper::ToStd(this->txtPassword->Text);

            if (db2.authenticateUser(username1, password1)) {
                Errorlbl1->Visible = false;
                Errorlbl2->Visible = false;
                HomeForm^ hf1 = gcnew HomeForm(username, false);
                hf1->Show();
                this->Hide();
            }
            else {
                Errorlbl1->Visible = true;
                Errorlbl2->Visible = true;
                return;
            }
        }
    }

}

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew FasFlix::LoginForm());
    return 0;
}
