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

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {idOstatniegoAdresata=0;};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
};
#endif
