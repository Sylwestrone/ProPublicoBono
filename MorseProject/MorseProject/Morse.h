#ifndef MORSE_H
#define MORSE_H

#include <iostream>
#include <string>
#include <sstream>



class Morse
{
public:
	Morse();
	void setFrequency(const int frequency);
	void setPause(const int pause);
	void setDotTime(const int dotTime);
	void setDashTime(const int dashTime);
	void setSpacePause(const int spacePause);
	void setCharPause(const int charPause);
	Morse& operator<< (const std::string &str);
	Morse& operator<< (const long &number);
	Morse& operator<< (const double &number);
	Morse& operator<< (const int &number);

	int pause;
private:
	void uzupelnijAlfabetMorsea();
	void spiewaj(const std::string &str);
	void signToMorse(int index);

	int frequency;
	int dotTime;
	int dashTime;
	int spacePause;
	int charPause;
	int size;
	std::string *alfabetMorsa;

};

#endif // MORSE_H
