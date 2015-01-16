#include "GfxCell.h"

GfxCell::GfxCell()
{
}

GfxCell::~GfxCell()
{
}

void GfxCell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	states.transform *= getTransform();
	sf::CircleShape cOuter(DEF_TEXTURE_CELL_SIZE, 100);
	sf::Texture tmpText;
	tmpText.loadFromFile("./img/cell.png", sf::IntRect(0, 0, 32, 32));
	tmpText.setSmooth(true);	
	
	cOuter.setTexture(&tmpText);	
	
	target.draw(cOuter, states);
	
}
	


