#include "stdafx.h"
#include "bmp.h"

BYTE* LoadBMP(int* width, int* height, long* size, LPCTSTR bmpfile)
{
	BITMAPFILEHEADER bmpheader;                       // ���������� bmp ��������
	BITMAPINFOHEADER bmpinfo;
	
	DWORD bytesread;                                // ���������� ����������� ����
	
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ,               // �������� ������������� ����� ��� ������
		NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	
	if (NULL == file)
	{
		return NULL;				//���� ���������� ������� ���� - return
	}

	
	if (ReadFile(file, &bmpheader, sizeof (BITMAPFILEHEADER), &bytesread, NULL) == false)      //��������� ��������� ����� (�������� ��� �������)
	{
		CloseHandle(file);
		return NULL;												//���� �� ������� - return
	}

	

	if (ReadFile(file, &bmpinfo, sizeof (BITMAPINFOHEADER), &bytesread, NULL) == false)        //��������� ���� �� �����
	{
		CloseHandle(file);
		return NULL;					//���� ��� ������� - return
	}

	
	if (bmpheader.bfType != 'MB')    // �������� �������� �� ���� bmp
	{
		CloseHandle(file);
		fprintf(stderr, "File is not BMP image!\n");			//������� ���� � ����� ������ ���� ���
		return NULL;								//���� �� ������� - return
	}

	
	*width = bmpinfo.biWidth;           // ��������� �������� �����������
	*height = abs(bmpinfo.biHeight);

	
	if (bmpinfo.biCompression != BI_RGB)   // �������� �������� �� ���� �� ������ bmp
 	{
		fprintf(stderr, "BMP is compressed!\n");
		CloseHandle(file);
		return NULL;			//���� �� ������� - return
	}

	if (bmpinfo.biBitCount != 24)     	// �������� �� ��� 24-������ bmp
	{
		CloseHandle(file);
		fprintf(stderr, "BMP is not 24 bit!\n");
		return NULL;
	}


	
	*size = bmpheader.bfSize - bmpheader.bfOffBits;             // ������� ������ ��� ������ ���������� �����������
	BYTE* Buffer = new BYTE[*size];
	
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);           // ���������� �������� ��������� �� ������ �����������
		printf("BMP is loaded!\n\n");
	
	
	if (ReadFile(file, Buffer, *size, &bytesread, NULL) == false)          // ��������� ���������� �����������
	{
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}		

	CloseHandle(file);              // ���� ��� ������� ������� ����


	return Buffer;
}

