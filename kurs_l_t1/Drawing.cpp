#include "stdafx.h"
#include "Drawing.h"


kurs_l_t1::Drawing::Drawing(PictureBox^ pictureBox1, int gridSize, DataGridView^ dataGridView1, DataGridView^ dataGridView2)
{
	this->gridSize=gridSize;
	this->dataGridView2=dataGridView2;
	this->dataGridView1=dataGridView1;
	this->pictureBox1=pictureBox1;
	this->g=pictureBox1->CreateGraphics();
}

void kurs_l_t1::Drawing::drawCell(int x, int y, int rectangleSize, System::Drawing::Color a)
{			 
	Pen^ p=gcnew Pen(a,rectangleSize);														//создаем новую ручку нужного  цвета и толщины
	g->DrawRectangle(p,x - x%(rectangleSize*2)+3 ,y - y%(rectangleSize*2)+3,rectangleSize,rectangleSize);			//рисуем квадрат с центром в центре клетки
}

void kurs_l_t1::Drawing::drawGrid()			
{
	int tGridSize=gridSize*2;																//размер €чейки в 2 раза большие чем толщина пера дл€ закрашивани€
	Pen^ p=gcnew Pen(System::Drawing::Color::Black);										//создаем ручку дл€ рисовани€ тонких черных линий
	Pen^ widep=gcnew Pen(System::Drawing::Color::Red,3);									//и толстых красных
	for (int i=0;i<pictureBox1->Size.Height;i+=tGridSize)									
		g->DrawLine((i/tGridSize%5==0)?widep:p,0,i,pictureBox1->Size.Width,i);				//рисуем черные линии и каждую 5 - красную
	for (int i=0;i<pictureBox1->Size.Width;i+=tGridSize)
		g->DrawLine((i/tGridSize%5==0)?widep:p,i,0,i,pictureBox1->Size.Height);				//рисуем черные линии и каждую 5 - красную
}

int kurs_l_t1::Drawing::getGridSize()
{
	return gridSize;
}

void kurs_l_t1::Drawing::fillLeftSet(int **leftTable, int gridHeight, int gridWidth)		
{
	int maxWidth=0;
	for (int i=0;i<gridHeight;i++)
	{
		int currentWidth=0;
		for(int j=0;j<gridWidth/2;j++)					 
			if(leftTable[i][j]!=0) currentWidth++;
		if(currentWidth>maxWidth) maxWidth=currentWidth;									//находим максимальную ширину левой таблицы(максимальное количество пачек в строке)
	}
	this->dataGridView2->ColumnCount=maxWidth+1;											//создаем необходимое количество колонок
	this->dataGridView2->RowCount=gridHeight;												//и строк
	for(int i=0;i<gridHeight;i++)		 
		for (int j=0; j<maxWidth; j++)
		{
			this->dataGridView2->Rows[i]->Cells[j]->Value=leftTable[i][j];					//заливаем в таблицу посчитанные данные
			this->dataGridView2->Rows[i]->Height=gridSize*2;								//и задаем размеры €чеек
			this->dataGridView2->Columns[j]->Width=20;
		}
	this->dataGridView2->Columns[maxWidth]->Width=0;										//последн€€ колонка - буферна€ и невидима€
	this->dataGridView2->Font = gcnew System::Drawing::Font("Arial", 7);					//шрифт текста Arial и кегль 7 в €чейках
	this->dataGridView2->Invalidate();														//перерисование таблицы
}

void kurs_l_t1::Drawing::fillTopSet(int **topTable, int gridHeight, int gridWidth)
{
	int maxHeight=0;
	for (int i=0;i<gridWidth;i++)
	{
		int currentHeight=0;
		for(int j=0;j<gridHeight/2+1;j++)					 
			if(topTable[j][i]!=0) currentHeight++;
		if(currentHeight>maxHeight) maxHeight=currentHeight;								//находим максимальную высоту верхней таблицы(максимальное количество пачек в столбце)
	}
	this->dataGridView1->RowCount=maxHeight+1;												//создаем необходимое количество строк
	this->dataGridView1->ColumnCount=gridWidth;												//и колонок
	for(int i=0;i<maxHeight;i++)					 
		for (int j=0; j<gridWidth; j++)
		{
			this->dataGridView1->Rows[i]->Cells[j]->Value=topTable[i][j];					//заливаем в таблицу посчитанные данные
			this->dataGridView1->Rows[i]->Height=gridSize*2;								//и задаем размеры €чеек
			this->dataGridView1->Columns[j]->Width=gridSize*2;
		}
	this->dataGridView1->Rows[maxHeight]->Height=0;											//последн€€ строка - буферна€ и невидима€
	this->dataGridView1->Font = gcnew System::Drawing::Font("Arial", 7);					//шрифт текста Arial и кегль 7 в €чейках
				 
	this->dataGridView1->Invalidate();														//перерисование таблицы
}

void kurs_l_t1 ::Drawing ::clearPictureBox ()
{
	g->Clear(Color::GhostWhite);
}