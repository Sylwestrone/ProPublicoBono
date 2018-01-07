#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

#include "../Morse.h"

class Console : public Morse
{
    public:
        Console();
        virtual ~Console();
        virtual void setExternalInfo(std::string info) {}
        virtual void convert(std::string text) {}
        virtual void convert(int number) {}

    private:
};

#endif // CONSOLE_H
