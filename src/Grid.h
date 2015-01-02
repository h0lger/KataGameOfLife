#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <iostream>

using namespace std;
#define DEFAULT_GRID_SIZE 40
#define N_ARR_SIZE 8 //Max number of neighbours

class Grid
{
public:
	Grid();	
	~Grid();
	
	void NextGeneration(); //Perform next gen
	friend ostream& operator<<(ostream& output, const Grid& G);
	void InitGrid();
	Cell ** GetCells();
	unsigned short ArrSize();

private:
	Cell **_cellArrPtr;
	unsigned short _arrSize;
	//Clone cell array
	Cell ** CloneArr();
	Cell *GetNeighbours(unsigned short r, unsigned short c, Cell **cellArrPtr, unsigned short *countPtr);
	void AddNeighbour(unsigned short r, unsigned short c, bool skipCEqual, unsigned short *countPtr, Cell *tmpCellArrPtr, Cell **cellArrPtr);
	unsigned short CountNeighbours(CellState cState, unsigned short r, unsigned short c, Cell **cellArrPtr);
};


#endif