#include "Cell.h"

Cell::Cell()
{
	//The cell is dead by default
	_isAlive = false;
}
Cell::Cell(const Cell &c)
{
	_isAlive = c._isAlive;
}

Cell::~Cell()
{
	//Nothing
}

//Get / set
bool Cell::IsAlive()
{
	return _isAlive;
}

void Cell::SetAlive()
{
	_isAlive = true;
}

void Cell::SetDead()
{
	_isAlive = false;
}