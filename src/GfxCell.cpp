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
	sf::CircleShape cOuter(12, 100);
	sf::Texture tmpText;
	tmpText.loadFromFile("./img/cell.png", sf::IntRect(0, 0, 32, 32));
	tmpText.setSmooth(true);
	//tmpText.create(200, 200);	
	
	cOuter.setTexture(&tmpText);
	//cOuter.setFillColor(sf::Color(0, 0, 178, 200));
	//cOuter.setOutlineThickness(10);
	//cOuter.setOutlineColor(sf::Color(255, 255, 255, 150));
	
	
	
	target.draw(cOuter, states);
	
}
	


