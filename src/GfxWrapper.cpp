#include "GfxWrapper.h"

//Members
sf::Color GfxWrapper::BACKGROUND = sf::Color(35, 35, 35);
sf::Color GfxWrapper::ALIVE_CELL = sf::Color(0, 145, 100);
sf::Color GfxWrapper::DEAD_CELL = sf::Color(30, 30, 30);

sf::RectangleShape GfxWrapper::CreateAliveSimpleCell(uint pos_x, uint pos_Y)
{
	sf::RectangleShape rect(sf::Vector2f(DEF_SIMPLE_CELL_SIZE, DEF_SIMPLE_CELL_SIZE));
  rect.setPosition(pos_x, pos_Y);
  rect.setFillColor(ALIVE_CELL);
	
	return rect;
}

GfxCell GfxWrapper::CreateAliveTextureCell(uint pos_x, uint pos_Y)
{
	GfxCell gCell = GfxCell();
  gCell.setPosition(pos_x, pos_Y);  
	
	return gCell;
}

sf::RectangleShape GfxWrapper::CreateDeadSimpleCell(uint pos_x, uint pos_Y)
{
	sf::RectangleShape rect(sf::Vector2f(DEF_SIMPLE_CELL_SIZE, DEF_SIMPLE_CELL_SIZE));
  rect.setPosition(pos_x, pos_Y);
  rect.setFillColor(DEAD_CELL);
	
	return rect;
}

void GfxWrapper::Init(Grid *gPtr)
{
	switch(_gfxType)
	{
			case Simple:
				_cellSize = DEF_SIMPLE_CELL_SIZE;
				_cellSpacing = DEF_CELL_SPACING;
				break;
				
			case Texture:
				_cellSize = DEF_TEXTURE_CELL_SIZE * 2;
				_cellSpacing = 0;
				break;
	}
	
	
	//Initialze window size
	_screen_x = gPtr->ArrSize() * (_cellSize + _cellSpacing);
	_screen_y = gPtr->ArrSize() * (_cellSize + _cellSpacing);	
}

GfxWrapper::GfxWrapper() {}
GfxWrapper::~GfxWrapper() {}

void GfxWrapper::RenderGrid(Grid *gPtr, sf::RenderWindow *window)
{
  Cell **tmpC = gPtr->GetCells();
  ushort xOffset = 0;
  ushort yOffset = 0;	
	sf::RectangleShape tmpCellShape;
	GfxCell gCell;

  for(size_t r = 0; r < gPtr->ArrSize(); r++) // rows
  {
    Cell *rCell = tmpC[r];
    for(size_t c = 0; c < gPtr->ArrSize(); c++) // cells
    {
			if(_gfxType == Simple)
			{
				if(rCell[c].IsAlive())      				
					tmpCellShape = CreateAliveSimpleCell(xOffset, yOffset);      
				else
					tmpCellShape = CreateDeadSimpleCell(xOffset, yOffset);
				//draw dead or alive cell				
				window->draw(tmpCellShape);
			}
			else //Texture
			{
				if(rCell[c].IsAlive())
				{
					gCell = CreateAliveTextureCell(xOffset, yOffset);				
					//draw only living cells..
					window->draw(gCell);
				}				
			}		
				
      // increase x offset for every cell
      xOffset += _cellSize + _cellSpacing;
    }
    // increase y offset for every row
    yOffset += _cellSize + _cellSpacing;
    xOffset = 0;
  }
}

void GfxWrapper::Render(Grid *gPtr, ushort n, GfxType gfxType)
{
	_gfxType = gfxType;
	InnerRender(gPtr, n, DEF_ANIMATION_SPEED_MS);
}

void GfxWrapper::Render(Grid *gPtr, ushort n, ushort aniSpeed, GfxType gfxType)
{
	_gfxType = gfxType;
	InnerRender(gPtr, n, aniSpeed);	
}

//Render with none default animations speed
void GfxWrapper::InnerRender(Grid *gPtr, ushort n, ushort aniSpeed)
{
	sf::ContextSettings settings;
  settings.antialiasingLevel = DEF_ANTIALAISING;
  sf::Clock clock; // starts clock
	bool run = true;
	size_t i = 0;
	Init(gPtr);
	sf::Vertex rect[] = 
	{		
			sf::Vertex(sf::Vector2f(0, 0), sf::Color(7, 74, 126, 255)),
			sf::Vertex(sf::Vector2f(_screen_x, 0), sf::Color(7, 74, 126, 255)),
			sf::Vertex(sf::Vector2f(_screen_x, _screen_y), sf::Color(30, 109, 166, 255)),
			sf::Vertex(sf::Vector2f(0, _screen_y), sf::Color(30, 109, 166, 255))
	};

  sf::RenderWindow window(sf::VideoMode(_screen_x, _screen_y), "KataGameOfLife", sf::Style::Default, settings);	

  while(run)
  {		
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
				window.close();
    }
    sf::Time elapsed = clock.getElapsedTime();

    // draw...
    if(i <= n && elapsed.asMilliseconds() > aniSpeed) // refresh
    {
      window.clear(BACKGROUND);
			if(_gfxType == Texture)
				window.draw(rect, 4, sf::Quads);
      RenderGrid(gPtr, &window);
      window.display();      
			i++;
			if(i > 0 && n > 0 && i % n != 0) gPtr->NextGeneration();
			clock.restart();
    }
		run = window.isOpen();		
  } // run
}

void GfxWrapper::TestRenderGfx()
{
	sf::ContextSettings settings;
  settings.antialiasingLevel = DEF_ANTIALAISING;
  sf::Clock clock; // starts clock
	bool run = true;
	sf::Vertex rect[] = 
	{		
			sf::Vertex(sf::Vector2f(0, 0), sf::Color(7, 74, 126, 255)),
			sf::Vertex(sf::Vector2f(500, 0), sf::Color(7, 74, 126, 255)),
			sf::Vertex(sf::Vector2f(500, 500), sf::Color(30, 109, 166, 255)),
			sf::Vertex(sf::Vector2f(0, 500), sf::Color(30, 109, 166, 255))
	};
	
	//Init(gPtr);	

  sf::RenderWindow window(sf::VideoMode(500, 500), "KataGameOfLife", sf::Style::Default, settings);	

  while(run)
  {		
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
				window.close();
    }
    sf::Time elapsed = clock.getElapsedTime();

    // draw...    
      window.clear(BACKGROUND);
			//draw			
			window.draw(rect, 4, sf::Quads);
			GfxCell gCell = GfxCell();
			gCell.setPosition(5, 5);			
			window.draw(gCell);
      
      window.display();			
			
			clock.restart();
    
		run = window.isOpen();		
  } // run
}