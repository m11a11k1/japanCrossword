#pragma once
#include "Drawing.h"

namespace kurs_l_t1
{
	ref class LogicalLevel
	{
		Byte **currentGrid;
		Byte **exampleGrid;
		int gridHeight, gridWidth;
	public:
		LogicalLevel(int gridHeight, int gridWidth);
		~LogicalLevel();
	
		double checkResult(kurs_l_t1::Drawing^ box);						//������� �������� 
		void drawCell(int x, int y, int rectangleSize);						//������� ���������� ������
		int** tableLeftSet();												//������� ����������  ����� �� �����������
		int** tableTopSet();												//������� ����������  ����� �� ���������
		int colorIndex(int X, int Y, kurs_l_t1::Drawing^ box);				//������� ����������� ��������� ������ ��� ������� �������(���������, ����� ������, ���������������� ������ )
		int getGridHeight();
		int getGridWidth();
		Byte **getExampleGrid();
		void clear ();
	};
}
