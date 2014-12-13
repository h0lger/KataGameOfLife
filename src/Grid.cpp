#include "Grid.h"
#include <vector>

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
	Cell *ne;
	unsigned short *countPtr = (unsigned short *)0;

	for (unsigned short r = 0; r < _arrSize; r++) //rows
	{
		for (unsigned short c = 0; c < _arrSize; c++) //cells
		{
			//Rule 1 (underpopulation)
			ne = GetNeighbours(r, c, clone, countPtr);
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

Cell *Grid::GetNeighbours(unsigned short r, unsigned short c, Cell **cellArrPtr, unsigned short *countPtr)
{
	//Every cell has at maximum 8 neighbours...
	Cell tmpCellArrPtr[N_ARR_SIZE];	

	//Figure out row above
	if (r == 0)
	{
		AddNeighbour(r, c, countPtr, tmpCellArrPtr, cellArrPtr);
	}	

	return tmpCellArrPtr;
}

void Grid::AddNeighbour(unsigned short r, unsigned short c, unsigned short *countPtr, Cell *tmpCellArrPtr, Cell **cellArrPtr)
{
	unsigned short i = (unsigned short)countPtr;
	//left cell
	if (c > 0)
		tmpCellArrPtr[++i] = cellArrPtr[r][c - 1];
	//right cell
	if (c < (DEFAULT_GRID_SIZE - 1))
		tmpCellArrPtr[++i] = cellArrPtr[r][c + 1];
}