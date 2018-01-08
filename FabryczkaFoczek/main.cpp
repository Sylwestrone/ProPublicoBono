#include <iostream>

#include "Factory.h"

using namespace std;

int main()
{
    Factory f;
    f.setExternalInfo("200 200 400");
    f.setOutput(Factory::blink);
    f.convert("Ala ma kota");
    f << "kot ma ale";
    f.setOutput(Factory::disk);
    f.convert("Ala ma kota");
    f.convert(123);

    return 0;
}
