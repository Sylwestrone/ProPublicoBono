#ifndef BLINK_H
#define BLINK_H

#include <string>

#include "../Morse.h"


class Blink : public Morse
{
    public:
        Blink();
        virtual ~Blink();
        virtual void setExternalInfo(std::string info) {}
        virtual void convert(std::string text) {}
        virtual void convert(int number) {}

    private:
};

#endif // BLINK_H
