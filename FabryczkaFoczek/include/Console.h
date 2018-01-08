#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <iostream>

#include "../Morse.h"
#include "MorseTranslator.h"
#include "../to_string.h"

class Console : public Morse
{
    public:
        Console();
        virtual ~Console();
        virtual void setExternalInfo(std::string info) {}
        virtual void convert(std::string text);
        virtual void convert(int number);
        virtual Console& operator<<(std::string text);

    private:
        MorseTranslator translator;
};

#endif // CONSOLE_H
