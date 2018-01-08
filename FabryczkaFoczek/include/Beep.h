#ifndef BEEP_H
#define BEEP_H

#include <string>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "../Morse.h"
#include "MorseTranslator.h"
#include "../to_string.h"


class Beeep : public Morse
{
    public:
        Beeep();
        virtual ~Beeep();
        virtual void setExternalInfo(std::string info);
        virtual void convert(std::string text);
        virtual void convert(int number);
        virtual Beeep& operator<<(std::string text);
    private:
        int frequency;
        int dotTime;
        int dashTime;
        int spacePause;
        int pause;
        int charPause;
        MorseTranslator translator;
};

#endif // BEEP_H
