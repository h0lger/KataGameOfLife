#include "Grid.h"

Grid::Grid()
{
	_arrSize = DEFAULT_GRID_SIZE;
	InitGrid();	
}
Grid::~Grid(void)
{
	delete _cellArrPtr;
}

//Metoder
void Grid::InitGrid()
{
	_cellArrPtr = new Cell*[_arrSize]; //multidimensionell array [rad][cell]
	for (size_t i = 0; i < _arrSize; i++)
	{
		_cellArrPtr[i] = new Cell[_arrSize];
	}
}

ostream& operator<<(ostream &output, const Grid &G)
{
	for (size_t r = 0; r < G._arrSize; r++)
	{
		Cell *rCell = G._cellArrPtr[r];
		for (size_t c = 0; c < G._arrSize; c++)
		{
			if (rCell[c].IsAlive())
				output << "*";
			else
				output << ".";
		}
		output << "\n"; //För varje ny rad
	}
	return output;
}

void Grid::NextGeneration()
{
	_cellArrPtr[1][1].SetAlive();
}