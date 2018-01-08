#ifndef DISK_H
#define DISK_H

#include <string>
#include <fstream>
#include <iostream>

#include "../Morse.h"
#include "MorseTranslator.h"
#include "../to_string.h"


class Disk : public Morse
{
    public:
        Disk();
        virtual ~Disk();
        virtual void setExternalInfo(std::string info);
        virtual void convert(std::string text);
        virtual void convert(int number);
        virtual Disk& operator<<(std::string text);

    private:
        MorseTranslator morseTranslator;
        std::string filePath;
};

#endif // DISK_H
