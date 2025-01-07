#include "Map.h"
#include "FileStream.h"
#include "TextureAssets.h"
#include "Logger.h"
using namespace Tools;

Map::~Map()
{
	for (u_int _lineIndex = 0; _lineIndex < mapSize.x; _lineIndex++)
	{
		for (u_int _collumnIndex = 0; _collumnIndex < mapSize.y; _collumnIndex++)
		{
			delete map[_lineIndex][_collumnIndex];
		}
	}
}

void Map::InitMap(const string& _filePath)
{
	FileStream _fs = FileStream(_filePath);
	vector<string> _content = _fs.ReadAll();

	mapSize = {
		static_cast<u_int>(_content.size()) ,
		static_cast<u_int>(_content[0].size())
	};

	for (u_int _lineIndex = 0; _lineIndex < mapSize.x; _lineIndex++)
	{
		vector<Tile*> _line;
		for (u_int _collumnIndex = 0; _collumnIndex < mapSize.y; _collumnIndex++)
		{
			char _char = _content[_lineIndex][_collumnIndex];
			Vector2i _position = _char == '#' ? SelectTileTexture({3, 1}, {20, 0}) :
				_char == '.' ? SelectTileTexture({ 2, 3 }, { 15, 1 }) :
				_char == 'G' ? SelectTileTexture({ 2, 3 }, { 15, 2 }) :
				SelectTileTexture({ 3, 1 }, { 20, 0 });
			Texture _texture = Texture(PACMAN_SHEET, false, IntRect(_position, {8, 8}));
			_line.push_back(new Tile(Vector2f(25.0F * _lineIndex, 25.0F *_collumnIndex), RectangleShape({ 25.0F, 25.0F }), _texture));
		}
		map.push_back(_line);
		Logger::GetInstance().Info("Generation Map : " + to_string(_lineIndex * 100 / (mapSize.x-1)) + "%");
	}

}

void Map::DisplayMap()
{
	sf::RenderWindow _window(sf::VideoMode({ 1000, 1000 }), "SFML works!");

	

	


	while (_window.isOpen())
	{
		while (const std::optional _event = _window.pollEvent())
		{
			if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
			{
				if (_key->code == Keyboard::Key::Escape)
				{
					_window.close();
				}
			}
		}

		_window.clear();

		for (u_int _lineindex = 0; _lineindex < mapSize.x; _lineindex++)
		{
			for (u_int _collumnindex = 0; _collumnindex < mapSize.y; _collumnindex++)
			{
				_window.draw(map[_lineindex][_collumnindex]->GetShape());
			}
		}

		_window.display();
	}


}
