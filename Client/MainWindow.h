#pragma once

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			serverIP = "127.0.0.1";
			serverPort = "8888";
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::Button^ buttonSend;
	private: System::Windows::Forms::TextBox^ textBoxPath;
	private: System::Windows::Forms::TextBox^ textBoxData;




	private: System::Windows::Forms::Label^ LabelAdress;
	private: System::Windows::Forms::Label^ labelPath;
	private: System::Windows::Forms::Label^ labelData;
	private: System::Windows::Forms::Label^ labelPort;

	private: System::Windows::Forms::MenuStrip^ menuTop;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutProgrammToolStripMenuItem;

	private: System::Windows::Forms::TextBox^ textBoxIP;
	private: System::Windows::Forms::TextBox^ textBoxPort;

	private: System::String^ serverIP;
	private: System::String^ serverPort;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->textBoxData = (gcnew System::Windows::Forms::TextBox());
			this->LabelAdress = (gcnew System::Windows::Forms::Label());
			this->labelPath = (gcnew System::Windows::Forms::Label());
			this->labelData = (gcnew System::Windows::Forms::Label());
			this->labelPort = (gcnew System::Windows::Forms::Label());
			this->menuTop = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutProgrammToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPort = (gcnew System::Windows::Forms::TextBox());
			this->menuTop->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(472, 95);
			this->buttonConnect->Margin = System::Windows::Forms::Padding(8);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(95, 23);
			this->buttonConnect->TabIndex = 0;
			this->buttonConnect->Text = L"Подключиться";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MainWindow::buttonConnect_Click);
			// 
			// buttonSend
			// 
			this->buttonSend->Location = System::Drawing::Point(492, 274);
			this->buttonSend->Margin = System::Windows::Forms::Padding(8);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(75, 23);
			this->buttonSend->TabIndex = 1;
			this->buttonSend->Text = L"Отправить";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MainWindow::buttonSend_Click);
			// 
			// textBoxPath
			// 
			this->textBoxPath->Location = System::Drawing::Point(123, 202);
			this->textBoxPath->Margin = System::Windows::Forms::Padding(8);
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(444, 20);
			this->textBoxPath->TabIndex = 3;
			// 
			// textBoxData
			// 
			this->textBoxData->Location = System::Drawing::Point(123, 238);
			this->textBoxData->Margin = System::Windows::Forms::Padding(8);
			this->textBoxData->Name = L"textBoxData";
			this->textBoxData->Size = System::Drawing::Size(444, 20);
			this->textBoxData->TabIndex = 4;
			// 
			// LabelAdress
			// 
			this->LabelAdress->AutoSize = true;
			this->LabelAdress->Location = System::Drawing::Point(17, 62);
			this->LabelAdress->Margin = System::Windows::Forms::Padding(8, 8, 0, 0);
			this->LabelAdress->Name = L"LabelAdress";
			this->LabelAdress->Size = System::Drawing::Size(98, 13);
			this->LabelAdress->TabIndex = 5;
			this->LabelAdress->Text = L"IP адрес сервера:";
			// 
			// labelPath
			// 
			this->labelPath->AutoSize = true;
			this->labelPath->Location = System::Drawing::Point(17, 205);
			this->labelPath->Margin = System::Windows::Forms::Padding(8, 8, 0, 0);
			this->labelPath->Name = L"labelPath";
			this->labelPath->Size = System::Drawing::Size(67, 13);
			this->labelPath->TabIndex = 6;
			this->labelPath->Text = L"Имя файла:";
			// 
			// labelData
			// 
			this->labelData->AutoSize = true;
			this->labelData->Location = System::Drawing::Point(17, 241);
			this->labelData->Margin = System::Windows::Forms::Padding(8, 8, 0, 0);
			this->labelData->Name = L"labelData";
			this->labelData->Size = System::Drawing::Size(68, 13);
			this->labelData->TabIndex = 7;
			this->labelData->Text = L"Сообщение:";
			// 
			// labelPort
			// 
			this->labelPort->AutoSize = true;
			this->labelPort->Location = System::Drawing::Point(429, 62);
			this->labelPort->Margin = System::Windows::Forms::Padding(8, 8, 0, 0);
			this->labelPort->Name = L"labelPort";
			this->labelPort->Size = System::Drawing::Size(35, 13);
			this->labelPort->TabIndex = 10;
			this->labelPort->Text = L"Порт:";
			// 
			// menuTop
			// 
			this->menuTop->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutProgrammToolStripMenuItem });
			this->menuTop->Location = System::Drawing::Point(0, 0);
			this->menuTop->Name = L"menuTop";
			this->menuTop->Size = System::Drawing::Size(584, 24);
			this->menuTop->TabIndex = 11;
			this->menuTop->Text = L"menuStrip1";
			// 
			// aboutProgrammToolStripMenuItem
			// 
			this->aboutProgrammToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->aboutProgrammToolStripMenuItem->Name = L"aboutProgrammToolStripMenuItem";
			this->aboutProgrammToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->aboutProgrammToolStripMenuItem->Text = L"О программе";
			this->aboutProgrammToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::aboutProgrammToolStripMenuItem_Click);
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(123, 59);
			this->textBoxIP->Margin = System::Windows::Forms::Padding(8);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(290, 20);
			this->textBoxIP->TabIndex = 12;
			// 
			// textBoxPort
			// 
			this->textBoxPort->Location = System::Drawing::Point(472, 59);
			this->textBoxPort->Margin = System::Windows::Forms::Padding(8);
			this->textBoxPort->Name = L"textBoxPort";
			this->textBoxPort->Size = System::Drawing::Size(95, 20);
			this->textBoxPort->TabIndex = 13;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->textBoxPort);
			this->Controls->Add(this->textBoxIP);
			this->Controls->Add(this->labelPort);
			this->Controls->Add(this->labelData);
			this->Controls->Add(this->labelPath);
			this->Controls->Add(this->LabelAdress);
			this->Controls->Add(this->textBoxData);
			this->Controls->Add(this->textBoxPath);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->menuTop);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuTop;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Клиент";
			this->menuTop->ResumeLayout(false);
			this->menuTop->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void aboutProgrammToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSend_Click(System::Object^ sender, System::EventArgs^ e);
};
}
