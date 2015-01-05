#ifndef GFX_WRAPPER_H

#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "GfxCell.h"

#define GFX_WRAPPER_H
#define CELL_WEIGHT 6
#define CELL_SPACING 3
#define DEF_ANIMATION_SPEED_MS 200 //milliseconds
#define DEF_ANTIALAISING 12

class GfxWrapper
{
public:
	GfxWrapper();
	~GfxWrapper();
	
	static sf::Color BACKGROUND;
	static sf::Color ALIVE_CELL;
	static sf::Color DEAD_CELL;
	
	void Render(Grid *, ushort);
	//Render with custom animation speed
	void Render(Grid *, ushort, ushort);
	void TestRenderGfx();
	
private:

	ushort _screen_x;
	ushort _screen_y;	
	static sf::RectangleShape CreateAliveCell(uint, uint);
	static sf::RectangleShape CreateDeadCell(uint, uint);
	void Init(Grid *);
	void RenderGrid(Grid *, sf::RenderWindow *);
	void InnerRender(Grid *, ushort, ushort);
};


#endif



