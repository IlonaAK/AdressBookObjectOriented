#include "Adresat.h"

Adresat::Adresat (int ID, int IDUZYTKOWNIKA, string IMIE, string NAZWISKO, string NUMERTELEFONU, string EMAIL, string ADRES){
this-> id=ID;
this-> idUzytkownika= IDUZYTKOWNIKA;
this-> imie= IMIE;
this-> nazwisko= NAZWISKO;
this-> numerTelefonu= NUMERTELEFONU;
this-> email= EMAIL;
this-> adres= ADRES;
}

Adresat::Adresat(){}

void Adresat::ustawId (int noweId)
{
    if(noweId >= 0)
    id=noweId;
}
void Adresat::ustawIdUzytkownika(int nowyIdUzytkownika)
{
    if(nowyIdUzytkownika >= 0)
    idUzytkownika=nowyIdUzytkownika;
}
void Adresat::ustawImie(string noweImie)
{
    imie=noweImie;
}
void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko=noweNazwisko;
}
void Adresat::ustawNumerTelefonu (string nowyNumerTelefonu)
{
    numerTelefonu=nowyNumerTelefonu;
}
void Adresat::ustawEmail (string nowyEmail)
{
    email=nowyEmail;
}
void Adresat::ustawAdres (string nowyAdres)
{
    adres= nowyAdres;
}
int Adresat::pobierzId ()
{
    return id;
}
int Adresat::pobierzIdUzytkownika ()
{
    return idUzytkownika;
}
string Adresat::pobierzImie ()
{
    return imie;
}
string Adresat::pobierzNazwisko ()
{
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu ()
{
    return numerTelefonu;
}
string Adresat::pobierzEmail ()
{
    return email;
}
string Adresat::pobierzAdres ()
{
    return adres;
}
