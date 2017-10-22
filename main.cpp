
#include <iostream>
#include <string>
#include "macierz.h"


int main()
{
    try {
        Macierz	*m = new Macierz();
        Macierz *m2 = new Macierz();
        m->setValue(1, 1, 2.0);
        m->wypisz();
        std::cout << "\n" << *m << "\n\n";
        *m = *m2;
        if (*m == *m2) {
            std::cout << "Macierz m oraz m1 sa takie same\n";
            std::cout << m << " " << m2 << "\n";
        }
        else
        {
            std::cout << "Macierze sa rozne\n";
        }

        Macierz *m3 = new Macierz();
        //*m3 = *m;
        Macierz a;
        Macierz b;
        std::cout << "za chwile mnozenie : \n";
        a.setValue(0,0,1);
        a.setValue(0,1,1);
        a.setValue(1,0,1);
        a.setValue(1,1,1);
        m3->setValue(1,0,2);
        m3->setValue(1,1,9);
        *m3 = *m3 * a;

        std::cout << "a :\n" << *m3 << std::endl;
        delete m;
        delete m2;
        delete m3;


    }
    catch (std::exception e) {
        throw e.what();
    }
    return 0;
}
