#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include<iostream>
#include<vector>
#include<fstream>

#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "UzytkownikMenedzer.h"

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    string nazwaTymczasowegoPlikuZAdresatami="temp.txt";

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);



public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {idOstatniegoAdresata=0;};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void edytujAdresataWPliku(int idAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void usunAdresataZPliku (int idUsuwanegoAdresata);
};
#endif
