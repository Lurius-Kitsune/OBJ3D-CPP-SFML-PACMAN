#include "Level.h"
#include "FileLoader.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Food.h"
#include "Game.h"

Level::Level(const string& _name)
{
	name = _name;
    prefixPath = "Assets/Maps/";
    vulnerableTimer = new Timer(10, [&]() { DeactiveVulenerableEvent(); });
    Generate();
}

Level::~Level()
{
    for (Entity* _entity : entities)
    {
        delete _entity;
    }
    delete vulnerableTimer;
}

void Level::Update()
{
    vulnerableTimer->Update(0.05F);
    for (Entity* _entity : entities)
    {
        _entity->Update();
    }
    Display(Game::GetInstance().GetWindow());
}

Entity* Level::CheckCollision(const Vector2f& _targetPosition)
{
    for (Entity* _entity : entities)
    {
        if (_entity->GetPosition() == _targetPosition) return _entity;
    }

    return nullptr;
}

void Level::RemoveEatable(Food* _eatable)
{
    eatables.erase(eatables.find(_eatable));
    if (IsOver())
    {
        Game::GetInstance().Stop();
    }
}

void Level::ActiveVulnerableEvent()
{
    for (Ghost* _ghost : ghosts)
    {
        _ghost->SetVulnerableStatus(true);
    }
}

void Level::Respawn(Entity* _entity)
{
    _entity->SetPosition();
}

void Level::Display(RenderWindow* _window) const
{
    for (Entity* _entity : entities)
    {
        _window->draw(_entity->GetShape());
    }
}

void Level::DeactiveVulenerableEvent()
{
    for (Ghost* _ghost : ghosts)
    {
        _ghost->SetVulnerableStatus(false);
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
    catch (const exception& _error)
    {
        cout << _error.what() << endl;
    }
}

void Level::SpawnEntity(const Vector2f& _shapeSize, const char _symbol, const u_int& _j, const u_int& _i)
{
    map<char, function<Entity*()>> _textureDatabase =
    {
        {'#', [&]() {
            return new Entity(this, "Walls/Wall", _shapeSize, CT_BLOCK);
        }},
        { '.', [&]() {
            Food* _eatable = new Food(this,"Foods/Point" , _shapeSize, FT_EATABLE, 10);
            eatables.insert(_eatable);
            return _eatable;
        }},
        { '*', [&]() {
            return new Food(this,"Foods/Apple" , _shapeSize,  FT_APPLE, 100);
        }},
        { 'C',  [&]() {
            return new PacMan(this, _shapeSize);
        }},
        { 'G', [&]() {
            Ghost* _ghost = new Ghost(this, _shapeSize);
            ghosts.insert(_ghost);
            return _ghost;
        }}
    };

    Entity* _entity = _textureDatabase[_symbol]();
    PlaceEntity(_j, _shapeSize, _i, _entity);
    entities.push_back(_entity);
}

void Level::PlaceEntity(const u_int& _j, const Vector2f& _shapeSize, const u_int& _i, Entity* _entity)
{
    const float _x = _j * _shapeSize.x;
    const float _y = _i * _shapeSize.y;
    _entity->SetPosition(Vector2f(_x, _y) + _shapeSize / 2.0f);
}
