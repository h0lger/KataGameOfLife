#ifndef	CELL_H
#define CELL_H

enum CellState
{
	Dead = 0,
	Alive = 1
};

class Cell
{
public:
	Cell();
	Cell(const Cell &); //Copy constructor
	~Cell();
	
	void SetDead();
	void SetAlive();
	bool IsAlive();

private:
	CellState _cellState;
	
};

#endif