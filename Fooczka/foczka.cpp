#include "foczka.h"
#include <string>

#include "windows.h"

Foczka::Foczka()
{
    frequency = 0;
    pause = 0;
    dotTime = 0;
    dashTime = 0;
    spacePause = 0;
    charPause = 0;
    size = 26;
    alfabetMorsa = new std::string [size];
    uzupelnijAlfabetMorsea();
}

void Foczka::uzupelnijAlfabetMorsea()
{
    alfabetMorsa[0] = ".-";     // a
    alfabetMorsa[1] = "-...";   // b
    alfabetMorsa[2] = "-.-.";   // c
    alfabetMorsa[3] = "-..";    // d
    alfabetMorsa[4] = ".";      // e
    alfabetMorsa[5] = "..-.";   // f
    alfabetMorsa[6] = "--.";    // g
    alfabetMorsa[7] = "....";   // h
    alfabetMorsa[8] = "..";     // i
    alfabetMorsa[9] = ".---";   // j
    alfabetMorsa[10] = "-.-";   // k
    alfabetMorsa[11] = ".-..";  // l
    alfabetMorsa[12] = "--";    // m
    alfabetMorsa[13] = "-.";    // n
    alfabetMorsa[14] = "---";   // o
}

void Foczka::setFrequency(const int frequency)
{
    this->frequency = frequency;
}

void Foczka::setPause(const int pause)
{
    this->pause = pause;
}

void Foczka::setDotTime(const int dotTime)
{
    this->dotTime = dotTime;
}

void Foczka::setDashTime(const int dashTime)
{
    this->dashTime = dashTime;
}

void Foczka::setSpacePause(const int spacePause)
{
    this->spacePause = spacePause;
}

void Foczka::setCharPause(const int charPause)
{
    this->charPause = charPause;
}


Foczka& Foczka::operator<< (const std::string &str)
{
    std::cout << str;
    spiewaj(str);
    return *this;
}

Foczka& Foczka::operator<< (const long &number)
{
    spiewaj(std::to_string(number));
    return *this;
}

Foczka& Foczka::operator<< (const double &number)
{
    spiewaj(std::to_string(number));
    return *this;
}

Foczka& Foczka::operator<< (const int &number)
{
    if(&number == &pause)
    {
        Beep(0, pause);
    }
    else
    {
        spiewaj(to_string(number));
    }

    return *this;
}

// Pobiera numer indexu tablicy w ktorym jest tlumaczenie znaku ze zwyklego alfabetu na morsa, i piszczy odpowiednio xD
void Foczka::signToMorse(int index)
{
    std::string znak =  alfabetMorsa[index];
    for(int i = 0; i < znak.length(); ++i)
    {
        if(znak[i] == '.')
        {
            Beep(frequency, dotTime);
        }
        else if(znak[i] == '-')
        {
            Beep(frequency, dashTime);
        }
        Beep(0, charPause);
    }
}

void Foczka::spiewaj(const std::string &str)
{
    char znak;
    std::string znakInMorse;
    for(int i = 0; i < str.length(); ++i)
    {
        znak = str[i];
        znak = tolower(znak);
        std::cout << znak;

        switch(znak)
        {
        case ' ':
            Beep(0, spacePause);
            break;
        case 'a':
            signToMorse(0);
            break;
        case 'b':
            signToMorse(1);
            break;
        case 'c':
            signToMorse(2);
            break;
        case 'd':
            signToMorse(3);
            break;
        case 'e':
            signToMorse(4);
            break;
        case 'f':
            signToMorse(5);
            break;
        case 'g':
            signToMorse(6);
            break;
        case 'h':
            signToMorse(7);
            break;
        case 'i':
            signToMorse(8);
            break;
        case 'j':
            signToMorse(9);
            break;
        case 'k':
            signToMorse(10);
            break;
        case 'l':
            signToMorse(11);
            break;
        case 'm':
            signToMorse(12);
            break;

        }

    }
}
