#include <iostream>

#include "AddressBook.h"

using namespace std;

int main ()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();

  ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    return 0;
}
