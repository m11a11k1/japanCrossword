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

	void clearPictureBox();																	//������� ���� ��� �������� ������ �����������
	void drawCell(int x, int y, int rectangleSize, System::Drawing::Color a);				//������� ��������� ������
	void drawGrid();																		//������� ��������� �����
	int getGridSize();	
	void fillTopSet(int** topTable, int gridHeight, int gridWidth);							//������� ������� ������� �������
	void fillLeftSet(int** leftTable, int gridHeight, int gridWidth);						//������� ������� ����� �������
};	
}
