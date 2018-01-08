#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>

#include "../Type.h"
#include "../Morse.h"
#include "Beep.h"
#include "Blink.h"
#include "Console.h"
#include "Disk.h"

// Provider Fabryki.
// Klasa inicjailujaca obiekt odpowiedniej klasy w zaleznosci od preferencji uzytkownika - jest posrednikiem pomiedzy uzytkownikiem a logika programu.
class Factory : public Morse
{
    public:
        Factory();
        Factory()
        virtual ~Factory();
        enum Type { beep, blink, console, disk};                 // Enum przechowujacy wszsytkie sposoby zwracanego wyniku.
        void virtual setExternalInfo(std::string parameters);
        void setOutput(Type type);                               // Metoda sluzaca ustawieniu sposobu zwrcania wynikow.
        void virtual convert(std::string text);                  // Przesloniete metody klasy abstrakcyjnej Morse
        virtual void convert(int number);
        Morse& operator<< (std::string text);
    private:
        Morse *instance;                                         // instance jest instancja odpowiedniej klasy (w zaleznosci od wyboru outputu uzytkowanika). Morse jest wspolnym typem dla wszsytkich klas logicznych.
        std::string info;                                        // Sluzy przekazaniu konfiguracji do dalszych etapow programu.

};

#endif // FACTORY_H
