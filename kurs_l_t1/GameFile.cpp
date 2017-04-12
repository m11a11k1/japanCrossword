#include "stdafx.h"
#include "GameFile.h"
#include <windows.h>


kurs_l_t1::GameFile::GameFile(char *filename)
{
	this->filename=filename;
}

kurs_l_t1::GameFile::~GameFile()
{
	delete this->filename;
}

const wchar_t* kurs_l_t1::GameFile::GetWC(const char *c)
{
	const size_t cSize = strlen(c)+1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs (wc, c, cSize);			//системная функция преобразования строки 1-байтовых символов в строку 2-байтовых символов
	return wc;
}

