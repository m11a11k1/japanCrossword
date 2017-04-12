#include "stdafx.h"
#include "LogicalLevel.h"

using namespace System;
using namespace System::Drawing;
kurs_l_t1::LogicalLevel::LogicalLevel(int gridHeight, int gridWidth)
{
	this->gridHeight=gridHeight;
	this->gridWidth=gridWidth;
			
	exampleGrid=new Byte*[gridHeight];
	currentGrid=new Byte*[gridHeight];
	for (int i = 0; i < gridHeight; i++)
	{
		exampleGrid[i]=new Byte[gridWidth];
		currentGrid[i]=new Byte[gridWidth];
	}
	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			currentGrid[i][j]=0;
			exampleGrid[i][j]=0;
		}
	}
}
kurs_l_t1::LogicalLevel::~LogicalLevel()
{
	for (int i = 0; i < gridHeight; i++)
	{
		delete(exampleGrid[i]);
		delete(currentGrid[i]);
	}
	delete(exampleGrid);
	delete(currentGrid);
}

double kurs_l_t1::LogicalLevel::checkResult(kurs_l_t1::Drawing^ box)
{
	int summary=0;														//���������� ��������� ����������� �����
	for(int i=0;i<gridHeight;i++)																						
		for(int j=0;j<gridWidth;j++)
		{
			currentGrid[i][j]%=3;					//�������� ��������� ������ (0-���������������� �� ���������, 1-���������, 2-����� �� ���������)
			if (currentGrid[i][j]%2==exampleGrid[i][j]) summary++;		//���� ��������� ����� � ���������� � ������� �������� ���������											
			else
			{
				box->drawCell(j*box->getGridSize()*2,i*box->getGridSize()*2,box->getGridSize(),Color::Blue);  //����� ��������� ����� ����� ������
				currentGrid[i][j]=0;
			}
		}
	return (double)summary/(double)(gridHeight*gridWidth);				//������� ������������ ����������
}

void kurs_l_t1::LogicalLevel::drawCell(int x, int y, int rectangleSize)
{												
	currentGrid[y/(rectangleSize*2)][x/(rectangleSize*2)]++;				//�������� ��������� ������ �� ��������� ( ���������������� �� ��������� -> ��������� -> ����� �� ���������)
																												//    ^_____________________________________________________/
}

int** kurs_l_t1::LogicalLevel::tableLeftSet()								//��������� ������ ��� ����� �������
{
	int **leftTable=new int* [gridHeight];
	for (int i=0;i<gridHeight;i++)
		leftTable[i]= new int [gridWidth/2+1];								//gridWidth/2 �.�. ��� ����������� ��������� ���������� ��������(�.�. ����� 1 - �����������)
	for (int i=0;i<gridHeight;i++)
		for(int j=0;j<gridWidth/2;j++)					 
			leftTable[i][j]=0;

	for (int i=0;i<gridHeight;i++)											//������� ����������� ��� � ������ ������
	{
		bool isSet=false;
		int currentTableCell=0;
		for(int j=0;j<gridWidth;j++)					
			if(exampleGrid[i][j]==1)										//���� ��� ����������� ���� ����������� ���������� ����� � ������� �����
			{ 
				isSet=true; 
				leftTable[i][currentTableCell]++;
			}		
			else 
				if (isSet)																	//���� �������������, � �� ����� ���� ����������� - ��������� � ��������� ����
				{
					currentTableCell++;
					isSet=false;															//� �������� ��� ������� �������������
				}					
	}
	return leftTable;
}

int** kurs_l_t1::LogicalLevel::tableTopSet()								//��������� ������ ��� ������� �������
{
	int **topTable=new int* [gridHeight/2+1];
	for (int i=0;i<gridHeight/2+1;i++)										//gridHeight/2 �.�. ��� ����������� ��������� ���������� �����(�.�. ����� 1 - �����������)
		topTable[i]= new int [gridWidth];				 
	for (int i=0;i<gridHeight/2+1;i++)				 
		for(int j=0;j<gridWidth;j++)					 
			topTable[i][j]=0;									

	for (int i=0;i<gridWidth;i++)
	{
		bool isSet=false;
		int currentSet=0;
		int currentTopTableCell=0;
		for (int j=0;j<gridHeight;j++)										//�� ������� �������
		{
			if (exampleGrid[j][i]==1)										//������� ���������� ����������� � ������� �����
			{
				isSet=true;
				currentSet++;
			}
			else
				if(isSet)													//���� ����� ���������, ��������� ���������� � ��������� � ���������
				{
					isSet=false;
					topTable[currentTopTableCell][i]=currentSet;
					currentSet=0;
					currentTopTableCell++;
				}
			if (j==gridHeight-1)										//���� ��������� ����������� - ������� �� �� �����
			{
				isSet=false;
				topTable[currentTopTableCell][i]=currentSet;
				currentSet=0;
				currentTopTableCell++;
			}
		}
	}
	return topTable;
}

int kurs_l_t1::LogicalLevel::colorIndex(int X, int Y, kurs_l_t1::Drawing^ box)				//������� ������� ���������� �������� ������(���������, ����� ������, ���������������� ������ )
{
	return currentGrid[Y/(box->getGridSize()*2)][X/(box->getGridSize()*2)]%3;
}

int kurs_l_t1::LogicalLevel::getGridHeight()
{
	return gridHeight;
}

int kurs_l_t1::LogicalLevel::getGridWidth()
{
	return gridWidth;
}

Byte **kurs_l_t1::LogicalLevel::getExampleGrid()
{
	return exampleGrid;
}

void kurs_l_t1::LogicalLevel::clear()
{
	for (int i = 0; i < gridHeight; i++)
	{
		for (int j = 0; j < gridWidth; j++)
		{
			currentGrid[i][j]=0;
			exampleGrid[i][j]=0;
		}
	}
}