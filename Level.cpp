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

void Level::Generate()
{
    try
    {
        const string& _extensionPath = ".txt";
        const vector<string>& _data = FileLoader::GetInstance().ReadAll((prefixPath + name).c_str());
        const u_int& _size = _data.size();

        for (u_int _i = 0; _i < _size; _i++)
        {
            cout << _data[_i] << endl;
            entities.push_back(new Entity("Foods/Apple.png"));
        }
    }
    catch (const exception& _ex)
    {
        cout << _ex.what() << endl;
    }
}

void Level::Display() const
{

}
