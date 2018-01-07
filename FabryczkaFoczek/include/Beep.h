#ifndef BEEP_H
#define BEEP_H

#include <string>

#include "../Morse.h"

class Beep : public Morse
{
    public:
        Beep();
        virtual ~Beep();
        virtual void setExternalInfo(std::string info) {}
        virtual void convert(std::string text) {}
        virtual void convert(int number) {}
    private:
};

#endif // BEEP_H
