#ifndef MORSE_H_INCLUDED
#define MORSE_H_INCLUDED

#include <string>

class Morse
{
    public:
        virtual ~Morse() {}
        virtual void setExternalInfo(std::string info) =0;
        virtual void convert(std::string text) =0;
        virtual void convert(int number) =0;
};


#endif // MORSE_H_INCLUDED
