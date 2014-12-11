#include "Cell.h"
#include <iostream>
using namespace std;

#ifndef GRID_H
#define DEFAULT_GRID_SIZE 10

class Grid
{
public:
	Grid();
	~Grid();	

	friend ostream &operator<<(ostream &output, const Grid &G);

	void InitGrid();

private:
	Cell **_cellArrPtr;
	unsigned short _arrSize;
};




#endif