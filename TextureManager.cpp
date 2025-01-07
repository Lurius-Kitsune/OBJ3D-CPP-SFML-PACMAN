#include "TextureManager.h"
#include "Logger.h"
void TextureManager::InitShape(RectangleShape& _shape, Texture& _texture, const string& _name)
{
	if (!_texture.loadFromFile("Assets/Textures/" + _name + ".png"))
	{
		Logger::GetInstance().Error("Impossible de lire le fichier !");
		if (!_texture.loadFromFile("Assets/Textures/MissingTexture.png"))
		{
			throw exception("Can't put missing texture, abort !");
		}
	}

	_shape.setTexture(&_texture);
}
