#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>

#include "../Type.h"
#include "../Morse.h"
#include "Beep.h"
#include "Blink.h"
#include "Console.h"

class Factory : public Morse
{
    public:
        Factory();
        virtual ~Factory();
        enum Type { beep, blink, console, disk};
        void virtual setExternalInfo(std::string parameters);
        void setOutput(Type type);
        void virtual convert(std::string text);
        virtual void convert(int number);
        void operator<< (std::string text);
    private:
        Morse *instance;

};

#endif // FACTORY_H
