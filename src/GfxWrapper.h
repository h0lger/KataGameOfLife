#ifndef GFX_WRAPPER_H

#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "GfxCell.h"

#define GFX_WRAPPER_H
#define DEF_SIMPLE_CELL_SIZE 6
#define DEF_CELL_SPACING 3
#define DEF_ANIMATION_SPEED_MS 200 //milliseconds
#define DEF_ANTIALAISING 12

enum GfxType
{
	Simple = 0,
	Texture = 1
};

class GfxWrapper
{
public:
	GfxWrapper();
	~GfxWrapper();
	
	static sf::Color BACKGROUND;
	static sf::Color ALIVE_CELL;
	static sf::Color DEAD_CELL;
	
	void Render(Grid *, ushort, GfxType);
	//Render with custom animation speed
	void Render(Grid *, ushort, ushort, GfxType);
	void TestRenderGfx();
	
private:

	ushort _screen_x;
	ushort _screen_y;
	GfxType _gfxType;
	ushort _cellSize;
	ushort _cellSpacing;
	static sf::RectangleShape CreateAliveSimpleCell(uint, uint);
	static sf::RectangleShape CreateDeadSimpleCell(uint, uint);
	static GfxCell CreateAliveTextureCell(uint, uint);	
	void Init(Grid *);
	void RenderGrid(Grid *, sf::RenderWindow *);
	void InnerRender(Grid *, ushort, ushort);
};


#endif



