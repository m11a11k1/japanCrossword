#pragma once

namespace kurs_l_t1 
{
	ref class GameFile
	{
	protected: 
		char *filename;
	public:	
		GameFile(char* filename);
		~GameFile();

		const wchar_t* GetWC(const char *c);			//преобразование строки однобайтовых символов в строку двухбайтовых
		virtual void Process(System::Windows::Forms::IWin32Window^ window,System::Byte **exampleGrid, int gridHeight, int gridWidth ) = 0;			
																	//функция обработки файлов будет определена в классах-наследниках
	};
}
