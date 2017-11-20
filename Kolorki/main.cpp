#include <iostream>
#include "CColor.h"
#include "Edit.h"


int main()
{
    Edit e;                                          //wyrysowanie 6 niebieskich pol
	e.setPosition(7, 3);
	e.setLength(6);
	e.setText("Ala");
	e.setTextColor(Edit::Green);  //enumeratory //osobny typ danych niezalezny od innych, mozna przerzutowac na inta, nie kazdego inta mozna przerzutowac na enumerator
	e.setBackground(Edit::White);

    e.display(); //metoda display wyrysowuje 6 pol, od lewej strony
	std::string s = e.getText(); //pobranie danych
	std::cout << s << std::endl;
	std::cout << red << s << defcolor << std::endl;
	e.userText(); //przekazuje sterowanie do uzytkownika, powrot kursora w poczatkowe miejsce, opanowac backspace, enter zakonczenie wprowadzania tekstu
	s = e.getText();
    std::cout << s;

    return 0;
}
