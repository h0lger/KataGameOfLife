#include "Cell.h"

Cell::Cell()
{
	//The cell is dead by default
	_cellState = Dead;
}
Cell::Cell(const Cell &c)
{
	_cellState = c._cellState;
}

Cell::~Cell()
{
	//Nothing
}

//Get / set
bool Cell::IsAlive()
{
	return _cellState == Alive;
}

void Cell::SetAlive()
{
	_cellState = Alive;
}

void Cell::SetDead()
{
	_cellState = Dead;
}