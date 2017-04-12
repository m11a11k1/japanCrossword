#pragma once
#include "BMP.h"
#include "gamefile.h"
namespace kurs_l_t1
{
ref class BmpFile :
public GameFile
{
public:
	BmpFile(char *filename):GameFile(filename){}	

	virtual void Process(System::Windows::Forms::IWin32Window^ window , System::Byte **exampleGrid, int gridHeight, int gridWidth ) override //��������� ����� bmp
	{
		long imgSize = 0;                                                                         //������ ����������� � ������
		int imgWidth = 0, imgHeight = 0;															  //������ � ������ ����������� � �������� 
		BYTE *img=LoadBMP(&imgWidth,&imgHeight,&imgSize,GetWC(filename));					  //����� ������� �������� �����������
		BYTE** example=new BYTE*[imgHeight];												  //��������� ������ ��� ���������� ������� ����������������� �����������
		int pixelsInCellY=imgHeight/gridHeight;												  //���������� �������� �� 1 ������ ��������� �����������
		int pixelsInCellX=imgWidth/gridWidth;
		if (imgSize == 0 || imgWidth*imgHeight*3 != imgSize)
		{
			System::Windows::Forms:: MessageBox::Show(window,System::Convert::ToString("Error opening file!!!"));
			return;
		}
		for(int i=0;i<imgHeight;i++)														  //��������� ������
			example[i]=new BYTE[imgWidth];

		for (int i=0;i<imgHeight-1;i++)														  //�������� ��������� �����������
			for (int j=0;j<imgWidth-1;j++)
				example[i][j]=((float) img [i*imgWidth*3+j*3]*0.1 + (float) img [i*imgWidth*3+j*3+1]*0.59 + (float) img [i*imgWidth*3+j*3+2]*0.31) < 128 ? 1 : 0;   
														//���� ������� ������������ � ������� ������ ������ 128 ������� ��������� ������, ����� - ���
		for(int i=0;i<gridHeight;i++)
			for(int j=0;j<gridWidth;j++)
			{
				int darkKoef=0;
				for (int k=0;k<pixelsInCellY-1;k++)
					for (int t=0;t<pixelsInCellX-1;t++)
						darkKoef+=example[i*pixelsInCellY+k][j*pixelsInCellX+t];			  //����� ����������� �� �������������� �� ���������� �� � �������� �������� � ������� ���������� ������ ��������, 
				exampleGrid[gridHeight-i-1][j]=(darkKoef>pixelsInCellX*pixelsInCellY/2?1:0);  //���� �� ������ �������� �� ���������� ���� �������� ������ ��������� �����������
			}					
	}
};
}