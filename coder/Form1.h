#pragma once


namespace coder {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::IO;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  originalFile;
	private: System::Windows::Forms::TextBox^  codedFile;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  repeatPassword;
	private: System::Windows::Forms::TextBox^  password;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  openButton;
	private: System::Windows::Forms::Button^  reloadButton;
	private: System::Windows::Forms::Button^  decodeButton;
	private: System::Windows::Forms::Button^  codeButton;
	private: System::Windows::Forms::OpenFileDialog^  Dialog1;
	private: System::ComponentModel::IContainer^  components;

	private: bool openedCoded;
	private: System::Windows::Forms::Timer^  antiBruteForce;
			 int counter;
			 static const int delay = 5 * 1000;
			 int len;
			 int progress;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->originalFile = (gcnew System::Windows::Forms::TextBox());
			this->codedFile = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->repeatPassword = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->reloadButton = (gcnew System::Windows::Forms::Button());
			this->decodeButton = (gcnew System::Windows::Forms::Button());
			this->codeButton = (gcnew System::Windows::Forms::Button());
			this->Dialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->antiBruteForce = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// originalFile
			// 
			this->originalFile->Location = System::Drawing::Point(77, 12);
			this->originalFile->Name = L"originalFile";
			this->originalFile->ReadOnly = true;
			this->originalFile->Size = System::Drawing::Size(227, 20);
			this->originalFile->TabIndex = 0;
			// 
			// codedFile
			// 
			this->codedFile->Location = System::Drawing::Point(77, 38);
			this->codedFile->Name = L"codedFile";
			this->codedFile->ReadOnly = true;
			this->codedFile->Size = System::Drawing::Size(227, 20);
			this->codedFile->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Original file";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Coded file";
			// 
			// repeatPassword
			// 
			this->repeatPassword->Location = System::Drawing::Point(108, 92);
			this->repeatPassword->Name = L"repeatPassword";
			this->repeatPassword->PasswordChar = '*';
			this->repeatPassword->Size = System::Drawing::Size(196, 20);
			this->repeatPassword->TabIndex = 5;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(108, 66);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(196, 20);
			this->password->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Repeat password";
			// 
			// openButton
			// 
			this->openButton->Location = System::Drawing::Point(311, 10);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(75, 23);
			this->openButton->TabIndex = 8;
			this->openButton->Text = L"open";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &Form1::openButton_Click);
			// 
			// reloadButton
			// 
			this->reloadButton->Enabled = false;
			this->reloadButton->Location = System::Drawing::Point(311, 36);
			this->reloadButton->Name = L"reloadButton";
			this->reloadButton->Size = System::Drawing::Size(75, 23);
			this->reloadButton->TabIndex = 9;
			this->reloadButton->Text = L"reload";
			this->reloadButton->UseVisualStyleBackColor = true;
			this->reloadButton->Click += gcnew System::EventHandler(this, &Form1::reloadButton_Click);
			// 
			// decodeButton
			// 
			this->decodeButton->Enabled = false;
			this->decodeButton->Location = System::Drawing::Point(311, 90);
			this->decodeButton->Name = L"decodeButton";
			this->decodeButton->Size = System::Drawing::Size(75, 23);
			this->decodeButton->TabIndex = 11;
			this->decodeButton->Text = L"wait 5 s";
			this->decodeButton->UseVisualStyleBackColor = true;
			this->decodeButton->Click += gcnew System::EventHandler(this, &Form1::decodeButton_Click);
			// 
			// codeButton
			// 
			this->codeButton->Enabled = false;
			this->codeButton->Location = System::Drawing::Point(311, 64);
			this->codeButton->Name = L"codeButton";
			this->codeButton->Size = System::Drawing::Size(75, 23);
			this->codeButton->TabIndex = 10;
			this->codeButton->Text = L"wait 5 s";
			this->codeButton->UseVisualStyleBackColor = true;
			this->codeButton->Click += gcnew System::EventHandler(this, &Form1::codeButton_Click);
			// 
			// Dialog1
			// 
			this->Dialog1->FileName = L"openFileDialog1";
			// 
			// antiBruteForce
			// 
			this->antiBruteForce->Enabled = true;
			this->antiBruteForce->Interval = 1000;
			this->antiBruteForce->Tick += gcnew System::EventHandler(this, &Form1::antiBruteForce_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(392, 124);
			this->Controls->Add(this->decodeButton);
			this->Controls->Add(this->codeButton);
			this->Controls->Add(this->reloadButton);
			this->Controls->Add(this->openButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->repeatPassword);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->codedFile);
			this->Controls->Add(this->originalFile);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: String^ caption(){return gcnew String("Binary coder");}

private: System::Void antiBruteForce_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 counter+=antiBruteForce->Interval;
			 codeButton->Text = "wait " + Convert::ToString((delay-counter)/1000.0) + " s";
			 decodeButton->Text = codeButton->Text;
			 if (counter >= delay) 
			 {
				 codeButton->Text = "code";
				 decodeButton->Text = "decode";
				 antiBruteForce->Enabled=false;
				 codeButton->Enabled=!antiBruteForce->Enabled && originalFile->Text!="";
				 decodeButton->Enabled=!antiBruteForce->Enabled  && codedFile->Text!="";
			 }
		 }

private: void loadPaths()
		 {
			 if (IO::File::Exists(Dialog1->FileName))
			 {
				 if (Dialog1->FileName->Substring(Dialog1->FileName->Length-5,5)==".code") // если открыт закодированный файл
				 {
					 codedFile->Text = Dialog1->FileName;
					 String^ original = Dialog1->FileName->Substring(0,Dialog1->FileName->Length-5);
					 if (IO::File::Exists(original))
						 originalFile->Text = original;
				 }
				 else // иначе если открыт обычный файл
				 {
					 originalFile->Text = Dialog1->FileName;
					 String^ coded = Dialog1->FileName+".code";
					 if (IO::File::Exists(coded))
						 codedFile->Text = coded;
				 }
				 reloadButton->Enabled=true;
				 codeButton->Enabled=!antiBruteForce->Enabled && originalFile->Text!="";
				 decodeButton->Enabled=!antiBruteForce->Enabled  && codedFile->Text!="";
			 }
		 }

private: void openButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // инициализация переменных
			 reloadButton->Enabled=false;
			 codeButton->Enabled=false;
			 decodeButton->Enabled=false;
			 originalFile->Text = "";
			 codedFile->Text = "";
			 // запрос на получение пути к файлу
			 Dialog1->FileName = "";
			 Dialog1->ShowDialog();
			 loadPaths();
		 }

private: System::Void reloadButton_Click(System::Object^  sender, System::EventArgs^  e) { loadPaths(); }

private: System::Void codeButton_Click(System::Object^  sender, System::EventArgs^  e) { code(false); }

private: System::Void decodeButton_Click(System::Object^  sender, System::EventArgs^  e) { code(true); }

private: int code(bool coded)
		 {
			 if (password->Text->Length==0)
				 if (MessageBox::Show("Continue with empty paswword?", "empty password",
				 MessageBoxButtons::YesNo, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1) ==
				 Windows::Forms::DialogResult::No) return -1;
			 if (password->Text!=repeatPassword->Text) 
			 {
				 MessageBox::Show("Passwords must match", "Invalid password",
				 MessageBoxButtons::OK, MessageBoxIcon::Error, MessageBoxDefaultButton::Button1);
				 return -2;
			 }
			 antiBruteForce->Enabled=true;
			 counter = 0;
			 codeButton->Enabled=false;
			 decodeButton->Enabled=false;
			 String^ _what = coded ? codedFile->Text : originalFile->Text;
			 String^ _where = coded ? _what->Substring(0,_what->Length-5) : _what+".code";
			 FileStream^ in = File::Open(_what, FileMode::Open);
			 FileStream^ out = File::Open(_where, FileMode::Create);
			 array<Byte>^ data = gcnew array<Byte>(in->Length);
			 // формирование ключа шифрования
			 String^ s1 = Convert::ToString(password->Text->Length); // числовое выражение длины введённого ключа
			 String^ s2 = Convert::ToString(in->Length); // числовое выражение размера файла
			 array<Byte>^ pass = gcnew array<Byte>(password->Text->Length + s1->Length + s2->Length);
			 for (int i=0; i<pass->Length; i++)
				 if (i<password->Text->Length) pass[i]=password->Text[i]; // введённый пользователем ключ
				 else if (i<password->Text->Length+s1->Length) pass[i]=s1[i - password->Text->Length]; // s1
				 else pass[i]=s2[i - password->Text->Length - s1->Length]; // s2
			 in->Read(data,0,data->Length);
			 progress=0;
			 len=pass->Length-1;
			 code(data,pass); // шифрование массива data ключом pass
			 out->Write(data,0,data->Length);
			 in->Close();
			 out->Close();
			 loadPaths();
		 }

private: array<Byte>^ code(array<Byte>^ a, array<Byte>^ b) // алгоритм шифрования рекурсивный
		 {
			 this->Text = caption() + ": progress - " + Convert::ToString(100*(progress++)/len) + "%";
			 if (b->Length == 1) return a; // выход из рекурсии

			 // циклическое применение xor
			 for (int i=0; i<a->Length; i++)
				 a[i]=a[i]^b[i%b->Length]; 

			 // формируем новый ключ c меньшей длиной
			 array<Byte>^ c = gcnew array<Byte>(b->Length - 1);
			 for (int i=0; i<c->Length; i++)
				 c[i]=b[i]^b[i+1];
			 return code(a,c);
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) { 
			 this->Text = caption(); 
		 }
};}
