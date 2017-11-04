// MorseProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Morse.h"


int main()
{
	Morse m;
	m.setFrequency(800);
	m.setPause(1000);
	m.setDotTime(200);
	m.setDashTime(400);
	m.setSpacePause(800);
	m.setCharPause(200);

	m << "Ala ma kota"; 

	long i = 0x5A5A5A5A;

	double d = 1.23456789;
    return 0;
}

