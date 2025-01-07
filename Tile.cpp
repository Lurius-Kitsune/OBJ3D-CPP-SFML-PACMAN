#include "Tile.h"

Tile::Tile(const Vector2f& _cordinates, const RectangleShape& _shape, const Texture& _texture)
{
	texture = _texture;
	coordinate = _cordinates;
	shape = _shape;
	shape.setTexture(&texture);
	shape.setPosition(coordinate);
}
