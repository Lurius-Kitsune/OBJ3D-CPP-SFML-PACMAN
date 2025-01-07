#pragma once

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define SLEEP(_duration, _time) sleep_for(_duration(_time))
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