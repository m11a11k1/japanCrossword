#pragma once																				
#include "GameFile.h"
#include "TxtFile.h"
#include "BmpFile.h"
#include "Drawing.h"
#include "LogicalLevel.h"

namespace kurs_l_t1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// ������ ��� Form1
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//	
			draw = gcnew Drawing(this->pictureBox1, 6, this->dataGridView1, this->dataGridView2);		//�������� ������� ��� �������� ���������
			logic = gcnew LogicalLevel(pictureBox1->Size.Height/(draw->getGridSize()*2)+1,pictureBox1->Size.Width/(draw->getGridSize()*2)+1);		
																							//�������� ������� ��� ������ � �������
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 LogicalLevel^ logic;
			 kurs_l_t1::Drawing^ draw;
			 GameFile^ inputFile;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;


	protected: 

	protected: 







	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(138, 120);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1065, 430);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeight = 12;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(138, 2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 12;
			this->dataGridView1->Size = System::Drawing::Size(1094, 112);
			this->dataGridView1->TabIndex = 1;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->ColumnHeadersHeight = 12;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->Location = System::Drawing::Point(2, 120);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 12;
			this->dataGridView2->Size = System::Drawing::Size(130, 461);
			this->dataGridView2->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(2, 2);
			this->textBox1->MaxLength = 256;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(130, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"*.txt or 24-bit *.bmp";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(2, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(2, 90);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Check";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(138, 553);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1086, 40);
			this->label1->TabIndex = 6;
			this->label1->Text = resources->GetString(L"label1.Text");
			
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1240, 594);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Japan Crossword";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, MouseEventArgs^  e)			//����� ��������� ������� �� ���� ��� ���������
			 {			
				 int colorIndex=0;
				 if (e->Button==System::Windows::Forms::MouseButtons::Left)								//��� ������� �� ���
					 drawCell(e->X, e->Y, draw->getGridSize(), ((colorIndex=logic->colorIndex(e->X, e->Y, draw))==0) ? Color::Black:(colorIndex==1) ? Color::Yellow:Color::GhostWhite);		//���������� ������ �� ��������� �����������(� ��� ����� ��� ���� ������ ����) ���������� ����� � ���������
				 else if(e->Button==System::Windows::Forms::MouseButtons::Right)						//��� ������� �� ���
					 draw->drawGrid();																	//���������� �����
			 }

			 System::Void drawCell(int x, int y, int rectangleSize, System::Drawing::Color a)
			 {			 
				 logic->drawCell(x,y,rectangleSize);													//��������� ������ � ������� � �������
				 draw->drawCell(x,y,rectangleSize,a);													//� ��������� ���������
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {				//����� ��������� ������� ������ Load
				 String^ tfilename;
				 String^ txt(".txt");
				 String^ bmp(".bmp");
				 char* filename;
				 bool isTxt=true;
				 if (System::String::IsNullOrWhiteSpace(textBox1->Text->ToString())==false)				//�������� �� �������� ������
				 {
					 tfilename=textBox1->Text->ToString();				 
					 if (!tfilename->EndsWith(txt)&&!tfilename->EndsWith(bmp))							//�������� �� ������������ ��������� ������
						 MessageBox::Show(this,Convert::ToString("Wrong type!!! Only *.txt or 24-bit *.bmp!"));
					 else
					 {						 
						 logic->clear();
						 filename = (char*)(void*)Marshal::StringToHGlobalAnsi(tfilename);				//�������������� System::String � char*
						 if (tfilename->EndsWith(bmp)) isTxt=false;										//�������� ����� ������ ���� ��������
						 if (isTxt) inputFile=gcnew TxtFile(filename);									//�������� ������� � ���� ������
						 else inputFile=gcnew BmpFile(filename);
						 inputFile->Process(this,logic->getExampleGrid(),logic->getGridHeight(),logic->getGridWidth());		//��������� ����� �����
						 draw->fillLeftSet(logic->tableLeftSet(),logic->getGridHeight(),logic->getGridWidth());				//������� �����
						 draw->fillTopSet(logic->tableTopSet(),logic->getGridHeight(),logic->getGridWidth());				//� ������� ������
						 draw->clearPictureBox();																			//������� ���� ��� ��������� �� ������ ��������
						 
					 }
				 }
				 else
					 MessageBox::Show(this,Convert::ToString("Empty filename!!!"));
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {				///����� ��������� ������� �� ������ Check
			MessageBox::Show(this,Convert::ToString(logic->checkResult(draw)*100)+Convert::ToString("%"),Convert::ToString("Result"));			//������� ��������� ��������
		 }
};
}

