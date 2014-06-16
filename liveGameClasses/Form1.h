#pragma once

#include "Field.h"

namespace liveGameClasses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Graphics  ^gr;
		BufferedGraphicsContext ^st;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
			 BufferedGraphics ^buff;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
			 Field^ f1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
			 bool fieldInit;
	public:
		Form1(void)
		{
			InitializeComponent();
			
			st = BufferedGraphicsManager::Current;
			gr = this->CreateGraphics();
			System::Drawing::Rectangle rect(0,0,600,600);
			buff = st->Allocate(gr, rect);

			buff->Graphics->Clear(Color::WhiteSmoke);
			buff->Render();
			fieldInit = false;
			f1 = gcnew Field();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start/Stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(100, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 26);
			this->button2->TabIndex = 1;
			this->button2->Text = L"NextStep";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(202, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 26);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Random";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(62, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(29, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"30";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(114, 13);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(29, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"30";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Поле: m - ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(95, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"n -";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(303, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 26);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Clean";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(149, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(27, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"ok";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(403, -2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(183, 107);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(9, 85);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(71, 17);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->Text = L"Neumann";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(9, 62);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(52, 17);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->Text = L"Mvon";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(9, 39);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(55, 17);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Moore";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 418);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled = !timer1->Enabled;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 f1->nextStep();
				 f1->drawCells(buff);
				 buff->Render();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 f1->nextStep();
				 f1->drawCells(buff);
				 buff->Render();
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				f1->random();
				f1->drawCells(buff);
				buff->Render();
		 }
private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(fieldInit)
			 {
				f1->mouseClick(e->X, e->Y);
				f1->drawCells(buff);
				buff->Render();
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				f1->clean();
				f1->drawCells(buff);
				buff->Render();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 fieldInit = true;
			 if(radioButton1->Checked)
				f1->init(Convert::ToUInt32(textBox2->Text), Convert::ToUInt32(textBox1->Text), 300, Moore);
			 else
			 {
				 if(radioButton2->Checked)
					f1->init(Convert::ToUInt32(textBox2->Text), Convert::ToUInt32(textBox1->Text), 300, Mvon);
				 else
					if(radioButton3->Checked)
						f1->init(Convert::ToUInt32(textBox2->Text), Convert::ToUInt32(textBox1->Text), 300, Neumann);
			 }
			 groupBox1->Visible = false;
			 button1->Enabled = true;
			 button2->Enabled = true;
			 button3->Enabled = true;
			 button4->Enabled = true;

			 f1->clean();
			 f1->drawCells(buff);
			 buff->Render();
		 }
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
			 button1->Enabled = false;
			 button2->Enabled = false;
			 button3->Enabled = false;
			 button4->Enabled = false;

		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

