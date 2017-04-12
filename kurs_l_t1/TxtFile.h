#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "gamefile.h"
#include <stdio.h>

namespace kurs_l_t1 
{
	ref class TxtFile : public GameFile
	{
	public:
		TxtFile(char *filename):GameFile(filename) {}
	
		void virtual Process(System::Windows::Forms::IWin32Window^ window ,System::Byte **exampleGrid, int gridHeight, int gridWidth) override
		{
			
			FILE* input=fopen(filename,"r");
			if (!input) 
			{
				System::Windows::Forms:: MessageBox::Show(window,System::Convert::ToString("Error opening file!!!"));
				return;
			}	
			for (int i=0;i<gridHeight;i++)
				for (int j=0;j<gridWidth;j++)
					fscanf(input,"%d",&exampleGrid[i][j]);
		}
	};
}