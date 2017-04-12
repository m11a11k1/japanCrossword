#include "stdafx.h"
#include "bmp.h"

BYTE* LoadBMP(int* width, int* height, long* size, LPCTSTR bmpfile)
{
	BITMAPFILEHEADER bmpheader;                       // объявление bmp структур
	BITMAPINFOHEADER bmpinfo;
	
	DWORD bytesread;                                // количество прочитанных байт
	
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ,               // открытие существующего файла для чтения
		NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	
	if (NULL == file)
	{
		return NULL;				//если невозможно открыть файл - return
	}

	
	if (ReadFile(file, &bmpheader, sizeof (BITMAPFILEHEADER), &bytesread, NULL) == false)      //прочитать заголовок файла (описание его свойств)
	{
		CloseHandle(file);
		return NULL;												//если не удалось - return
	}

	

	if (ReadFile(file, &bmpinfo, sizeof (BITMAPINFOHEADER), &bytesread, NULL) == false)        //прочитать инфо из файла
	{
		CloseHandle(file);
		return NULL;					//если нне удалось - return
	}

	
	if (bmpheader.bfType != 'MB')    // проверка является ли файл bmp
	{
		CloseHandle(file);
		fprintf(stderr, "File is not BMP image!\n");			//вывести инфо в поток ошибок если нет
		return NULL;								//если не удалось - return
	}

	
	*width = bmpinfo.biWidth;           // получение размеров изображения
	*height = abs(bmpinfo.biHeight);

	
	if (bmpinfo.biCompression != BI_RGB)   // проверка является ли файл не сжатым bmp
 	{
		fprintf(stderr, "BMP is compressed!\n");
		CloseHandle(file);
		return NULL;			//если не удалось - return
	}

	if (bmpinfo.biBitCount != 24)     	// является ли это 24-битным bmp
	{
		CloseHandle(file);
		fprintf(stderr, "BMP is not 24 bit!\n");
		return NULL;
	}


	
	*size = bmpheader.bfSize - bmpheader.bfOffBits;             // создать массив для чтения собственно изображения
	BYTE* Buffer = new BYTE[*size];
	
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);           // перемещаем файловый указатель на начало изображения
		printf("BMP is loaded!\n\n");
	
	
	if (ReadFile(file, Buffer, *size, &bytesread, NULL) == false)          // прочитать собственно изображение
	{
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}		

	CloseHandle(file);              // если все удалось закрыть файл


	return Buffer;
}

