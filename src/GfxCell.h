#ifndef GFXCELL_H
#define GFXCELL_H
#include <SFML/Graphics.hpp>
#define CELL_RADIUS 20

class GfxCell : public sf::Drawable, public sf::Transformable
{
public:
	GfxCell();
	~GfxCell();
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // GFXCELL_H
