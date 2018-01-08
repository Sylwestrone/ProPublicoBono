#include "Disk.h"

Disk::Disk()
{
    //ctor
}

Disk::~Disk()
{
    //dtor
}

void Disk::convert(std::string text)
{
    std::ofstream file;
    file.open(filePath);

    std::string result = morseTranslator.convert(text);
    file << result;

    file.close();
}

void Disk::convert(int number)
{
    convert(to_string(number));
}

Disk& Disk::operator<<(std::string text)
{
    convert(text);
    return *this;
}

void Disk::setExternalInfo(std::string info)
{
    filePath = info;
}
