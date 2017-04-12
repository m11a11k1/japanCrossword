#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
namespace kurs_l_t1
{
ref class Drawing
{
	Graphics^ g;
	PictureBox^ pictureBox1;
	int gridSize;
	DataGridView^ dataGridView1;
	DataGridView^ dataGridView2;
public:
	Drawing(PictureBox^ pictureBox1, int gridSize, DataGridView^ dataGridView1, DataGridView^ dataGridView2);

	void clearPictureBox();																	//очистка поля при загрузке нового изображения
	void drawCell(int x, int y, int rectangleSize, System::Drawing::Color a);				//функция рисования клетки
	void drawGrid();																		//функция рисования сетки
	int getGridSize();	
	void fillTopSet(int** topTable, int gridHeight, int gridWidth);							//функция заливки верхней таблицы
	void fillLeftSet(int** leftTable, int gridHeight, int gridWidth);						//функция заливки левой таблицы
};	
}
