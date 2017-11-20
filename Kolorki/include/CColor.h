#ifndef CCOLOR_H
#define CCOLOR_H

#include <windows.h>
#include <iostream>

std::ostream & red(std::ostream& os)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    return os;
}

std::ostream & defcolor(std::ostream& os)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    return os;
}

class CColor
{
    public:
        CColor() {}
        ~CColor() {}
        friend std::ostream & operator<<(std::ostream& os, const CColor& c_color)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c_color.word_a | c_color.word_b | c_color.word_c);
            return os;
        }


    private:
        WORD word_a, word_b, word_c;
};

#endif // CCOLOR_H
