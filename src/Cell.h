#ifndef	CELL_H

class Cell
{
public:
	Cell();
	~Cell();

	void SetDead();
	void SetAlive();
	bool IsAlive();

private:
	bool _isAlive;
	
};
#endif