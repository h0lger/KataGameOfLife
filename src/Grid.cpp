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

//Expose pointer to cell array
Cell ** Grid::GetCells()
{
	return _cellArrPtr;
}

//Simulate next generataion of cells
void Grid::NextGeneration()
{	
	//Clone existing state before we manipulate
	Cell **clone = CloneArr();	
	unsigned short nAlive = 0; //Alive neigbours
	unsigned short nDead = 0; //Dead neighbours

	//Loop every cell
	for (unsigned short r = 0; r < _arrSize; r++) //rows
	{
		for (unsigned short c = 0; c < _arrSize; c++) //cells
		{
			nAlive = CountNeighbours(Alive, r, c, clone);

			//For all living cells
			if (_cellArrPtr[r][c].IsAlive())
			{				
				//Rule 1 (underpopulation)			
				//Rule 2 (overcrowdning)
				if (nAlive < 2 || nAlive > 3)
					_cellArrPtr[r][c].SetDead();				
				//Rule 3 (2 or 3 live neighbours lives on)
				// No logic needed...
			}			
			else //For all dead cells
			{
				//Rule 4 (3 live neighbours becomes alive)
				if (nAlive == 3)
					_cellArrPtr[r][c].SetAlive();
			}			
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
	Cell *tmpCellArrPtr = new Cell[N_ARR_SIZE];

	//Figure out neighbours in row above
	if (r > 0)
	{
		AddNeighbour(r - 1, c, false, countPtr, tmpCellArrPtr, cellArrPtr);
	}
	//Figure out neighbours on the same row
	AddNeighbour(r, c, true, countPtr, tmpCellArrPtr, cellArrPtr);
	//Figure out neighbours in row below
	if (r < _arrSize - 1)
		AddNeighbour(r + 1, c, false, countPtr, tmpCellArrPtr, cellArrPtr);

	return tmpCellArrPtr;
}

void Grid::AddNeighbour(unsigned short r, unsigned short c, bool skipCEqual, unsigned short *countPtr, Cell *tmpCellArrPtr, Cell **cellArrPtr)
{	
	//left cell
	if (c > 0)
		tmpCellArrPtr[(++*countPtr) - 1] = cellArrPtr[r][c - 1];
	//To avoid current cell value
	if (!skipCEqual)
		tmpCellArrPtr[(++*countPtr) - 1] = cellArrPtr[r][c];
	//right cell
	if (c < (_arrSize - 1))
		tmpCellArrPtr[(++*countPtr) - 1] = cellArrPtr[r][c + 1];

	
}

unsigned short Grid::CountNeighbours(CellState cState, unsigned short r, unsigned short c, Cell **cellArrPtr)
{
	Cell *ne;
	unsigned short nCells = 0; //Number of neighbours
	unsigned short count = 0; // Number of neighbours (cell state)

	//Fetch all neighbours, could be at most 8
	ne = GetNeighbours(r, c, cellArrPtr, &nCells);

	for (size_t i = 0; i < nCells; i++)
	{
		if (cState == Alive && ne[i].IsAlive())
			count++;
		else if (cState == Dead && !ne[i].IsAlive())
			count++;
	}

	return count;
}