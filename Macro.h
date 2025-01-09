#pragma once
#include "Object.h"
#include <random>

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define SLEEP(_time) sf::sleep(Time(_time))
#define STRING(value) to_string(value)
#define INLINE inline
#define CLEAR system("cls")
#define CAST(_type, _value) static_cast<_type>(_value)
#define Super __super

#define UTF8
#ifdef UTF8
#define InitUTF8 SetConsoleOutputCP(CP_UTF8)
#else
#define InitUTF8 locale::global(locale("fr-FR"))
#endif

static int RandomInt(const int _min, const int _max)
{
    std::random_device _dev;
    std::mt19937 _rng(_dev());
    std::uniform_int_distribution<std::mt19937::result_type> _dist(_min, _max);

    return _dist(_rng);
}