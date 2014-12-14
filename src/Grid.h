#include "Cell.h"
#include <iostream>
using namespace std;

#ifndef GRID_H
#define DEFAULT_GRID_SIZE 20
#define N_ARR_SIZE 8 //Max number of neighbours

class Grid
{
public:
	Grid();	
	~Grid();
	
	void NextGeneration(); //Perform next gen

	friend ostream& operator<<(ostream& output, const Grid& G);

	void InitGrid();

private:
	Cell **_cellArrPtr;
	unsigned short _arrSize;
	Cell ** CloneArr(); //Clone cellArrPtr
	Cell *GetNeighbours(unsigned short r, unsigned short c, Cell **cellArrPtr, unsigned short *countPtr);
	void AddNeighbour(unsigned short r, unsigned short c, bool skipCEqual, unsigned short *countPtr, Cell *tmpCellArrPtr, Cell **cellArrPtr);
	
};




#endif