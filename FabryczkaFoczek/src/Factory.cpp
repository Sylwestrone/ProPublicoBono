#include "Factory.h"

Factory::Factory()
{
    instance = new Console();
}

Factory::~Factory()
{
    delete instance;
}

void Factory::setExternalInfo(std::string parameters)
{
    instance->setExternalInfo(parameters);
    info = parameters;
}

void Factory::setOutput(Type type)
{
    if(type == Type::beep)
    {
        instance = new Beeep();
    }
    else if(type == Type::blink)
    {
        instance = new Blink();
    }
    else if(type == Type::console)
    {
        instance = new Console();
    }
    else if(type == Type::disk)
    {
        instance = new Disk();
    }
    instance->setExternalInfo(info);
}


void Factory::convert(std::string text)
{
    instance->convert(text);
}

void Factory::convert(int number)
{
    instance->convert(number);
}

Morse& Factory::operator<<(std::string text)
{
    instance->convert(text);
    return *this;
}
