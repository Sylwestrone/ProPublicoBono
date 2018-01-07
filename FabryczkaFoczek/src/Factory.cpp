#include "Factory.h"

Factory::Factory()
{
    instance = new Beep();
}

Factory::~Factory()
{
    delete instance;
}

void Factory::setExternalInfo(std::string parameters)
{
    instance->setExternalInfo(parameters);
}

void Factory::setOutput(Type type)
{
    if(type == Type::beep)
    {
        instance = new Beep();
    }
    else if(type == Type::blink)
    {
        instance = new Blink();
    }
    else if(type == Type::console)
    {
        instance = new Console();
    }
}


void Factory::convert(std::string text)
{
    instance->convert(text);
}

void Factory::convert(int number)
{
    instance->convert(number);
}

void Factory::operator<<(std::string text)
{
    instance->convert(text);
}
