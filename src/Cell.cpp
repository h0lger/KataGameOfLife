#include "Cell.h"

Cell::Cell()
{
	//Standard �r att cellen �r d�d
	_isAlive = false;
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