#include "Cell.h"

Cell::Cell()
{
	//Standard �r att cellen �r d�d
	//_isAlive = false;
}
Cell::Cell(const Cell &c)
{
	_isAlive = c._isAlive;
}

Cell::~Cell()
{
	//Inget �n
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