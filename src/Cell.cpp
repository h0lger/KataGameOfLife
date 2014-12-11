#include "Cell.h"

Cell::Cell()
{
	//Standard är att cellen är död
	_isAlive = false;
}
Cell::~Cell()
{
	//Inget än
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