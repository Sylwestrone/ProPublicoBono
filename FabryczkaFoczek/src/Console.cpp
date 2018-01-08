#include "Console.h"

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

void Console::convert(std::string text)
{
    std::cout << translator.convert(text);
}

void Console::convert(int number)
{
    convert(to_string(number));
}

Console& Console::operator<<(std::string text)
{
    convert(text);
    return *this;
}
