#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>

#define SIZE  2

class Macierz {
public:
    Macierz();
    ~Macierz();
    void wypisz() const; // sk¹d ten straszny CONST?! WTF?! ten const obok nazwy metody oznacza ¿e ta metoda nie bêdzie modyfikowaæ pól tej klasy (czyli u
//nas macierzy :)
    double getValue(const int posX, const int posY) const;
    void setValue(const int posX, const int posY, double value); // to zmienia jak¹œ cyferkê z macierzy o podanych koordynatach- easy (nie ma consta za
//metod¹, a wiesz czemu? ... podejdŸ to Ci powiem... bo ta metoda modyfikuje macierz, dobre co? xD)
    friend std::ostream & operator<< (std::ostream &output, const Macierz& m); // jazda bez trzymanki xD funkcja zaprzyjaŸniona (NIE METODA!! xD) -
//dlaczego zaprzyjaŸniona? bo to taka funkcyjka któa ma dostêp prywatnych danych klasy xD (zwróc uwagê na definicjê - nie ma tam "Macierz:: " <- jak wspomnia³em
//to nie jest meotoda klasy macierz :) wiêcje ni¿ej xD
    bool operator== (const Macierz& m) const; // to bêdzie do porównañ czy jedna macierz równa siê drugiej ;p
    Macierz & operator= (const Macierz &m); // to do przypisywania - zero filozofii
    Macierz operator* (const Macierz &m); // a to to do mno¿enia
    Macierz operator* (double skalar);
private:
    double **macierz; // wskaŸniczek do wskaŸniczków ;p czyli tablica 2d
};

//konstruktor alokuje pamiec dla dwuwymiarowej tablicy "macierz" oraz domyslnie wpisuje do niej same 0 by nie bylo tam krzakow xD
Macierz::Macierz() {
    macierz = new double * [SIZE];// najepierw tworzymy jednowymiarow¹ tablicê wskaŸników
    for (int i = 0; i < SIZE; ++i) {
        macierz[i] = new double[SIZE]; // teraz do ka¿dej komórki wrzucamy tablicê ju¿ zwyk³ych wartoœci double - czyli otrzymujemy tablicê 2d
        for (int j = 0; j < SIZE; ++j) { // tutaj dodatkowo ustawiamy wartoœci na 0
            macierz[i][j] = 0;
        }
    }
}

Macierz::~Macierz() { // tutaj musimy posprz¹taæ po sobie, czyli zwalniamy pamiêæ po tablicy 2d - jak by by³a 1d to easy - wstarczy delete [] tab xD; ale to
//jest 2d :)

    for (int i = 0; i < SIZE; ++i) { //skoro w ka¿dej komórce jest jakaœ tablica wskaŸników to musimy j¹ ca³¹ prze.jechaæ xD i opró¿niæ  ka¿d¹
        delete [] macierz[i];
    }
    delete[] macierz; // na koñcu opró¿niamy nadrzêdn¹ tablicê
    macierz = nullptr;
    //std::cout << "Pamiec zwolniona\n"; // wypisuje coœ :) :)
}

// metoda wypisujaca macierz
// no wiadomo o co biega, co ja siê bêdê tutaj produkowa³ xDD
void Macierz::wypisz() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << macierz[i][j] << " ";
        }
        std::cout << "\n";
    }
}

double Macierz::getValue(const int posX, const int posY) const { // po co te consty przy tych intach? to informacja i jednoczeœnie blokada, ¿e nie bêdziemy w
//tej metodzie modyfikowaæ posX oraz posY
    return this->macierz[posX][posY];
}

void Macierz::setValue(const int posX, const int posY, double value) {
    if (posX < 0 || posY < 0 || posX >= SIZE || posY >= SIZE) {
        std::cout << "Nie mozna wstawic wartosci.";
        return;
    }
    macierz[posX][posY] = value;
}

// sluzy wypisywaniu macierzy, dzieki temu mo¿emy wypisywaæ macizerz w ten sposób : Macierz m; cout << m << endl;
std::ostream & operator<< (std::ostream &output, const Macierz &m) {
    return output << m.getValue(0, 0) << " " << m.getValue(0, 1) << "\n" << m.getValue(1, 0) << " " << m.getValue(1, 1);
}

// to coœ robi
// wiadomo co
bool Macierz::operator==(const Macierz& m) const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (this->macierz[i][j] != m.getValue(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Macierz & Macierz::operator= (const Macierz &m) {
    if(this != &m){
        for (int i = 0; i < SIZE; ++i) { //skoro w ka¿dej komórce jest jakaœ tablica wskaŸników to musimy j¹ ca³¹ prze.jechaæ xD i opró¿niæ  ka¿d¹
            delete [] macierz[i];
        }
        delete[] macierz;

        macierz = new double * [SIZE];// najepierw tworzymy jednowymiarow¹ tablicê wskaŸników
        for (int i = 0; i < SIZE; ++i) {
            macierz[i] = new double[SIZE]; // teraz do ka¿dej komórki wrzucamy tablicê ju¿ zwyk³ych wartoœci double - czyli otrzymujemy tablicê 2d
            for (int j = 0; j < SIZE; ++j) { // tutaj dodatkowo ustawiamy wartoœci na 0
                macierz[i][j] = m.getValue(i, j);
            }
        }

        std::cout << "operator = \n";

    }
    return *this;
}


Macierz Macierz::operator* (const Macierz &m) {
    Macierz wynik;
    double suma = 0;

    for(int w = 0; w < SIZE; ++w){
        for(int k = 0; k < SIZE; ++k){
            wynik.setValue(w, k, 0);
            for(int x = 0; x < SIZE; ++x){
                suma = macierz[w][k];
                suma += macierz[w][x] * m.getValue(x, k);
                wynik.setValue(w, k, suma);
            }
        }
    }
    return wynik;
}

Macierz Macierz::operator*(const double skalar){
    Macierz wynik;

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            wynik.setValue(i, j, skalar * macierz[i][j]);
        }
    }
    return wynik;
}

#endif // MACIERZ_H
