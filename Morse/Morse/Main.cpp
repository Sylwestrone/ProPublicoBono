// Morse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Morse.h"
#include <iostream>

int main()
{
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

	getchar();
    return 0;
}

