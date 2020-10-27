#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <string>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat (int ID, int IDUZYTKOWNIKA, string IMIE, string NAZWISKO, string NUMERTELEFONU, string EMAIL, string ADRES);
    Adresat();

    void ustawId (int noweId);
    void ustawIdUzytkownika (int nowyIdUzytkownika);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail (string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika ();
    string pobierzImie ();
    string pobierzNazwisko ();
    string pobierzNumerTelefonu ();
    string pobierzEmail ();
    string pobierzAdres ();
};
#endif
