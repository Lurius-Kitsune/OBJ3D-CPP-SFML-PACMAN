#include "FileLoader.h"

vector<string> FileLoader::ReadAll(const char* _path) const
{
    const string& _filePath = string(_path);
    const string& _finalFileName = _filePath.empty() ? "Unknown" : _filePath + ".txt";

    ifstream _fs = ifstream(_finalFileName);
    
    if (!_fs.is_open())
    {
        throw exception(("Fichier impossible à ouvrir, veuillez vérifier le chemin : " + _finalFileName).c_str());
    }

    vector<string> _content;
    string _line;
    while (getline(_fs, _line))
    {
        _content.push_back(_line);
    }

    return _content;
}
