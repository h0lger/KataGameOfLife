#include "GfxWrapper.h"

//Members
sf::Color GfxWrapper::BACKGROUND = sf::Color(35, 35, 35);
sf::Color GfxWrapper::ALIVE_CELL = sf::Color(0, 145, 100);
sf::Color GfxWrapper::DEAD_CELL = sf::Color(30, 30, 30);

sf::RectangleShape GfxWrapper::CreateAliveCell(uint pos_x, uint pos_Y)
{
	sf::RectangleShape rect(sf::Vector2f(CELL_WEIGHT, CELL_WEIGHT));
  rect.setPosition(pos_x, pos_Y);
  rect.setFillColor(ALIVE_CELL);
	
	return rect;
}

void GfxWrapper::Init(Grid *gPtr)
{
	//Initialze window size
	_screen_x = gPtr->ArrSize() * (CELL_WEIGHT + CELL_SPACING);
	_screen_y = gPtr->ArrSize() * (CELL_WEIGHT + CELL_SPACING);	
}

sf::RectangleShape GfxWrapper::CreateDeadCell(uint pos_x, uint pos_Y)
{
	sf::RectangleShape rect(sf::Vector2f(CELL_WEIGHT, CELL_WEIGHT));
  rect.setPosition(pos_x, pos_Y);
  rect.setFillColor(DEAD_CELL);
	
	return rect;
}

GfxWrapper::GfxWrapper() {}
GfxWrapper::~GfxWrapper() {}

void GfxWrapper::RenderGrid(Grid *gPtr, sf::RenderWindow *window)
{
  Cell **tmpC = gPtr->GetCells();
  ushort xOffset = 0;
  ushort yOffset = 0;
	sf::RectangleShape tmpCellShape;

  for(size_t r = 0; r < gPtr->ArrSize(); r++) // rows
  {
    Cell *rCell = tmpC[r];
    for(size_t c = 0; c < gPtr->ArrSize(); c++) // cells
    {
      if(rCell[c].IsAlive())      				
				tmpCellShape = CreateAliveCell(xOffset, yOffset);      
			else
				tmpCellShape = CreateDeadCell(xOffset, yOffset);
			//draw dead or alive cell
			
			window->draw(tmpCellShape);
				
      // increase x offset for every cell
      xOffset += CELL_WEIGHT + CELL_SPACING;
    }
    // increase y offset for every row
    yOffset += CELL_WEIGHT + CELL_SPACING;
    xOffset = 0;
  }
}

void GfxWrapper::Render(Grid *gPtr, ushort n)
{
	InnerRender(gPtr, n, DEF_ANIMATION_SPEED_MS);
}

void GfxWrapper::Render(Grid *gPtr, ushort n, ushort aniSpeed)
{
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
			sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 100)),
			sf::Vertex(sf::Vector2f(500, 0), sf::Color(0, 0, 0, 100)),
			sf::Vertex(sf::Vector2f(500, 500), sf::Color(0, 0, 10, 250)),
			sf::Vertex(sf::Vector2f(0, 500), sf::Color(1, 1, 1, 250))
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