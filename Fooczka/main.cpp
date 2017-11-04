#include <iostream>
#include <windows.h>
#include "foczka.h"

using namespace std;


int main()
{
    //Beep(7000, 7000);

    Foczka m;
	m.setFrequency(800);
	m.setPause(1000);
	m.setDotTime(200);
	m.setDashTime(400);
	m.setSpacePause(800);
	m.setCharPause(200);

	m << "Ala ma kota"; std::cout << "\n";

	long i = 0x5A5A5A5A;

	double d = 1.23456789;

	m << i << m.pause << d;


    return 0;
}
