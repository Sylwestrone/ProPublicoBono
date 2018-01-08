#ifndef BLINK_H
#define BLINK_H

#include <string>
#include <iostream>
#define _WIN32_WINNT 0X403
#include "windows.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "../to_string.h"
#include "../Morse.h"
#include "MorseTranslator.h"




class Blink : public Morse
{
    public:
        Blink();
        virtual ~Blink();
        virtual void setExternalInfo(std::string info);
        virtual void convert(std::string text);
        virtual void convert(int number);
        virtual Blink& operator<<(std::string text);

    private:
        void capsLockBlink();
        MorseTranslator translator;
        int dotTime;
        int dashTime;
        int spacePause;
        int pause;
        int charPause;
        int actualPause;
};

#endif // BLINK_H
