#include "MNL_SignIn.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MyNovelList::MNL_SignIn signInForm;
	Application::Run(% signInForm);
}