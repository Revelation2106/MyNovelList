#pragma once

/*

Name: Thomas Cole

Student ID: B00269678

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "MNL_SignIn.h"
#include "DoubleLinkedList.h"
#include "Sort.h"
#include "Cryptographer.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <msclr/marshal_cppstd.h> //Used to convert C# String^ to C++ std::string and vice-versa

namespace MyNovelList {

	//Allow use of C#-related code within C++
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Opens the home screen
	/// </summary>
	public ref class MNL_Home : public System::Windows::Forms::Form
	{
	protected:

		// Sorting enum
		enum class SortingAlgorithm
		{
			Bubble = 0,
			Selection,
			Insertion,
			Shell,
		};

		// Variables used to measure time of sorting algorithms
		std::chrono::steady_clock::time_point* timerBegin, * timerEnd;

		// Variable used to create user data file based on whoever logs in
		std::string* filename;

		// Declaration and definition of doubly linked list
		DoubleLinkedList* bookLinkedList = new DoubleLinkedList();

		// Mouse event variables
		bool isDragging;
		Point offset;

		// Declaration and definition of variable to track incrimentation 
		// of key for use in linked list
		int keyAccum = 0;

		// Windows Forms generated declarations
		private: System::Windows::Forms::Button^ sortTitleAscButton;
		private: System::Windows::Forms::Button^ sortTitleDescButton;
		private: System::Windows::Forms::Label^ sortTitleLabel;
		private: System::Windows::Forms::Label^ sortAuthorLabel;
		private: System::Windows::Forms::Button^ sortAuthorDescButton;
		private: System::Windows::Forms::Button^ sortAuthorAscButton;
		private: System::Windows::Forms::Label^ sortSeriesLabel;
		private: System::Windows::Forms::Button^ sortSeriesDescButton;
		private: System::Windows::Forms::Button^ sortSeriesAscButton;
		private: System::Windows::Forms::Label^ sortScoreLabel;
		private: System::Windows::Forms::Button^ sortScoreDescButton;
		private: System::Windows::Forms::Button^ sortScoreAscButton;
		private: System::Windows::Forms::ListBox^ sortListBox;

		internal: System::Windows::Forms::ColumnHeader^ keyColumn;
		private: System::Windows::Forms::Button^ editButton;
		private: System::Windows::Forms::Label^ nameErrorLabel;
		private: System::Windows::Forms::Label^ authorErrorLabel;
		private: System::Windows::Forms::Label^ scoreErrorLabel;
		private: System::Windows::Forms::Label^ sortLabel;
		private: System::Windows::Forms::TextBox^ timeTextBox;
		private: System::Windows::Forms::Label^ deleteErrorLabel;
		private: System::Windows::Forms::Label^ editErrorLabel;
		private: System::Windows::Forms::Button^ clearButton;
		private: System::Windows::Forms::Label^ seriesNameErrorLabel;
		private: System::Windows::Forms::Button^ deleteButton;

	public:
		MNL_Home(std::string username)
		{
			InitializeComponent();

			// Set default sort
			sortListBox->SelectedIndex = 0;

			filename = new std::string(username + "_data.dat");

			// Decrypt user data
			std::stringstream decryptedIn = DecryptFromFile((*filename));

			if (decryptedIn.tellp() == std::streampos(0))
				return;

			std::string keyAccumString;

			// Read decrypted data
			// First line of file is always the key accumulator
			std::getline(decryptedIn, keyAccumString);
			keyAccum = std::stoi(keyAccumString);

			BookFromFile(decryptedIn);

			UpdateListView();
		}

	protected:
		/// <summary>
		/// Clean up any Windows Forms resources being used.
		/// </summary>
		~MNL_Home()
		{
			// If components exist, delete them
			if (components)
			{
				delete components;
			}
		}

		// Windows Forms generated declarations
		private: System::Windows::Forms::TextBox^ nameTextBox;
		private: System::Windows::Forms::TextBox^ authorTextBox;
		private: System::Windows::Forms::CheckBox^ seriesCheckBox;
		private: System::Windows::Forms::Label^ nameLabel;
		private: System::Windows::Forms::Label^ authorLabel;
		private: System::Windows::Forms::Label^ partOfSeriesLabel;
		private: System::Windows::Forms::Label^ seriesNameLabel;
		private: System::Windows::Forms::TextBox^ seriesTextBox;
		private: System::Windows::Forms::NumericUpDown^ volumeUpDown;
		private: System::Windows::Forms::Label^ volumeLabel;
		private: System::Windows::Forms::Label^ scoreLabel;
		private: System::Windows::Forms::Button^ submitButton;
		private: System::Windows::Forms::Button^ exitButton;
		private: System::Windows::Forms::ListBox^ scoreListBox;
		private: System::Windows::Forms::ListView^ libraryDisplayListView;
		private: System::Windows::Forms::ColumnHeader^ titleColumn;
		private: System::Windows::Forms::ColumnHeader^ authorColumn;
		private: System::Windows::Forms::ColumnHeader^ seriesColumn;
		private: System::Windows::Forms::ColumnHeader^ volumeColumn;
		private: System::Windows::Forms::ColumnHeader^ scoreColumn;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MNL_Home::typeid));
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->authorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->seriesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->partOfSeriesLabel = (gcnew System::Windows::Forms::Label());
			this->seriesNameLabel = (gcnew System::Windows::Forms::Label());
			this->seriesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->volumeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->volumeLabel = (gcnew System::Windows::Forms::Label());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->scoreListBox = (gcnew System::Windows::Forms::ListBox());
			this->libraryDisplayListView = (gcnew System::Windows::Forms::ListView());
			this->titleColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->authorColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->seriesColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->volumeColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->scoreColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->keyColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->sortTitleAscButton = (gcnew System::Windows::Forms::Button());
			this->sortTitleDescButton = (gcnew System::Windows::Forms::Button());
			this->sortTitleLabel = (gcnew System::Windows::Forms::Label());
			this->sortAuthorLabel = (gcnew System::Windows::Forms::Label());
			this->sortAuthorDescButton = (gcnew System::Windows::Forms::Button());
			this->sortAuthorAscButton = (gcnew System::Windows::Forms::Button());
			this->sortSeriesLabel = (gcnew System::Windows::Forms::Label());
			this->sortSeriesDescButton = (gcnew System::Windows::Forms::Button());
			this->sortSeriesAscButton = (gcnew System::Windows::Forms::Button());
			this->sortScoreLabel = (gcnew System::Windows::Forms::Label());
			this->sortScoreDescButton = (gcnew System::Windows::Forms::Button());
			this->sortScoreAscButton = (gcnew System::Windows::Forms::Button());
			this->sortListBox = (gcnew System::Windows::Forms::ListBox());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->nameErrorLabel = (gcnew System::Windows::Forms::Label());
			this->authorErrorLabel = (gcnew System::Windows::Forms::Label());
			this->scoreErrorLabel = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->sortLabel = (gcnew System::Windows::Forms::Label());
			this->timeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->deleteErrorLabel = (gcnew System::Windows::Forms::Label());
			this->editErrorLabel = (gcnew System::Windows::Forms::Label());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->seriesNameErrorLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// nameTextBox
			// 
			this->nameTextBox->BackColor = System::Drawing::Color::Wheat;
			this->nameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nameTextBox->Location = System::Drawing::Point(51, 146);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(475, 31);
			this->nameTextBox->TabIndex = 0;
			// 
			// authorTextBox
			// 
			this->authorTextBox->BackColor = System::Drawing::Color::Wheat;
			this->authorTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->authorTextBox->Location = System::Drawing::Point(51, 328);
			this->authorTextBox->Name = L"authorTextBox";
			this->authorTextBox->Size = System::Drawing::Size(475, 31);
			this->authorTextBox->TabIndex = 1;
			// 
			// seriesCheckBox
			// 
			this->seriesCheckBox->AutoSize = true;
			this->seriesCheckBox->Location = System::Drawing::Point(50, 399);
			this->seriesCheckBox->Name = L"seriesCheckBox";
			this->seriesCheckBox->Size = System::Drawing::Size(28, 27);
			this->seriesCheckBox->TabIndex = 2;
			this->seriesCheckBox->UseVisualStyleBackColor = true;
			this->seriesCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MNL_Home::seriesCheckBox_CheckedChanged);
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::White;
			this->nameLabel->Location = System::Drawing::Point(41, 71);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(153, 55);
			this->nameLabel->TabIndex = 8;
			this->nameLabel->Text = L"Name";
			this->nameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// authorLabel
			// 
			this->authorLabel->AutoSize = true;
			this->authorLabel->BackColor = System::Drawing::Color::Transparent;
			this->authorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authorLabel->ForeColor = System::Drawing::Color::White;
			this->authorLabel->Location = System::Drawing::Point(41, 260);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(166, 55);
			this->authorLabel->TabIndex = 9;
			this->authorLabel->Text = L"Author";
			this->authorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// partOfSeriesLabel
			// 
			this->partOfSeriesLabel->AutoSize = true;
			this->partOfSeriesLabel->BackColor = System::Drawing::Color::Transparent;
			this->partOfSeriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->partOfSeriesLabel->ForeColor = System::Drawing::Color::White;
			this->partOfSeriesLabel->Location = System::Drawing::Point(84, 388);
			this->partOfSeriesLabel->Name = L"partOfSeriesLabel";
			this->partOfSeriesLabel->Size = System::Drawing::Size(306, 55);
			this->partOfSeriesLabel->TabIndex = 10;
			this->partOfSeriesLabel->Text = L"Part of series";
			this->partOfSeriesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// seriesNameLabel
			// 
			this->seriesNameLabel->AutoSize = true;
			this->seriesNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->seriesNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seriesNameLabel->ForeColor = System::Drawing::Color::White;
			this->seriesNameLabel->Location = System::Drawing::Point(41, 443);
			this->seriesNameLabel->Name = L"seriesNameLabel";
			this->seriesNameLabel->Size = System::Drawing::Size(160, 55);
			this->seriesNameLabel->TabIndex = 12;
			this->seriesNameLabel->Text = L"Series";
			this->seriesNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// seriesTextBox
			// 
			this->seriesTextBox->BackColor = System::Drawing::Color::Wheat;
			this->seriesTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->seriesTextBox->Enabled = false;
			this->seriesTextBox->Location = System::Drawing::Point(51, 518);
			this->seriesTextBox->Name = L"seriesTextBox";
			this->seriesTextBox->Size = System::Drawing::Size(475, 31);
			this->seriesTextBox->TabIndex = 11;
			// 
			// volumeUpDown
			// 
			this->volumeUpDown->BackColor = System::Drawing::Color::Wheat;
			this->volumeUpDown->Enabled = false;
			this->volumeUpDown->Location = System::Drawing::Point(551, 518);
			this->volumeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->volumeUpDown->Name = L"volumeUpDown";
			this->volumeUpDown->Size = System::Drawing::Size(120, 31);
			this->volumeUpDown->TabIndex = 13;
			this->volumeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// volumeLabel
			// 
			this->volumeLabel->AutoSize = true;
			this->volumeLabel->BackColor = System::Drawing::Color::Transparent;
			this->volumeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->volumeLabel->ForeColor = System::Drawing::Color::White;
			this->volumeLabel->Location = System::Drawing::Point(541, 443);
			this->volumeLabel->Name = L"volumeLabel";
			this->volumeLabel->Size = System::Drawing::Size(187, 55);
			this->volumeLabel->TabIndex = 14;
			this->volumeLabel->Text = L"Volume";
			this->volumeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scoreLabel->ForeColor = System::Drawing::Color::White;
			this->scoreLabel->Location = System::Drawing::Point(40, 580);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(150, 55);
			this->scoreLabel->TabIndex = 16;
			this->scoreLabel->Text = L"Score";
			this->scoreLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// submitButton
			// 
			this->submitButton->BackColor = System::Drawing::Color::Wheat;
			this->submitButton->FlatAppearance->BorderSize = 0;
			this->submitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submitButton->Location = System::Drawing::Point(51, 865);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(230, 40);
			this->submitButton->TabIndex = 17;
			this->submitButton->Text = L"Add";
			this->submitButton->UseVisualStyleBackColor = false;
			this->submitButton->Click += gcnew System::EventHandler(this, &MNL_Home::submitButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::Color::Wheat;
			this->exitButton->FlatAppearance->BorderSize = 0;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->Location = System::Drawing::Point(1609, 865);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(230, 90);
			this->exitButton->TabIndex = 18;
			this->exitButton->Text = L"Log Out";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &MNL_Home::exitButton_Click);
			// 
			// scoreListBox
			// 
			this->scoreListBox->BackColor = System::Drawing::Color::Wheat;
			this->scoreListBox->FormattingEnabled = true;
			this->scoreListBox->ItemHeight = 25;
			this->scoreListBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1 - (Appalling)", L"2 - (Horrible)", L"3 - (Very Bad)",
					L"4 - (Bad)", L"5 - (Average)", L"6 - (Fine)", L"7 - (Good)", L"8 - (Very Good)", L"9 - (Great)", L"10 - (Masterpiece)"
			});
			this->scoreListBox->Location = System::Drawing::Point(50, 656);
			this->scoreListBox->Name = L"scoreListBox";
			this->scoreListBox->Size = System::Drawing::Size(231, 104);
			this->scoreListBox->TabIndex = 19;
			// 
			// libraryDisplayListView
			// 
			this->libraryDisplayListView->BackColor = System::Drawing::Color::Wheat;
			this->libraryDisplayListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->titleColumn,
					this->authorColumn, this->seriesColumn, this->volumeColumn, this->scoreColumn, this->keyColumn
			});
			this->libraryDisplayListView->FullRowSelect = true;
			this->libraryDisplayListView->HideSelection = false;
			this->libraryDisplayListView->Location = System::Drawing::Point(734, 44);
			this->libraryDisplayListView->MultiSelect = false;
			this->libraryDisplayListView->Name = L"libraryDisplayListView";
			this->libraryDisplayListView->Size = System::Drawing::Size(1105, 690);
			this->libraryDisplayListView->TabIndex = 20;
			this->libraryDisplayListView->UseCompatibleStateImageBehavior = false;
			this->libraryDisplayListView->View = System::Windows::Forms::View::Details;
			this->libraryDisplayListView->SelectedIndexChanged += gcnew System::EventHandler(this, &MNL_Home::libraryDisplayListView_SelectedIndexChanged);
			// 
			// titleColumn
			// 
			this->titleColumn->Text = L"Title";
			this->titleColumn->Width = 150;
			// 
			// authorColumn
			// 
			this->authorColumn->Text = L"Author";
			this->authorColumn->Width = 100;
			// 
			// seriesColumn
			// 
			this->seriesColumn->Text = L"Series";
			this->seriesColumn->Width = 150;
			// 
			// volumeColumn
			// 
			this->volumeColumn->Text = L"Volume";
			this->volumeColumn->Width = 50;
			// 
			// scoreColumn
			// 
			this->scoreColumn->Text = L"Score";
			this->scoreColumn->Width = 50;
			// 
			// keyColumn
			// 
			this->keyColumn->Text = L"Key";
			this->keyColumn->Width = 50;
			// 
			// sortTitleAscButton
			// 
			this->sortTitleAscButton->BackColor = System::Drawing::Color::Wheat;
			this->sortTitleAscButton->FlatAppearance->BorderSize = 0;
			this->sortTitleAscButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortTitleAscButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortTitleAscButton->Location = System::Drawing::Point(733, 826);
			this->sortTitleAscButton->Name = L"sortTitleAscButton";
			this->sortTitleAscButton->Size = System::Drawing::Size(160, 60);
			this->sortTitleAscButton->TabIndex = 21;
			this->sortTitleAscButton->Text = L"Sort (Asc)";
			this->sortTitleAscButton->UseVisualStyleBackColor = false;
			this->sortTitleAscButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortTitleButton_Click);
			// 
			// sortTitleDescButton
			// 
			this->sortTitleDescButton->BackColor = System::Drawing::Color::Wheat;
			this->sortTitleDescButton->FlatAppearance->BorderSize = 0;
			this->sortTitleDescButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortTitleDescButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortTitleDescButton->Location = System::Drawing::Point(733, 892);
			this->sortTitleDescButton->Name = L"sortTitleDescButton";
			this->sortTitleDescButton->Size = System::Drawing::Size(160, 60);
			this->sortTitleDescButton->TabIndex = 23;
			this->sortTitleDescButton->Text = L"Sort (Desc)";
			this->sortTitleDescButton->UseVisualStyleBackColor = false;
			this->sortTitleDescButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortTitleDescButton_Click);
			// 
			// sortTitleLabel
			// 
			this->sortTitleLabel->AutoSize = true;
			this->sortTitleLabel->BackColor = System::Drawing::Color::Transparent;
			this->sortTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortTitleLabel->ForeColor = System::Drawing::Color::White;
			this->sortTitleLabel->Location = System::Drawing::Point(779, 792);
			this->sortTitleLabel->Name = L"sortTitleLabel";
			this->sortTitleLabel->Size = System::Drawing::Size(66, 31);
			this->sortTitleLabel->TabIndex = 24;
			this->sortTitleLabel->Text = L"Title";
			this->sortTitleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sortAuthorLabel
			// 
			this->sortAuthorLabel->AutoSize = true;
			this->sortAuthorLabel->BackColor = System::Drawing::Color::Transparent;
			this->sortAuthorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortAuthorLabel->ForeColor = System::Drawing::Color::White;
			this->sortAuthorLabel->Location = System::Drawing::Point(949, 792);
			this->sortAuthorLabel->Name = L"sortAuthorLabel";
			this->sortAuthorLabel->Size = System::Drawing::Size(94, 31);
			this->sortAuthorLabel->TabIndex = 27;
			this->sortAuthorLabel->Text = L"Author";
			this->sortAuthorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sortAuthorDescButton
			// 
			this->sortAuthorDescButton->BackColor = System::Drawing::Color::Wheat;
			this->sortAuthorDescButton->FlatAppearance->BorderSize = 0;
			this->sortAuthorDescButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortAuthorDescButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortAuthorDescButton->Location = System::Drawing::Point(916, 892);
			this->sortAuthorDescButton->Name = L"sortAuthorDescButton";
			this->sortAuthorDescButton->Size = System::Drawing::Size(160, 60);
			this->sortAuthorDescButton->TabIndex = 26;
			this->sortAuthorDescButton->Text = L"Sort (Desc)";
			this->sortAuthorDescButton->UseVisualStyleBackColor = false;
			this->sortAuthorDescButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortAuthorDescButton_Click);
			// 
			// sortAuthorAscButton
			// 
			this->sortAuthorAscButton->BackColor = System::Drawing::Color::Wheat;
			this->sortAuthorAscButton->FlatAppearance->BorderSize = 0;
			this->sortAuthorAscButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortAuthorAscButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortAuthorAscButton->Location = System::Drawing::Point(916, 826);
			this->sortAuthorAscButton->Name = L"sortAuthorAscButton";
			this->sortAuthorAscButton->Size = System::Drawing::Size(160, 60);
			this->sortAuthorAscButton->TabIndex = 25;
			this->sortAuthorAscButton->Text = L"Sort (Asc)";
			this->sortAuthorAscButton->UseVisualStyleBackColor = false;
			this->sortAuthorAscButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortAuthorAscButton_Click);
			// 
			// sortSeriesLabel
			// 
			this->sortSeriesLabel->AutoSize = true;
			this->sortSeriesLabel->BackColor = System::Drawing::Color::Transparent;
			this->sortSeriesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortSeriesLabel->ForeColor = System::Drawing::Color::White;
			this->sortSeriesLabel->Location = System::Drawing::Point(1131, 792);
			this->sortSeriesLabel->Name = L"sortSeriesLabel";
			this->sortSeriesLabel->Size = System::Drawing::Size(91, 31);
			this->sortSeriesLabel->TabIndex = 30;
			this->sortSeriesLabel->Text = L"Series";
			this->sortSeriesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sortSeriesDescButton
			// 
			this->sortSeriesDescButton->BackColor = System::Drawing::Color::Wheat;
			this->sortSeriesDescButton->FlatAppearance->BorderSize = 0;
			this->sortSeriesDescButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortSeriesDescButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortSeriesDescButton->Location = System::Drawing::Point(1098, 892);
			this->sortSeriesDescButton->Name = L"sortSeriesDescButton";
			this->sortSeriesDescButton->Size = System::Drawing::Size(160, 60);
			this->sortSeriesDescButton->TabIndex = 29;
			this->sortSeriesDescButton->Text = L"Sort (Desc)";
			this->sortSeriesDescButton->UseVisualStyleBackColor = false;
			this->sortSeriesDescButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortSeriesDescButton_Click);
			// 
			// sortSeriesAscButton
			// 
			this->sortSeriesAscButton->BackColor = System::Drawing::Color::Wheat;
			this->sortSeriesAscButton->FlatAppearance->BorderSize = 0;
			this->sortSeriesAscButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortSeriesAscButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortSeriesAscButton->Location = System::Drawing::Point(1098, 826);
			this->sortSeriesAscButton->Name = L"sortSeriesAscButton";
			this->sortSeriesAscButton->Size = System::Drawing::Size(160, 60);
			this->sortSeriesAscButton->TabIndex = 28;
			this->sortSeriesAscButton->Text = L"Sort (Asc)";
			this->sortSeriesAscButton->UseVisualStyleBackColor = false;
			this->sortSeriesAscButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortSeriesAscButton_Click);
			// 
			// sortScoreLabel
			// 
			this->sortScoreLabel->AutoSize = true;
			this->sortScoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->sortScoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortScoreLabel->ForeColor = System::Drawing::Color::White;
			this->sortScoreLabel->Location = System::Drawing::Point(1310, 792);
			this->sortScoreLabel->Name = L"sortScoreLabel";
			this->sortScoreLabel->Size = System::Drawing::Size(85, 31);
			this->sortScoreLabel->TabIndex = 33;
			this->sortScoreLabel->Text = L"Score";
			this->sortScoreLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sortScoreDescButton
			// 
			this->sortScoreDescButton->BackColor = System::Drawing::Color::Wheat;
			this->sortScoreDescButton->FlatAppearance->BorderSize = 0;
			this->sortScoreDescButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortScoreDescButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortScoreDescButton->Location = System::Drawing::Point(1277, 892);
			this->sortScoreDescButton->Name = L"sortScoreDescButton";
			this->sortScoreDescButton->Size = System::Drawing::Size(160, 60);
			this->sortScoreDescButton->TabIndex = 32;
			this->sortScoreDescButton->Text = L"Sort (Desc)";
			this->sortScoreDescButton->UseVisualStyleBackColor = false;
			this->sortScoreDescButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortScoreDescButton_Click);
			// 
			// sortScoreAscButton
			// 
			this->sortScoreAscButton->BackColor = System::Drawing::Color::Wheat;
			this->sortScoreAscButton->FlatAppearance->BorderSize = 0;
			this->sortScoreAscButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sortScoreAscButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sortScoreAscButton->Location = System::Drawing::Point(1277, 826);
			this->sortScoreAscButton->Name = L"sortScoreAscButton";
			this->sortScoreAscButton->Size = System::Drawing::Size(160, 60);
			this->sortScoreAscButton->TabIndex = 31;
			this->sortScoreAscButton->Text = L"Sort (Asc)";
			this->sortScoreAscButton->UseVisualStyleBackColor = false;
			this->sortScoreAscButton->Click += gcnew System::EventHandler(this, &MNL_Home::sortScoreAscButton_Click);
			// 
			// sortListBox
			// 
			this->sortListBox->BackColor = System::Drawing::Color::Wheat;
			this->sortListBox->FormattingEnabled = true;
			this->sortListBox->ItemHeight = 25;
			this->sortListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bubble", L"Selection", L"Insertion", L"Shell" });
			this->sortListBox->Location = System::Drawing::Point(1457, 823);
			this->sortListBox->Name = L"sortListBox";
			this->sortListBox->Size = System::Drawing::Size(130, 129);
			this->sortListBox->TabIndex = 34;
			// 
			// editButton
			// 
			this->editButton->BackColor = System::Drawing::Color::Wheat;
			this->editButton->FlatAppearance->BorderSize = 0;
			this->editButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editButton->Location = System::Drawing::Point(320, 865);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(230, 40);
			this->editButton->TabIndex = 36;
			this->editButton->Text = L"Edit Selected";
			this->editButton->UseVisualStyleBackColor = false;
			this->editButton->Click += gcnew System::EventHandler(this, &MNL_Home::editButton_Click);
			// 
			// nameErrorLabel
			// 
			this->nameErrorLabel->AutoSize = true;
			this->nameErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->nameErrorLabel->Location = System::Drawing::Point(310, 101);
			this->nameErrorLabel->Name = L"nameErrorLabel";
			this->nameErrorLabel->Size = System::Drawing::Size(216, 25);
			this->nameErrorLabel->TabIndex = 37;
			this->nameErrorLabel->Text = L"Please enter a name!";
			this->nameErrorLabel->Visible = false;
			// 
			// authorErrorLabel
			// 
			this->authorErrorLabel->AutoSize = true;
			this->authorErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->authorErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->authorErrorLabel->Location = System::Drawing::Point(290, 284);
			this->authorErrorLabel->Name = L"authorErrorLabel";
			this->authorErrorLabel->Size = System::Drawing::Size(236, 25);
			this->authorErrorLabel->TabIndex = 38;
			this->authorErrorLabel->Text = L"Please enter an author!";
			this->authorErrorLabel->Visible = false;
			// 
			// scoreErrorLabel
			// 
			this->scoreErrorLabel->AutoSize = true;
			this->scoreErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->scoreErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->scoreErrorLabel->Location = System::Drawing::Point(302, 656);
			this->scoreErrorLabel->Name = L"scoreErrorLabel";
			this->scoreErrorLabel->Size = System::Drawing::Size(224, 25);
			this->scoreErrorLabel->TabIndex = 39;
			this->scoreErrorLabel->Text = L"Please select a score!";
			this->scoreErrorLabel->Visible = false;
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::Wheat;
			this->deleteButton->FlatAppearance->BorderSize = 0;
			this->deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteButton->Location = System::Drawing::Point(320, 915);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(230, 40);
			this->deleteButton->TabIndex = 40;
			this->deleteButton->Text = L"Delete Selected";
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MNL_Home::deleteButton_Click);
			// 
			// sortLabel
			// 
			this->sortLabel->AutoSize = true;
			this->sortLabel->BackColor = System::Drawing::Color::Transparent;
			this->sortLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sortLabel->ForeColor = System::Drawing::Color::White;
			this->sortLabel->Location = System::Drawing::Point(1468, 761);
			this->sortLabel->Name = L"sortLabel";
			this->sortLabel->Size = System::Drawing::Size(107, 62);
			this->sortLabel->TabIndex = 41;
			this->sortLabel->Text = L"Sorting \r\nMethod";
			this->sortLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeTextBox
			// 
			this->timeTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->timeTextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->timeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeTextBox->Location = System::Drawing::Point(1457, 959);
			this->timeTextBox->Name = L"timeTextBox";
			this->timeTextBox->ReadOnly = true;
			this->timeTextBox->Size = System::Drawing::Size(130, 22);
			this->timeTextBox->TabIndex = 42;
			this->timeTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// deleteErrorLabel
			// 
			this->deleteErrorLabel->AutoSize = true;
			this->deleteErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->deleteErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->deleteErrorLabel->Location = System::Drawing::Point(347, 958);
			this->deleteErrorLabel->Name = L"deleteErrorLabel";
			this->deleteErrorLabel->Size = System::Drawing::Size(179, 25);
			this->deleteErrorLabel->TabIndex = 43;
			this->deleteErrorLabel->Text = L"Nothing selected!";
			this->deleteErrorLabel->Visible = false;
			// 
			// editErrorLabel
			// 
			this->editErrorLabel->AutoSize = true;
			this->editErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->editErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->editErrorLabel->Location = System::Drawing::Point(347, 837);
			this->editErrorLabel->Name = L"editErrorLabel";
			this->editErrorLabel->Size = System::Drawing::Size(179, 25);
			this->editErrorLabel->TabIndex = 44;
			this->editErrorLabel->Text = L"Nothing selected!";
			this->editErrorLabel->Visible = false;
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::Color::Wheat;
			this->clearButton->FlatAppearance->BorderSize = 0;
			this->clearButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearButton->Location = System::Drawing::Point(51, 915);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(230, 40);
			this->clearButton->TabIndex = 45;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &MNL_Home::clearButton_Click);
			// 
			// seriesNameErrorLabel
			// 
			this->seriesNameErrorLabel->AutoSize = true;
			this->seriesNameErrorLabel->BackColor = System::Drawing::Color::Transparent;
			this->seriesNameErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->seriesNameErrorLabel->Location = System::Drawing::Point(310, 467);
			this->seriesNameErrorLabel->Name = L"seriesNameErrorLabel";
			this->seriesNameErrorLabel->Size = System::Drawing::Size(216, 25);
			this->seriesNameErrorLabel->TabIndex = 46;
			this->seriesNameErrorLabel->Text = L"Please enter a name!";
			this->seriesNameErrorLabel->Visible = false;
			// 
			// MNL_Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(192, 192);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1894, 1009);
			this->Controls->Add(this->seriesNameErrorLabel);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->editErrorLabel);
			this->Controls->Add(this->deleteErrorLabel);
			this->Controls->Add(this->timeTextBox);
			this->Controls->Add(this->sortLabel);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->scoreErrorLabel);
			this->Controls->Add(this->authorErrorLabel);
			this->Controls->Add(this->nameErrorLabel);
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->sortListBox);
			this->Controls->Add(this->sortScoreLabel);
			this->Controls->Add(this->sortScoreDescButton);
			this->Controls->Add(this->sortScoreAscButton);
			this->Controls->Add(this->sortSeriesLabel);
			this->Controls->Add(this->sortSeriesDescButton);
			this->Controls->Add(this->sortSeriesAscButton);
			this->Controls->Add(this->sortAuthorLabel);
			this->Controls->Add(this->sortAuthorDescButton);
			this->Controls->Add(this->sortAuthorAscButton);
			this->Controls->Add(this->sortTitleLabel);
			this->Controls->Add(this->sortTitleDescButton);
			this->Controls->Add(this->sortTitleAscButton);
			this->Controls->Add(this->libraryDisplayListView);
			this->Controls->Add(this->scoreListBox);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->volumeLabel);
			this->Controls->Add(this->volumeUpDown);
			this->Controls->Add(this->seriesNameLabel);
			this->Controls->Add(this->seriesTextBox);
			this->Controls->Add(this->partOfSeriesLabel);
			this->Controls->Add(this->authorLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->seriesCheckBox);
			this->Controls->Add(this->authorTextBox);
			this->Controls->Add(this->nameTextBox);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MNL_Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MNL: Home";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_Home::MNL_Home_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_Home::MNL_Home_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MNL_Home::MNL_Home_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// "Checked changed" event for the series checkbox
		private: System::Void seriesCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// If the new entry is marked as a series
		if (seriesCheckBox->Checked)
		{
			// Allow editing of the series name and volume count
			seriesTextBox->Enabled = true;
			volumeUpDown->Enabled = true;

			return;
		}

		// Clear and reset the fields
		seriesTextBox->Clear();
		volumeUpDown->Value = 1;

		// Disable the options
		seriesTextBox->Enabled = false;
		volumeUpDown->Enabled = false;
	}

		// "Mouse move" events allows user to move the application by clicking and dragging
		private: System::Void MNL_Home_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		isDragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
		private: System::Void MNL_Home_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (isDragging)
		{
			Point currentScreenPos = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
		}
	}
		private: System::Void MNL_Home_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		isDragging = false;
	}

		// Clear error labels
		private: void ClearErrorLabels()
	{
		nameErrorLabel->Visible = false;
		authorErrorLabel->Visible = false;
		scoreErrorLabel->Visible = false;
		editErrorLabel->Visible = false;
		deleteErrorLabel->Visible = false;
		seriesNameErrorLabel->Visible = false;
	}

		// Factory function to create book
		private: Book* CreateBook()
	{
		using namespace msclr::interop;

		Book* b = new Book();
		b->title = marshal_as<std::string>(nameTextBox->Text);
		b->author = marshal_as<std::string>(authorTextBox->Text);

		// Gets the score from the ListBox and converts it into a string
		std::string tempScoreString = marshal_as<std::string>(scoreListBox->Text);
		int pos = tempScoreString.find(" - ");
		b->score = std::stoi(tempScoreString.substr(0, pos));

		// Checks if book is a series and fills out info as appropriate
		if (seriesCheckBox->Checked)
		{
			b->isSeries = true;
			b->series = marshal_as<std::string>(seriesTextBox->Text);
			b->volume = std::stoi(marshal_as<std::string>(volumeUpDown->Text));
		}

		return b;
	}

		// Creates a book from a stringstream
		private: void BookFromFile(std::stringstream& stream)
	{
		std::string title, author, series, volume, score, inKey;

		// Reads to the end of the file and parses data
		while (std::getline(stream, title, '\t'), std::getline(stream, author, '\t'),
			std::getline(stream, series, '\t'), std::getline(stream, volume, '\t'),
			std::getline(stream, score, '\t'), std::getline(stream, inKey))
		{
			// Create node with unique key
			Node* temp = new Node();
			temp->key = std::stoi(inKey);
			String^ tempKey = temp->key.ToString();

			// Creates book, taking info from text boxes
			Book* b = new Book();
			b->title = title;
			b->author = author;

			if (series != "@")
			{
				b->isSeries = true;
				b->series = series;
			}

			b->volume = std::stoi(volume);
			b->score = std::stoi(score);

			// Adds book to linked list
			temp->data = b;
			bookLinkedList->appendNode(temp);
		}
	}

		// Add linked list node
		private: void AddNode()
	{
		// Create node with unique key
		Node* temp = new Node();
		// Check if the head is nullptr, if so reset keyAccum
		if (bookLinkedList->head == nullptr)
			keyAccum = 0;
		temp->key = keyAccum++;

		// Creates and adds book to linked list
		temp->data = CreateBook();
		bookLinkedList->appendNode(temp);
	}

		// Updates the ListView's contents
		private: void UpdateListView()
	{
		libraryDisplayListView->Items->Clear();

		for (Node* node = bookLinkedList->head; node != nullptr; node = node->next)
		{
			using namespace msclr::interop;

			// Add to ListView by creating a ListViewItem and filling it out
			array<String^>^ subItems = gcnew array<String^>(6);
			subItems[0] = marshal_as<String^>(node->data->title);
			subItems[1] = marshal_as<String^>(node->data->author);
			subItems[2] = marshal_as<String^>(node->data->series);
			subItems[3] = node->data->volume.ToString();
			subItems[4] = node->data->score.ToString();
			subItems[5] = node->key.ToString();
			ListViewItem^ tempLV = gcnew ListViewItem(subItems);
			libraryDisplayListView->Items->Add(tempLV);
		}
	}

		// Clear data fields
		private: void ClearFields()
	{
		// Clear and reset text/list/check boxes
		nameTextBox->Clear();
		authorTextBox->Clear();
		seriesCheckBox->Checked = false;
		seriesTextBox->Clear();
		volumeUpDown->Value = 1;
		scoreListBox->SelectedIndex = 0;
		scoreListBox->SelectedIndex = -1;

		// Focus the user text input on the title text box,
		// allows easier navigation if the user wants to input 
		// books in quick succession
		nameTextBox->Focus();
	}

		// Checks whether data is valid
		private: bool IsValidData()
	{
		// If the name text box is empty
		if (nameTextBox->Text == "")
			nameErrorLabel->Visible = true;
		// If the author text box is empty
		if (authorTextBox->Text == "")
			authorErrorLabel->Visible = true;
		// If the score ListBox hasn't been selected
		if (scoreListBox->Text == "")
			scoreErrorLabel->Visible = true;
		// If the isSeries checkbox is checked and the series name text box is empty
		if (seriesCheckBox->Checked == true && seriesTextBox->Text == "")
			seriesNameErrorLabel->Visible = true;
		// If no error messages are showing
		if (nameErrorLabel->Visible || authorErrorLabel->Visible ||
			scoreErrorLabel->Visible || seriesNameErrorLabel->Visible)
			return false;

		return true;
	}

		// Check ListBox has a valid selection
		private: bool IsValidSelected()
	{
		// Check if anything is selected
		if (libraryDisplayListView->SelectedItems->Count == 0)
		{
			return false;
		}

		return true;
	}

		// Button "on-click" events for adding, editing and deleting entries
		private: System::Void submitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Hide error labels for text fields
		ClearErrorLabels();

		if (!IsValidData())
			return;

		AddNode();
		UpdateListView();
		ClearFields();
	}
		private: System::Void editButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Hide error labels
		ClearErrorLabels();

		// If no error messages are showing
		if (!IsValidData() || !IsValidSelected())
			return;

		// Get key from ListView
		std::string listKey = msclr::interop::marshal_as<std::string>(libraryDisplayListView->SelectedItems[0]->SubItems[5]->Text);

		// Updates linked list with new data
		bookLinkedList->updateNodeByKey(std::stoi(listKey), CreateBook());

		UpdateListView();
		ClearFields();
	}
		private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ClearErrorLabels();

		if (!IsValidSelected())
			return deleteErrorLabel->Visible = true;

		// Get key from ListView
		std::string listKey = msclr::interop::marshal_as<std::string>(libraryDisplayListView->SelectedItems[0]->SubItems[5]->Text);

		// Delete node based on key
		bookLinkedList->deleteNodeByKey(std::stoi(listKey));

		// Updates ListView
		UpdateListView();

		// Clear data fields
		ClearFields();
	}

		// Function to update the timer text box
		private: void UpdateTimerTextBox(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end)
	{
		std::chrono::duration<double, std::milli> msDouble = end - begin;
		timeTextBox->Text = msclr::interop::marshal_as<String^>(std::to_string(msDouble.count()) + " ms");
	}

		// Function which can be passed a sorting algorithm template to time
		DoubleLinkedList* TimeASort(Sort::SortFunc sort, Sort::CompareFunc comparator)
		   {
			   DoubleLinkedList* temp;
			   timerBegin = &std::chrono::high_resolution_clock::now();
			   temp = sort(bookLinkedList, comparator);
			   timerEnd = &std::chrono::high_resolution_clock::now();

			   UpdateTimerTextBox((*timerBegin), (*timerEnd));

			   return temp;
		   }

		// Decide which sorting algorithm to use
		private: void DecideSort(Sort::CompareFunc comparator)
	{
		// Switch statement to determine which sorting algorithm to apply
		switch ((SortingAlgorithm)sortListBox->SelectedIndex)
		{
		case SortingAlgorithm::Bubble:
			bookLinkedList = TimeASort(Sort::BubbleSort, comparator);
			break;
		case SortingAlgorithm::Selection:
			bookLinkedList = TimeASort(Sort::SelectionSort, comparator);
			break;
		case SortingAlgorithm::Insertion:
			bookLinkedList = TimeASort(Sort::InsertionSort, comparator);
			break;
		case SortingAlgorithm::Shell:
			bookLinkedList = TimeASort(Sort::ShellSort, comparator);
			break;
		}
	}

		// Sorting button "on-click" event handlers
		private: System::Void sortTitleButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareTitle);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortTitleDescButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareTitleBack);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortAuthorAscButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareAuthor);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortAuthorDescButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareAuthorBack);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortSeriesAscButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareSeries);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortSeriesDescButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareSeriesBack);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortScoreAscButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareScore);

		// Updates ListView with sorted data
		UpdateListView();
	}
		private: System::Void sortScoreDescButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Decide on which sorting algorithm to apply
		DecideSort(Sort::CompareScoreBack);

		// Updates ListView with sorted data
		UpdateListView();
	}

		// Exit button "on-click" event handler 
		private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Open out filestream to save user book data
		std::stringstream outFile;
		outFile << keyAccum << "\n";

		// For each node in the linked list
		for (int i = 0; i < bookLinkedList->size(); i++)
		{
			// Output the C++ strings to the file
			outFile << (*bookLinkedList)[i]->data->title << "\t"
				<< (*bookLinkedList)[i]->data->author << "\t"
				<< ((*bookLinkedList)[i]->data->series == "" ? "@" : (*bookLinkedList)[i]->data->series) << "\t"
				<< (*bookLinkedList)[i]->data->volume << "\t"
				<< (*bookLinkedList)[i]->data->score << "\t"
				<< (*bookLinkedList)[i]->key
				<< std::endl;
		}

		// Encrypt data
		EncryptToFile(outFile, (*filename));

		// Restart the application to allow the user to log in again if they wish
		Application::Restart();
		// In order to avoid a fatal crash when calling Restart(), 
		// the current environment must exit with code 0
		Environment::Exit(0);
	}

		// "Selection index changed" event handler for the ListView
		private: System::Void libraryDisplayListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// Check if anything is actually selected
		if (!IsValidSelected())
			return;

		// Create temporary variable to extract data from
		ListViewItem^ temp = libraryDisplayListView->SelectedItems[0];

		// Only replace fields if the user hasn't input something already
		nameTextBox->Text = temp->SubItems[0]->Text;
		authorTextBox->Text = temp->SubItems[1]->Text;
		seriesTextBox->Text = temp->SubItems[2]->Text;

		if (seriesTextBox->Text != "")
			seriesCheckBox->Checked = true;
		else
			seriesCheckBox->Checked = false;

		// ->Value and ->SelectedIndex requires an int, so convert from String^ 
		// to std::string and then do std::stoi to get int value
		std::string volString = msclr::interop::marshal_as<std::string>(temp->SubItems[3]->Text);
		volumeUpDown->Value = std::stoi(volString);

		std::string scoreString = msclr::interop::marshal_as<std::string>(temp->SubItems[4]->Text);
		scoreListBox->SelectedIndex = std::stoi(scoreString) - 1;
	}

		// "On-click" event handler for the clear button
		private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ClearErrorLabels();
		ClearFields();

		// Deselects anything in the ListView
		libraryDisplayListView->SelectedIndices->Clear();
	}
	};
}