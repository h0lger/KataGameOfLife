#ifndef	CELL_H

class Cell
{
public:
	Cell();
	Cell(const Cell &); //Copy contructor
	~Cell();

	//const Cell &operator=(const Cell &);
	void SetDead();
	void SetAlive();
	bool IsAlive();

private:
	bool _isAlive;
	
};
#endif