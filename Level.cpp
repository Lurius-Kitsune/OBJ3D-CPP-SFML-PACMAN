#include "Level.h"
#include "FileLoader.h"


Level::Level(const string& _name)
{
	name = _name;
    prefixPath = "Assets/Maps/";
    Generate();
}

Level::~Level()
{
    for (Entity* _entity : entities)
    {
        delete _entity;
    }
}

void Level::Display(RenderWindow& _window) const
{
    for (Entity* _entity : entities)
    {
        _window.draw(_entity->GetShape());
    }
}

void Level::Generate()
{
    try
    {
        const string& _extensionPath = ".txt";
        const vector<string>& _data = FileLoader::GetInstance().ReadAll((prefixPath + name).c_str());
        const u_int& _size = static_cast<u_int>(_data.size());
        const Vector2f& _shapeSize = { 20.0f, 20.0f };
        

        for (u_int _i = 0; _i < _size; _i++)
        {
            u_int _j = 0;
            for (const char _symbol : _data[_i])
            {
                SpawnEntity(_shapeSize,_symbol, _j, _i);
                _j++;
            }
            cout << _data[_i] << endl;
        }

        mapSize = Vector2u(static_cast<unsigned>(_data[0].size() * _shapeSize.x), 
            static_cast<unsigned>(_data.size() * _shapeSize.y));
    }
    catch (const exception& _ex)
    {
        cout << _ex.what() << endl;
    }
}

void Level::SpawnEntity(const Vector2f& _shapeSize, const char _symbol, const u_int& _j, const u_int& _i)
{
    std::map<char, function<Entity*()>> _textureDatabase =
    {
        {'#', [&]() {
            return new Entity("Walls/Wall", _shapeSize);
        }},
        { '.', [&]() {
            return new Entity("Foods/Point" , _shapeSize);
        }},
        { '*', [&]() {
            return new Entity("Foods/Apple" , _shapeSize);
        }},
        { 'C',  [&]() {
            return new PacMan("Pacman/Moving/PacMan_Eating_1" , _shapeSize);
        }},
        { 'G', [&]() {
            return new Entity("Ghosts/Blue/BlueGhost_Vulnerable" , _shapeSize);
        }}
    };

    Entity* _entity = _textureDatabase[_symbol]();
    PlaceEntity(_j, _i, _entity);
    entities.push_back(_entity);
}

void Level::PlaceEntity(const u_int& _j, const u_int& _i, Entity* _entity)
{
    const float _x = _j * _entity->GetShapeSize().x;
    const float _y = _i * _entity->GetShapeSize().y;
    _entity->SetPosition(Vector2f(_x, _y));
}
