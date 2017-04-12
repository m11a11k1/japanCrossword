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
	
		double checkResult(kurs_l_t1::Drawing^ box);						//функци€ проверки 
		void drawCell(int x, int y, int rectangleSize);						//функци€ заполнени€ €чейки
		int** tableLeftSet();												//подсчет заполненых  €чеек по горизонтали
		int** tableTopSet();												//подсчет заполненых  €чеек по вертикали
		int colorIndex(int X, int Y, kurs_l_t1::Drawing^ box);				//функци€ возвращени€ состо€ни€ €чейки дл€ текущей таблицы(заполнена, точно пуста€, предположительно пуста€ )
		int getGridHeight();
		int getGridWidth();
		Byte **getExampleGrid();
		void clear ();
	};
}
