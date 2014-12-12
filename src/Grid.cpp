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
	_cellArrPtr = new Cell*[_arrSize]; //multi-dimensional array [row][cell]
	for (size_t i = 0; i < _arrSize; i++)
	{
		_cellArrPtr[i] = new Cell[_arrSize];
	}
}

ostream& operator<<(ostream &output, const Grid &G)
{
	for (size_t r = 0; r < G._arrSize; r++) //rows
	{
		Cell *rCell = G._cellArrPtr[r];
		for (size_t c = 0; c < G._arrSize; c++) //cells
		{
			if (rCell[c].IsAlive())
				output << "*";
			else
				output << ".";
		}
		output << "\n"; //For every new row
	}
	return output;
}

void Grid::NextGeneration()
{	
	Cell **clone = CloneArr();
	for (size_t r = 0; r < _arrSize; r++) //rows
	{
		for (size_t c = 0; c < _arrSize; c++) //cells
		{
			//Rule 1 (underpopulation)
			//TODO
		}
	}

	delete clone;
}

Cell ** Grid::CloneArr()
{
	//Neccessary for keeping history of -1 generation
	Cell **tmpCPtr = new Cell*[_arrSize];

	for (size_t r = 0; r < _arrSize; r++) //rows
	{
		Cell *rCell = _cellArrPtr[r];
		tmpCPtr[r] = new Cell[_arrSize];
		Cell *rCellClone = tmpCPtr[r];
		for (size_t c = 0; c < _arrSize; c++) //cells
		{
			rCellClone[c] = rCell[c];
		}
	}

	return tmpCPtr;
}