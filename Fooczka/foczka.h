#ifndef FOCZKA_H_INCLUDED
#define FOCZKA_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>



class Foczka
{
public:
    Foczka();
    void setFrequency(const int frequency);
    void setPause(const int pause);
    void setDotTime(const int dotTime);
    void setDashTime(const int dashTime);
    void setSpacePause(const int spacePause);
    void setCharPause(const int charPause);
    Foczka& operator<< (const std::string &str);
    Foczka& operator<< (const long &number);
    Foczka& operator<< (const double &number);
    Foczka& operator<< (const int &number);

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

template <typename T>
  std::string to_string ( T& Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

#endif // FOCZKA_H_INCLUDED
