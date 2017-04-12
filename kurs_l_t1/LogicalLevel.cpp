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
	int summary=0;														//количество правильно заполненных ячеек
	for(int i=0;i<gridHeight;i++)																						
		for(int j=0;j<gridWidth;j++)
		{
			currentGrid[i][j]%=3;					//получить состояние ячейки (0-предположительно не заполнена, 1-заполнена, 2-точно не заполнена)
			if (currentGrid[i][j]%2==exampleGrid[i][j]) summary++;		//если состояния ячеек в правильной и текущей таблицах совпадают											
			else
			{
				box->drawCell(j*box->getGridSize()*2,i*box->getGridSize()*2,box->getGridSize(),Color::Blue);  //иначе заполнить ячеку синим цветом
				currentGrid[i][j]=0;
			}
		}
	return (double)summary/(double)(gridHeight*gridWidth);				//процент правильности заполнения
}

void kurs_l_t1::LogicalLevel::drawCell(int x, int y, int rectangleSize)
{												
	currentGrid[y/(rectangleSize*2)][x/(rectangleSize*2)]++;				//изменить состояние ячейки на следующее ( предположительно не заполнена -> заполнена -> точно не заполнена)
																												//    ^_____________________________________________________/
}

int** kurs_l_t1::LogicalLevel::tableLeftSet()								//посчитать данные для левой таблицы
{
	int **leftTable=new int* [gridHeight];
	for (int i=0;i<gridHeight;i++)
		leftTable[i]= new int [gridWidth/2+1];								//gridWidth/2 т.к. это максимально возможное количество столбцов(т.е. через 1 - закрашенные)
	for (int i=0;i<gridHeight;i++)
		for(int j=0;j<gridWidth/2;j++)					 
			leftTable[i][j]=0;

	for (int i=0;i<gridHeight;i++)											//подсчет непрерывных зон в каждой строке
	{
		bool isSet=false;
		int currentTableCell=0;
		for(int j=0;j<gridWidth;j++)					
			if(exampleGrid[i][j]==1)										//если это закрашенная зона увеличиваем количество ячеек в текущей пачке
			{ 
				isSet=true; 
				leftTable[i][currentTableCell]++;
			}		
			else 
				if (isSet)																	//если незакрашенная, а до этого была закрашенная - переходим к следующей зоне
				{
					currentTableCell++;
					isSet=false;															//и помечаем что текущая незакрашенная
				}					
	}
	return leftTable;
}

int** kurs_l_t1::LogicalLevel::tableTopSet()								//посчитать данные для верхней таблицы
{
	int **topTable=new int* [gridHeight/2+1];
	for (int i=0;i<gridHeight/2+1;i++)										//gridHeight/2 т.к. это максимально возможное количество строк(т.е. через 1 - закрашенные)
		topTable[i]= new int [gridWidth];				 
	for (int i=0;i<gridHeight/2+1;i++)				 
		for(int j=0;j<gridWidth;j++)					 
			topTable[i][j]=0;									

	for (int i=0;i<gridWidth;i++)
	{
		bool isSet=false;
		int currentSet=0;
		int currentTopTableCell=0;
		for (int j=0;j<gridHeight;j++)										//по каждому столбцу
		{
			if (exampleGrid[j][i]==1)										//считаем количество закрашенных в текущей пачке
			{
				isSet=true;
				currentSet++;
			}
			else
				if(isSet)													//если пачка кончилась, сохраняем количество и переходим к следующей
				{
					isSet=false;
					topTable[currentTopTableCell][i]=currentSet;
					currentSet=0;
					currentTopTableCell++;
				}
			if (j==gridHeight-1)										//если кончилось изображение - сделать то же самое
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

int kurs_l_t1::LogicalLevel::colorIndex(int X, int Y, kurs_l_t1::Drawing^ box)				//вернуть текущее логическое значение ячейки(заполнена, точно пустая, предположительно пустая )
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