// kurs_l_t1.cpp: ������� ���� �������.
#include "stdafx.h"
#include "Form1.h"

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	System::Windows::Forms::Application::Run(gcnew kurs_l_t1::Form1());
	return 0;
}
