#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include<sstream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string wczytajLinie();
    static char wczytajZnak();
    static int wczytajLiczbeCalkowita();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static bool czyPlikJestPusty(fstream &plikTekstowy);
};
#endif
