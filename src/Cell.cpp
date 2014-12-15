#include "Cell.h"

Cell::Cell()
{
	//The cell is dead by default
	_cellState = CellState::Dead;
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
	return _cellState == CellState::Alive;
}

void Cell::SetAlive()
{
	_cellState = CellState::Alive;
}

void Cell::SetDead()
{
	_cellState = CellState::Dead;
}