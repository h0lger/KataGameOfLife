#include "GfxWrapper.h"

static void iterate(Grid *, sf::RenderWindow);
static sf::RectangleShape CreateAliveCell(uint, uint);

static sf::RectangleShape CreateAliveCell(uint pos_x, uint pos_Y)
{
	sf::RectangleShape rect(sf::Vector2f(CELL_WEIGHT, CELL_WEIGHT));
  rect.setPosition(pos_x, pos_Y);
  rect.setFillColor(RECT_COLOR);
	
	return rect;
}

static void iterate(Grid *gPtr, sf::RenderWindow *window)
{
  Cell **tmpC = gPtr->GetCells();
  ushort xOffset = 0;
  ushort yOffset = 0;

  for(size_t r = 0; r < gPtr->ArrSize(); r++) // rows
  {
    Cell *rCell = tmpC[r];
    for(size_t c = 0; c < gPtr->ArrSize(); c++) // cells
    {
      if(rCell[c].IsAlive())
      {
				//draw!
				sf::RectangleShape tmpCellShape = CreateAliveCell(xOffset, yOffset);
				window->draw(tmpCellShape);
      }
      // increase x offset for every cell
      xOffset += CELL_WEIGHT + CELL_SPACING;
    }
    // increase y offset for every row
    yOffset += CELL_WEIGHT + CELL_SPACING;
    xOffset = 0;
  }
}

void render_iterations(Grid *gPtr, ushort n)
{
	sf::ContextSettings settings;
  settings.antialiasingLevel = DEF_ANTIALAISING;
  sf::Clock clock; // starts clock
	bool run = true;
	size_t i = 0;

  sf::RenderWindow window(sf::VideoMode(DEF_SCREEN_X, DEF_SCREEN_Y), "KataGameOfLife", sf::Style::Default, settings);

  // shapes
  sf::RectangleShape rect = CreateAliveCell(10, 10);

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
    if(i <= n && elapsed.asMilliseconds() > ANIMATION_SPEED_MS) // refresh every 500ms
    {
      window.clear(BACKGROUND);
      iterate(gPtr, &window);
      window.display();			
      std::cout << "Refresh\n";      
			i++;
			if(i > 0 && i % n != 0) gPtr->NextGeneration();
			clock.restart();
    }
		run = window.isOpen();
  } // run
}