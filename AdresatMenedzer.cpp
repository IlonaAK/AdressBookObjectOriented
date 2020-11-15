#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
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

void AdresatMenedzer::wyswietlWszystkichAdresatow()
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
void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow==0)
    {
        cout << endl << "W ksi\245\276ce adresowej nie ma adresat\242w z tymi danymi." << endl;
    }
    else
        cout << endl << "Ilo\230\206 adresat\242w w ksi\245\276ce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresat\242w o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksi\245\276ka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresat/242w o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imi/251:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail()<< endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierd\253 naciskaj\245c klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunAdresataZPliku (idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zosta\210 USUNI\250TY" << endl << endl;
                system("pause");
                break;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zosta\210 usuni\251ty" << endl << endl;
                system("pause");
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksi\\245\276ce adresowej" << endl << endl;
        system("pause");
    }
}


void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imi\251: ";
                itr -> ustawImie(MetodyPomocnicze::wczytajLinie());
                itr -> ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzImie()));
                zaktualizujDaneWybranegoAdresata(*itr);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr -> ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                itr -> ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzNazwisko()));
                zaktualizujDaneWybranegoAdresata(*itr);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                 itr -> ustawEmail(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                 itr -> ustawAdres(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr);
                break;
            case '6':
                cout << endl << "Powr\242t do menu u\253ytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powr\242t do menu u\253ytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Kt\242re dane zaktualizowa\206: " << endl;
    cout << "1 - Imi\251" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powr\242t " << endl;
    cout << endl << "Tw\242j wyb\242r: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    string liniaZDanymiAdresata="";

    liniaZDanymiAdresata=plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    plikZAdresatami.edytujAdresataWPliku(adresat.pobierzId(), liniaZDanymiAdresata);

    cout << endl << "Dane zosta\y zaktualizowane." << endl << endl;
}

