#include "MorseTranslator.h"

MorseTranslator::MorseTranslator()
{

    size = 26;
    alfabetMorsa = new std::string [size];
    uzupelnijAlfabetMorsea();
}

MorseTranslator::~MorseTranslator()
{
    //dtor
}



void MorseTranslator::uzupelnijAlfabetMorsea()
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

// Pobiera numer indexu tablicy w ktorym jest tlumaczenie znaku ze zwyklego alfabetu na morsa, i piszczy odpowiednio xD
std::string MorseTranslator::signToMorse(int index)
{
    return alfabetMorsa[index];
}

std::string MorseTranslator::convert(const std::string &str)
{
    char znak;
    std::string morseExpresion = "";
    for(int i = 0; i < str.length(); ++i)
    {
        znak = str[i];
        znak = tolower(znak);

        switch(znak)
        {
        case ' ':
            morseExpresion += ' ';
            break;
        case 'a':
            morseExpresion += signToMorse(0);
            break;
        case 'b':
            morseExpresion += signToMorse(1);
            break;
        case 'c':
            morseExpresion += signToMorse(2);
            break;
        case 'd':
            morseExpresion += signToMorse(3);
            break;
        case 'e':
            morseExpresion += signToMorse(4);
            break;
        case 'f':
            morseExpresion += signToMorse(5);
            break;
        case 'g':
            morseExpresion += signToMorse(6);
            break;
        case 'h':
            morseExpresion += signToMorse(7);
            break;
        case 'i':
            morseExpresion += signToMorse(8);
            break;
        case 'j':
            morseExpresion += signToMorse(9);
            break;
        case 'k':
            morseExpresion += signToMorse(10);
            break;
        case 'l':
            morseExpresion += signToMorse(11);
            break;
        case 'm':
            morseExpresion += signToMorse(12);
            break;

        }

    }
    return morseExpresion;
}
