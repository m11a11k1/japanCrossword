// kurs_l_t1.cpp: главный файл проекта.
#include "stdafx.h"
#include "Form1.h"

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	System::Windows::Forms::Application::Run(gcnew kurs_l_t1::Form1());
	return 0;
}
