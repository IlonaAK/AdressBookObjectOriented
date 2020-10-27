#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto za\210o\276ono pomy\230lnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout  << "Podaj login: ";
        cin>> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj has\210o: ";
    cin>> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    for (int i =0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje u\276ytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for(int i=0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe has\210o: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Has\210o zosta\210o zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    bool czyPoprawneHaslo=false;
    bool czyIstniejeLogin=false;
    bool czyWykorzystanoLimit=false;
    idZalogowanegoUzytkownika=0;

    cout << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while ((itr != uzytkownicy.end())&&(czyPoprawneHaslo==false)&&(czyWykorzystanoLimit==false))
    {
        if (itr -> pobierzLogin()== login)
        {
            czyIstniejeLogin=true;
            for (int iloscProb=3; iloscProb>0; iloscProb--)
            {
                cout << "Podaj has\210o (pozosta\210o pr\242b: "<< iloscProb <<"): ";
                cin >> haslo;
                if (itr -> pobierzHaslo() == haslo)
                {
                    czyPoprawneHaslo=true;
                    cout << endl << "Zalogowa\210e\230 si\251." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika=itr -> pobierzId();
                    iloscProb=0;
                }
                if ((iloscProb==1)&&(czyPoprawneHaslo==false))
                    czyWykorzystanoLimit=true;
            }
        }
        else
            itr++;
    }
    if (czyIstniejeLogin==false)
    {
        cout << "Nie ma u\276ytkownika z takim loginem!" << endl << endl;
        system("pause");
    }
    if (czyWykorzystanoLimit==true)
    {
        cout << "Wyczerpano limit pr\242b!" << endl << endl;
        system("pause");
    }
}

    int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika ()
    {
        return idZalogowanegoUzytkownika;
    }

    void UzytkownikMenedzer::wylogujUzytkownika()
    {
        idZalogowanegoUzytkownika=0;
    }
