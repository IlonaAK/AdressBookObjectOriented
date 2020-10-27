#include "AdresatMenedzer.h"

void AdresatMenedzer::dodawanieAdresata()
{
    Adresat adresat;
    system("cls");

    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    adresat.ustawId(pobierzIdNowegoAdresata()+1);
    cout<< "-------PODAJ DANE ADRESATA------"<<endl<<endl;

    cout << "Podaj imi\251: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    cout << endl << "Adresat dodany pomy\230lnie" << endl << endl;
    system("pause");
}

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    return plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void AdresatMenedzer::wyswietlWszystkichAdresatowUzytkownika()
{
   system("cls");
    cout << "--------ADRESACI-------" << endl<< endl;
    for (int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            cout << adresaci[i].pobierzId() <<". "<< adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko()<<endl;
            cout << "telefon: " << adresaci[i].pobierzNumerTelefonu()<<endl;
            cout << "email: " << adresaci[i].pobierzEmail()<<endl;
            cout << "adres: " << adresaci[i].pobierzAdres()<<endl;
            cout << "---------------------------"<<endl;

        }
    }
}


