#pragma once

#include "MNL_Home.h"

#include <fstream>
#include <string>

namespace MyNovelList {

	// Allow use of C#-related code within C++
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Global username and password vector lists
	std::vector<std::string> usernameVector;
	std::vector<std::string> passwordVector;

	// Global string to store the username of the successfully logged in user
	std::string successfulUsername = "";

	/// <summary>
	/// Opens a sign-in window. 
	/// </summary>
	public ref class MNL_SignIn : public System::Windows::Forms::Form
	{
	protected:
		// Bool to track whether a login attempt was successful
		bool loginSuccessful;

	// Windows Forms generated declarations
	private: System::Windows::Forms::Label^ copyLabel;
	private: System::Windows::Forms::Label^ mnlLabel;
	private: System::Windows::Forms::Label^ incorrectDetailsLabel;
	private: System::Windows::Forms::Label^ createAccountLabel;
	private: System::Windows::Forms::Label^ accountLabel;
	private: System::Windows::Forms::Panel^ registerPanel;
	private: System::Windows::Forms::TextBox^ registerPassTextBox;
	private: System::Windows::Forms::Label^ registerPassLabel;
	private: System::Windows::Forms::TextBox^ registerUserTextBox;
	private: System::Windows::Forms::Label^ registerUserLabel;
	private: System::Windows::Forms::Button^ registerButton;
	private: System::Windows::Forms::Panel^ uaPanel;
	private: System::Windows::Forms::TextBox^ uaTextBox;
	private: System::Windows::Forms::Button^ uaButton;
	private: System::Windows::Forms::Label^ uaLabelHeading;
	private: System::Windows::Forms::Label^ registerNoTextLabel;
	private: System::Windows::Forms::Label^ registerLabel;

	public:
		// Default constructor.
		MNL_SignIn(void)
		{
			// Initialiser for Windows Forms components
			InitializeComponent();

			// Hides the user agreement panel
			uaPanel->Hide();
			// Hides the registration panel
			registerPanel->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any Windows Forms resources being used.
		/// </summary>
		~MNL_SignIn()
		{
			// If components exist, delete them
			if (components)
			{
				delete components;
			}
		}

	// Windows Forms generated declarations
	private: System::Windows::Forms::Label^ signInLabel;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::TextBox^ usernameTextBox;
	private: System::Windows::Forms::TextBox^ passwordTextBox;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Button^ signInButton;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::CheckBox^ uaCheckBox;
	private: System::Windows::Forms::Label^ uaLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MNL_SignIn::typeid));
			this->signInLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->signInButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->uaCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->uaLabel = (gcnew System::Windows::Forms::Label());
			this->copyLabel = (gcnew System::Windows::Forms::Label());
			this->mnlLabel = (gcnew System::Windows::Forms::Label());
			this->incorrectDetailsLabel = (gcnew System::Windows::Forms::Label());
			this->createAccountLabel = (gcnew System::Windows::Forms::Label());
			this->accountLabel = (gcnew System::Windows::Forms::Label());
			this->registerPanel = (gcnew System::Windows::Forms::Panel());
			this->registerPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->registerPassLabel = (gcnew System::Windows::Forms::Label());
			this->registerUserTextBox = (gcnew System::Windows::Forms::TextBox());
			this->registerUserLabel = (gcnew System::Windows::Forms::Label());
			this->registerButton = (gcnew System::Windows::Forms::Button());
			this->registerLabel = (gcnew System::Windows::Forms::Label());
			this->uaPanel = (gcnew System::Windows::Forms::Panel());
			this->uaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->uaButton = (gcnew System::Windows::Forms::Button());
			this->uaLabelHeading = (gcnew System::Windows::Forms::Label());
			this->registerNoTextLabel = (gcnew System::Windows::Forms::Label());
			this->registerPanel->SuspendLayout();
			this->uaPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// signInLabel
			// 
			this->signInLabel->AutoSize = true;
			this->signInLabel->BackColor = System::Drawing::Color::Transparent;
			this->signInLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signInLabel->ForeColor = System::Drawing::Color::White;
			this->signInLabel->Location = System::Drawing::Point(188, 186);
			this->signInLabel->Name = L"signInLabel";
			this->signInLabel->Size = System::Drawing::Size(271, 85);
			this->signInLabel->TabIndex = 0;
			this->signInLabel->Text = L"Sign In";
			this->signInLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::Color::Transparent;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::Color::White;
			this->usernameLabel->Location = System::Drawing::Point(194, 343);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(233, 51);
			this->usernameLabel->TabIndex = 1;
			this->usernameLabel->Text = L"Username:";
			this->usernameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->BackColor = System::Drawing::Color::Wheat;
			this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameTextBox->Location = System::Drawing::Point(203, 419);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(500, 44);
			this->usernameTextBox->TabIndex = 3;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->BackColor = System::Drawing::Color::Wheat;
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->Location = System::Drawing::Point(203, 580);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(500, 44);
			this->passwordTextBox->TabIndex = 5;
			this->passwordTextBox->UseSystemPasswordChar = true;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->BackColor = System::Drawing::Color::Transparent;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->ForeColor = System::Drawing::Color::White;
			this->passwordLabel->Location = System::Drawing::Point(194, 504);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(224, 51);
			this->passwordLabel->TabIndex = 4;
			this->passwordLabel->Text = L"Password:";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// signInButton
			// 
			this->signInButton->BackColor = System::Drawing::Color::Wheat;
			this->signInButton->Enabled = false;
			this->signInButton->FlatAppearance->BorderSize = 0;
			this->signInButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signInButton->Location = System::Drawing::Point(203, 756);
			this->signInButton->Name = L"signInButton";
			this->signInButton->Size = System::Drawing::Size(230, 90);
			this->signInButton->TabIndex = 6;
			this->signInButton->Text = L"Sign In";
			this->signInButton->UseVisualStyleBackColor = false;
			this->signInButton->Click += gcnew System::EventHandler(this, &MNL_SignIn::signInButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::Color::Transparent;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->ForeColor = System::Drawing::Color::Wheat;
			this->exitButton->Location = System::Drawing::Point(473, 756);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(230, 90);
			this->exitButton->TabIndex = 7;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &MNL_SignIn::exitButton_Click);
			// 
			// uaCheckBox
			// 
			this->uaCheckBox->AutoSize = true;
			this->uaCheckBox->BackColor = System::Drawing::Color::Transparent;
			this->uaCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->uaCheckBox->ForeColor = System::Drawing::Color::White;
			this->uaCheckBox->Location = System::Drawing::Point(203, 672);
			this->uaCheckBox->Name = L"uaCheckBox";
			this->uaCheckBox->Size = System::Drawing::Size(212, 35);
			this->uaCheckBox->TabIndex = 8;
			this->uaCheckBox->Text = L"I agree to the ";
			this->uaCheckBox->UseVisualStyleBackColor = false;
			this->uaCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MNL_SignIn::uaCheckBox_CheckedChanged);
			// 
			// uaLabel
			// 
			this->uaLabel->AutoSize = true;
			this->uaLabel->BackColor = System::Drawing::Color::Transparent;
			this->uaLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->uaLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->uaLabel->ForeColor = System::Drawing::Color::Wheat;
			this->uaLabel->Location = System::Drawing::Point(412, 673);
			this->uaLabel->Name = L"uaLabel";
			this->uaLabel->Size = System::Drawing::Size(211, 31);
			this->uaLabel->TabIndex = 9;
			this->uaLabel->Text = L"User Agreement";
			this->uaLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->uaLabel->Click += gcnew System::EventHandler(this, &MNL_SignIn::uaLabel_Click);
			// 
			// copyLabel
			// 
			this->copyLabel->AutoSize = true;
			this->copyLabel->BackColor = System::Drawing::Color::Transparent;
			this->copyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->copyLabel->ForeColor = System::Drawing::Color::White;
			this->copyLabel->Location = System::Drawing::Point(200, 1014);
			this->copyLabel->Name = L"copyLabel";
			this->copyLabel->Size = System::Drawing::Size(503, 25);
			this->copyLabel->TabIndex = 12;
			this->copyLabel->Text = L"Copyright © 2021 Thomas Cole. All rights reserved.";
			this->copyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mnlLabel
			// 
			this->mnlLabel->AutoSize = true;
			this->mnlLabel->BackColor = System::Drawing::Color::Transparent;
			this->mnlLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mnlLabel->ForeColor = System::Drawing::Color::White;
			this->mnlLabel->Location = System::Drawing::Point(188, 46);
			this->mnlLabel->Name = L"mnlLabel";
			this->mnlLabel->Size = System::Drawing::Size(448, 85);
			this->mnlLabel->TabIndex = 13;
			this->mnlLabel->Text = L"MyNovelList";
			this->mnlLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// incorrectDetailsLabel
			// 
			this->incorrectDetailsLabel->AutoSize = true;
			this->incorrectDetailsLabel->BackColor = System::Drawing::Color::Transparent;
			this->incorrectDetailsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->incorrectDetailsLabel->ForeColor = System::Drawing::Color::Red;
			this->incorrectDetailsLabel->Location = System::Drawing::Point(197, 859);
			this->incorrectDetailsLabel->Name = L"incorrectDetailsLabel";
			this->incorrectDetailsLabel->Size = System::Drawing::Size(444, 31);
			this->incorrectDetailsLabel->TabIndex = 14;
			this->incorrectDetailsLabel->Text = L"Username or Password is incorrect!";
			this->incorrectDetailsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->incorrectDetailsLabel->Visible = false;
			// 
			// createAccountLabel
			// 
			this->createAccountLabel->AutoSize = true;
			this->createAccountLabel->BackColor = System::Drawing::Color::Transparent;
			this->createAccountLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->createAccountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Underline,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->createAccountLabel->ForeColor = System::Drawing::Color::Wheat;
			this->createAccountLabel->Location = System::Drawing::Point(510, 927);
			this->createAccountLabel->Name = L"createAccountLabel";
			this->createAccountLabel->Size = System::Drawing::Size(96, 31);
			this->createAccountLabel->TabIndex = 15;
			this->createAccountLabel->Text = L"Create";
			this->createAccountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->createAccountLabel->Click += gcnew System::EventHandler(this, &MNL_SignIn::createAccountLabel_Click);
			// 
			// accountLabel
			// 
			this->accountLabel->AutoSize = true;
			this->accountLabel->BackColor = System::Drawing::Color::Transparent;
			this->accountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountLabel->ForeColor = System::Drawing::Color::White;
			this->accountLabel->Location = System::Drawing::Point(197, 927);
			this->accountLabel->Name = L"accountLabel";
			this->accountLabel->Size = System::Drawing::Size(298, 31);
			this->accountLabel->TabIndex = 16;
			this->accountLabel->Text = L"Don\'t have an account\?";
			this->accountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registerPanel
			// 
			this->registerPanel->BackColor = System::Drawing::SystemColors::Control;
			this->registerPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"registerPanel.BackgroundImage")));
			this->registerPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->registerPanel->Controls->Add(this->registerNoTextLabel);
			this->registerPanel->Controls->Add(this->registerPassTextBox);
			this->registerPanel->Controls->Add(this->registerPassLabel);
			this->registerPanel->Controls->Add(this->registerUserTextBox);
			this->registerPanel->Controls->Add(this->registerUserLabel);
			this->registerPanel->Controls->Add(this->registerButton);
			this->registerPanel->Controls->Add(this->registerLabel);
			this->registerPanel->Location = System::Drawing::Point(0, 0);
			this->registerPanel->Name = L"registerPanel";
			this->registerPanel->Size = System::Drawing::Size(1920, 1080);
			this->registerPanel->TabIndex = 17;
			// 
			// registerPassTextBox
			// 
			this->registerPassTextBox->BackColor = System::Drawing::Color::Wheat;
			this->registerPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerPassTextBox->Location = System::Drawing::Point(205, 613);
			this->registerPassTextBox->Name = L"registerPassTextBox";
			this->registerPassTextBox->Size = System::Drawing::Size(500, 44);
			this->registerPassTextBox->TabIndex = 12;
			this->registerPassTextBox->UseSystemPasswordChar = true;
			// 
			// registerPassLabel
			// 
			this->registerPassLabel->AutoSize = true;
			this->registerPassLabel->BackColor = System::Drawing::Color::Transparent;
			this->registerPassLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerPassLabel->ForeColor = System::Drawing::Color::White;
			this->registerPassLabel->Location = System::Drawing::Point(196, 537);
			this->registerPassLabel->Name = L"registerPassLabel";
			this->registerPassLabel->Size = System::Drawing::Size(224, 51);
			this->registerPassLabel->TabIndex = 11;
			this->registerPassLabel->Text = L"Password:";
			this->registerPassLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registerUserTextBox
			// 
			this->registerUserTextBox->BackColor = System::Drawing::Color::Wheat;
			this->registerUserTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerUserTextBox->Location = System::Drawing::Point(205, 452);
			this->registerUserTextBox->Name = L"registerUserTextBox";
			this->registerUserTextBox->Size = System::Drawing::Size(500, 44);
			this->registerUserTextBox->TabIndex = 10;
			// 
			// registerUserLabel
			// 
			this->registerUserLabel->AutoSize = true;
			this->registerUserLabel->BackColor = System::Drawing::Color::Transparent;
			this->registerUserLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerUserLabel->ForeColor = System::Drawing::Color::White;
			this->registerUserLabel->Location = System::Drawing::Point(196, 376);
			this->registerUserLabel->Name = L"registerUserLabel";
			this->registerUserLabel->Size = System::Drawing::Size(233, 51);
			this->registerUserLabel->TabIndex = 9;
			this->registerUserLabel->Text = L"Username:";
			this->registerUserLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registerButton
			// 
			this->registerButton->BackColor = System::Drawing::Color::Wheat;
			this->registerButton->FlatAppearance->BorderSize = 0;
			this->registerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registerButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerButton->Location = System::Drawing::Point(205, 762);
			this->registerButton->Name = L"registerButton";
			this->registerButton->Size = System::Drawing::Size(230, 90);
			this->registerButton->TabIndex = 8;
			this->registerButton->Text = L"Create";
			this->registerButton->UseVisualStyleBackColor = false;
			this->registerButton->Click += gcnew System::EventHandler(this, &MNL_SignIn::registerButton_Click);
			// 
			// registerLabel
			// 
			this->registerLabel->AutoSize = true;
			this->registerLabel->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerLabel->ForeColor = System::Drawing::Color::White;
			this->registerLabel->Location = System::Drawing::Point(190, 241);
			this->registerLabel->Name = L"registerLabel";
			this->registerLabel->Size = System::Drawing::Size(440, 85);
			this->registerLabel->TabIndex = 7;
			this->registerLabel->Text = L"Registration";
			this->registerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// uaPanel
			// 
			this->uaPanel->BackColor = System::Drawing::SystemColors::Control;
			this->uaPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"uaPanel.BackgroundImage")));
			this->uaPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->uaPanel->Controls->Add(this->uaTextBox);
			this->uaPanel->Controls->Add(this->uaButton);
			this->uaPanel->Controls->Add(this->uaLabelHeading);
			this->uaPanel->Location = System::Drawing::Point(0, 0);
			this->uaPanel->Name = L"uaPanel";
			this->uaPanel->Size = System::Drawing::Size(1920, 1080);
			this->uaPanel->TabIndex = 18;
			// 
			// uaTextBox
			// 
			this->uaTextBox->BackColor = System::Drawing::Color::Wheat;
			this->uaTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->uaTextBox->Location = System::Drawing::Point(205, 398);
			this->uaTextBox->Multiline = true;
			this->uaTextBox->Name = L"uaTextBox";
			this->uaTextBox->ReadOnly = true;
			this->uaTextBox->Size = System::Drawing::Size(569, 335);
			this->uaTextBox->TabIndex = 9;
			this->uaTextBox->Text = resources->GetString(L"uaTextBox.Text");
			// 
			// uaButton
			// 
			this->uaButton->BackColor = System::Drawing::Color::Wheat;
			this->uaButton->FlatAppearance->BorderSize = 0;
			this->uaButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->uaButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->uaButton->Location = System::Drawing::Point(205, 811);
			this->uaButton->Name = L"uaButton";
			this->uaButton->Size = System::Drawing::Size(230, 90);
			this->uaButton->TabIndex = 8;
			this->uaButton->Text = L"Ok";
			this->uaButton->UseVisualStyleBackColor = false;
			this->uaButton->Click += gcnew System::EventHandler(this, &MNL_SignIn::uaButton_Click);
			// 
			// uaLabelHeading
			// 
			this->uaLabelHeading->AutoSize = true;
			this->uaLabelHeading->BackColor = System::Drawing::Color::Transparent;
			this->uaLabelHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->uaLabelHeading->ForeColor = System::Drawing::Color::White;
			this->uaLabelHeading->Location = System::Drawing::Point(190, 241);
			this->uaLabelHeading->Name = L"uaLabelHeading";
			this->uaLabelHeading->Size = System::Drawing::Size(584, 85);
			this->uaLabelHeading->TabIndex = 7;
			this->uaLabelHeading->Text = L"User Agreement";
			this->uaLabelHeading->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registerNoTextLabel
			// 
			this->registerNoTextLabel->AutoSize = true;
			this->registerNoTextLabel->BackColor = System::Drawing::Color::Transparent;
			this->registerNoTextLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerNoTextLabel->ForeColor = System::Drawing::Color::Red;
			this->registerNoTextLabel->Location = System::Drawing::Point(199, 871);
			this->registerNoTextLabel->Name = L"registerNoTextLabel";
			this->registerNoTextLabel->Size = System::Drawing::Size(507, 31);
			this->registerNoTextLabel->TabIndex = 19;
			this->registerNoTextLabel->Text = L"Please enter a Username and Password!";
			this->registerNoTextLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->registerNoTextLabel->Visible = false;
			// 
			// MNL_SignIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(192, 192);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->accountLabel);
			this->Controls->Add(this->createAccountLabel);
			this->Controls->Add(this->incorrectDetailsLabel);
			this->Controls->Add(this->mnlLabel);
			this->Controls->Add(this->copyLabel);
			this->Controls->Add(this->uaLabel);
			this->Controls->Add(this->uaCheckBox);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->signInButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->signInLabel);
			this->Controls->Add(this->uaPanel);
			this->Controls->Add(this->registerPanel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MNL_SignIn";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MNL: Sign-In";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_SignIn::MNL_SignIn_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_SignIn::MNL_SignIn_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_SignIn::MNL_SignIn_MouseUp);
			this->registerPanel->ResumeLayout(false);
			this->registerPanel->PerformLayout();
			this->uaPanel->ResumeLayout(false);
			this->uaPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// "On-click" event for the sign-in button
		private: System::Void signInButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// Temporary strings
			std::string userTemp, passTemp;
			// In filestream to the designated filepath
			std::ifstream in("UP.dat");

			// While the file is open
			while (in)
			{
				// If the filestream can get a line, set userTemp and passTemp to the associated text
				if (in >> userTemp >> passTemp)
				{
					// Add the temporary variables to their vector lists
					usernameVector.emplace_back(userTemp);
					passwordVector.emplace_back(passTemp);

					// If the text in the username and password text boxes match the temporary variables
					if (msclr::interop::marshal_as<std::string>(usernameTextBox->Text) == userTemp &&
						msclr::interop::marshal_as<std::string>(passwordTextBox->Text) == passTemp)
					{
						// Allow login by setting the bool to true
						loginSuccessful = true;
						// Note the name of the successful user
						successfulUsername = msclr::interop::marshal_as<std::string>(usernameTextBox->Text);
						break;
					}
				}
			}

			// Close the file
			in.close();

			// If raw data is correct for both fields then allow access
			if (loginSuccessful)
			{
				incorrectDetailsLabel->Visible = false;
				// Hide the current window
				this->Hide();
				// Create an instance of the home screen
				MNL_Home^ home = gcnew MNL_Home(successfulUsername);
				// Display it as a dialogue box (must be done as only one Windows Form program can be active
				// at one time and closing the current window would shut down the program)
				home->ShowDialog();
				// Close the current window after the new window is opened
				this->Close();
			}
			else
			{
				// Display error message if the username or password is wrong
				incorrectDetailsLabel->Visible = true;
				loginSuccessful = false;
			}
		}

		// "On-click" event for the exit button
		private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Application::Exit();
		}

		// "Check changed" event for the user agreement checkbox
		private: System::Void uaCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			// If the user has agreed to the user agreement
			if (uaCheckBox->Checked)
			{
				// Enable the sign-in button
				signInButton->Enabled = true;
			}
			else
			{
				// Disable the button
				signInButton->Enabled = false;
			}
		}

		// "On-click" event for the user agreement panel's ok button
		private: System::Void uaButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// Hide the user agreement panel
			uaPanel->SendToBack();
			uaPanel->Hide();
		}

		// "On-click" event for the user agreement label
		private: System::Void uaLabel_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// Displays the user agreement panel
			uaPanel->BringToFront();
			uaPanel->Show();

			incorrectDetailsLabel->Visible = false;
		}

		// Mouse event variables
		bool isDragging;
		Point offset;
		// Allows user to drag around the application window through various mouse events
		private: System::Void MNL_SignIn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Enable dragging and set the offset to the mouse's position
			isDragging = true;
			offset.X = e->X;
			offset.Y = e->Y;
		}
		private: System::Void MNL_SignIn_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// If the user is dragging their mouse
			if (isDragging)
			{
				// Move the screen to that point minus the mouse offset
				Point currentScreenPos = PointToScreen(Point(e->X, e->Y));
				Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
			}
		}
		private: System::Void MNL_SignIn_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			// Set dragging to false
			isDragging = false;
		}

		// "On-click" event for the register user button
		private: System::Void registerButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			//If username and password fields have data then write it to a .dat file
			if (registerUserTextBox->Text != "" && registerPassTextBox->Text != "")
			{
				registerNoTextLabel->Visible = false;

				std::ofstream outFile;
				// Open an out filestream
				outFile.open("UP.dat", std::fstream::app);
				// Write the contents of the username and password box to the file
				outFile << msclr::interop::marshal_as<std::string>(registerUserTextBox->Text) << " " << msclr::interop::marshal_as<std::string>(registerPassTextBox->Text) << std::endl;
				// Close the file
				outFile.close();

				// Clear the text boxes
				registerUserTextBox->Clear();
				registerPassTextBox->Clear();

				// Hide the registration panel
				registerPanel->Hide();
				registerPanel->SendToBack();
			}
			else
			{
				// Display an error if one of the text fields is empty
				registerNoTextLabel->Visible = true;
			}
		}

		// "On-click" event for the create account label
		private: System::Void createAccountLabel_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// Shows the registration panel
			registerPanel->BringToFront();
			registerPanel->Show();

			incorrectDetailsLabel->Visible = false;
		}
	};
}
