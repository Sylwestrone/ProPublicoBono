#ifndef MORSETRANSLATOR_H
#define MORSETRANSLATOR_H

#include <string>

class MorseTranslator
{
    public:
        MorseTranslator();
        virtual ~MorseTranslator();
        std::string convert(const std::string &str);
    private:
        void uzupelnijAlfabetMorsea();

        std::string signToMorse(int index);
        int size;
        std::string *alfabetMorsa;
};

#endif // MORSETRANSLATOR_H
