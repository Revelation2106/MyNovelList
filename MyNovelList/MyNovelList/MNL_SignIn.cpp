#include "MNL_SignIn.h"

//Allow use of C#-related code within C++
using namespace System;
using namespace System::Windows::Forms;

// Single thread only application
[STAThreadAttribute]

// Application entry point
void main(array<String^>^ args)
{
	// Set Windows Forms parameters
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	// Create and run a new sign-in Windows Form
	MyNovelList::MNL_SignIn signInForm;
	Application::Run(% signInForm);
}