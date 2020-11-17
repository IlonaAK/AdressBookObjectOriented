#include "AddressBook.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wyswietlMenuGlowne()
{
    system("cls");
    cout << "        MENU  G\235\340WNE   " << endl;
    cout << "*****************************" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "*****************************" << endl;
    cout << "Twoj wyb\242r: ";
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::menuGlowne()
{
    char wybor='0';
    do
    {
        wyswietlMenuGlowne();
        wybor=MetodyPomocnicze::wczytajZnak();
        switch (wybor)
        {
        case ('2'):
        {
            cout <<endl<< "LOGOWANIE"<<endl;
             logowanieUzytkownika();
            if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0)
                menuUzytkownika();
            break;
        }
        case ('1'):
        {
            cout <<endl<< "REJESTRACJA"<<endl;
            rejestracjaUzytkownika();
            break;
        }


        case ('3'):
        {
            exit(0);

        }
        default:
            cout <<endl<< "Niepoprawny wyb\242r";
            Sleep(1000);
            break;
        }

    }
    while (wybor!=3);
}

void KsiazkaAdresowa::wyswietlMenuUzytkownika()
{
     system("cls");
                cout<<"    MENU U\275YTKOWNIKA"<<endl;
                cout<<"******************************"<<endl;
                cout << "1. Dodaj adresata"<<endl;
                cout << "2. Wyszukaj po imieniu"<<endl;
                cout << "3. Wyszukaj po nazwisku"<<endl;
                cout << "4. Wy\230wietl wszystkich adresat\242w"<<endl;
                cout << "5. Usu\344 adresata" <<endl;
                cout << "6. Edytuj adresata" <<endl;
                cout << "7. Zmie\344 has\210o" <<endl;
                cout << "8. Wyloguj si\251" <<endl;
                cout << "Tw\242j wyb\242r: ";
}
void KsiazkaAdresowa::menuUzytkownika()
{
    char wybor='0';
    do
    {
        wyswietlMenuUzytkownika();
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        wybor=MetodyPomocnicze::wczytajZnak();
        switch (wybor)
        {
        case ('1'):
        {
            adresatMenedzer->dodajAdresata();
            break;

        }
        case ('2'):
        {
            adresatMenedzer->wyszukajAdresatowPoImieniu();
            break;
        }
        case ('3'):
        {
            adresatMenedzer->wyszukajAdresatowPoNazwisku();
            break;
        }
        case ('4'):
        {
            adresatMenedzer->wyswietlWszystkichAdresatow();
            system("pause");
            break;
        }
        case ('5'):
        {
            adresatMenedzer->usunAdresata();
            break;
        }
        case ('6'):
        {
             adresatMenedzer->edytujAdresata();
            break;
        }
        case ('7'):
        {
            uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
            Sleep(1000);
            break;
        }

        case ('8'):
        {
            wylogujUzytkownika();
            menuGlowne();
            break;
        }
        default:
            cout <<endl<< "Niepoprawny wyb\242r";
            Sleep(1500);
            break;
        }
    }
    while (wybor!=8);
}


void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}
