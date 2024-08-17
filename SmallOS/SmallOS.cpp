#include <clocale>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <ctime>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <random>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>


/*
------------------------------------------------------------------------------------------------------------
*/


#pragma comment(lib, "winmm.lib")

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


/*
------------------------------------------------------------------------------------------------------------
*/


std::string OSName = "Small OS 0.3";

std::string AppName = "";
bool AppE = false;
static void Commands(std::string cmd, bool AppExit);

static void Loading() {
    for (size_t i = 0; i < 101; i++) {
        std::cout << i << "%\n";
    }
    system("cls");
}

std::string DeviceLang;


namespace Setup {
    using namespace std;

    string Userinfo[] = { "name", "device_name", "password" };

    bool odejit = false;

    static void User() {
        cout
            << "------------------------------------------------------------------------------" << endl
            << "---- #### ---------- ### - # -- # -- ##### -- #### ------ ### ------ ### -----" << endl
            << "--- # ---------------- # - # -- # -- # - # - # --------- # - # ---- # - # ----" << endl
            << "---- ### -- #### -- #### - # -- # -- # - # -- ### ------ # - # ------ ## -----" << endl
            << "------- # - # # # - #  # - # -- # -- # - # ----- # ----- # - # ---- # - # ----" << endl
            << "--- #### -- # # # - #### - ## - ## - ##### - #### ------- ### - # -- ### -----" << endl
            << "------------------------------------------------------------------------------" << endl
            << endl
            << "Welcome to SmallOS setup!" << endl
            << "Select your system language:" << endl
            << "- CZ/cs, Česko" << endl
            << "- EN/uk, English United Kingdom" << endl
            << "Select a language with capital letters only!\n (\"CZ\" / \"EN\")" << endl
            << endl << "> ";
        while (true) {
            getline(cin, DeviceLang);
            if (DeviceLang == "CZ" || DeviceLang == "EN") {
                break;
            }
            else if (DeviceLang.length()-1 <= 0 || DeviceLang.length()-1 > 1) {
                cout 
                    << "This language doen't exist"
                    << endl << endl;
                PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            else {
                cout << "\n> ";
            }
            if (DeviceLang.empty() || DeviceLang.length() == 1) {
                cout << "> ";
            }
        }

        if (DeviceLang == "CZ") {
            while (true) {
                int i = 0;
                cout << "Zadejte jméno uživatele:\n";
                getline(cin, Userinfo[0]);
                for (char c : Userinfo[0]) {
                    if (!isascii(c)) {
                        i++;
                        system("cls");
                        cout << "Zadávejte pouze ASCII znaky.\n\n";
                        if (i == 1) {
                            break;
                        }
                    }
                    else {
                        odejit = true;
                    }
                }
                if (odejit == true) {
                    break;
                }
            }

            while (true) {
                int i = 0;
                cout << "Zadejte jméno zařizení:\n";
                getline(cin, Userinfo[1]);
                if (Userinfo[1] == "") {
                    system("cls");
                    cout << "Není zadán jméno zařízení!";
                }
                else {
                    for (char c : Userinfo[1]) {
                        if (!isascii(c)) {
                            i++;

                            cout << "Zadávejte pouze ASCII znaky.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            odejit = true;
                        }
                    }
                    if (odejit == true) {
                        break;
                    }
                }
            }

            while (true) {
                int i = 0;
                cout << "Zadejte heslo zařizení:\n";
                cin >> Userinfo[2];
                for (char c : Userinfo[2]) {
                    if (!isascii(c)) {
                        i++;
                        cout << "Zadávejte pouze ASCII znaky.\n\n";
                        if (i == 1) {
                            break;
                        }
                    }
                    else {
                        odejit = true;
                    }
                }
                if (Userinfo[2].length() < 8) {
                    cout << "Krátké heslo.\n\n";
                }
                else {
                    odejit = true;
                    break;
                }
            }
        }
        else if (DeviceLang == "EN") {
            while (true) {
                int i = 0;
                cout << "Enter a user name:\n";
                getline(cin, Userinfo[0]);
                for (char c : Userinfo[0]) {
                    if (!isascii(c)) {
                        i++;
                        system("cls");
                        cout << "Write user name with ASCII latters.\n\n";
                        if (i == 1) {
                            break;
                        }
                    }
                    else {
                        odejit = true;
                    }
                }
                if (odejit == true) {
                    break;
                }
            }

            while (true) {
                int i = 0;
                cout << "Enter a device name:\n";
                getline(cin, Userinfo[1]);
                if (Userinfo[1] == "") {
                    system("cls");
                    cout << "Device name not specified!";
                }
                else {
                    for (char c : Userinfo[1]) {
                        if (!isascii(c)) {
                            i++;

                            cout << "Write device name with ASCII latters.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            odejit = true;
                        }
                    }
                    if (odejit == true) {
                        break;
                    }
                }
            }

            while (true) {
                int i = 0;
                cout << "Enter a password:\n";
                cin >> Userinfo[2];
                for (char c : Userinfo[2]) {
                    if (!isascii(c)) {
                        i++;
                        cout << "Write password with ASCII latters!\n\n";
                        if (i == 1) {
                            break;
                        }
                    }
                    else {
                        odejit = true;
                    }
                }
                if (Userinfo[2].length() < 8) {
                    cout << "Password is too short!\n\n";
                }
                else {
                    odejit = true;
                    break;
                }
            }
        }
    }

    static void Heslo() {
        using namespace std;
        string b;

        if (DeviceLang == "CZ") {
            cout << "Zadejte heslo:\n";
            cin >> b;
            if (Userinfo[2] == b) {
                system("cls");
                cout << "Odemčeno\n\n";
                PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            else {
                system("cls");
                cout << "Špatné heslo, zadejte znovu.\n";
                PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                Heslo();
            }
        }
        else if (DeviceLang == "EN") {
            cout << "Enter password:\n";
            cin >> b;
            if (Userinfo[2] == b) {
                system("cls");
                cout << "Unlocked\n\n";
                PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
            else {
                system("cls");
                cout << "Wrong password, enter password again.\n";
                PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                Heslo();
            }
        }

    }

    static void Edit_User(int E_U, string Lang) {
        bool odejit = false;
        int i = 0;
        if (Lang == "CZ") {
            switch (E_U) {
            case 0:
                while (true) {
                    Userinfo[0];
                    cout << "Zadej nové jméno uživatele:\n";
                    getline(cin, Userinfo[0]);
                    for (char c : Userinfo[0]) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znaky.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            odejit = true;
                        }
                    }
                    if (odejit == true) {
                        break;
                    }
                    system("cls");
                    PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                }
                break;
            case 1:
                while (true) {
                    Userinfo[1];
                    cout << "Zadej nové jméno zařízeni:\n";
                    getline(cin, Userinfo[1]);
                    for (char c : Userinfo[1]) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znaky.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            odejit = true;
                        }
                    }
                    if (odejit == true) {
                        break;
                    }
                    system("cls");
                    PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                }
                break;
            case 2:
                while (true) {
                    Userinfo[2];
                    cout << "Zadejte heslo zařizení:\n";
                    getline(cin, Userinfo[2]);
                    for (char c : Userinfo[2]) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znaky.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            odejit = true;
                        }
                    }
                    if (odejit == true) {
                        break;
                    }
                    system("cls");
                    PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                }
                break;
            }
        }
        else if (Lang == "EN") {

        }
    }
}


/*
------------------------------------------------------------------------------------------------------------
*/


namespace SystemIO {
    using namespace std;

    string AppName = "";

    static void CLine() {
        cout << "SmallOS-" << Setup::Userinfo[1] << "> ";
    }

    static void Beep() {
        PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
    }

    static void Error() {
        cout << "Zadal jsi neplatný příkaz!" << endl << endl;
        Beep();
    }

    static void BackInfo() {
        cout << "\nPříkazem \"zpet\" jdeš o krok zpátky." << endl << endl;
    }

    static void Error2() {

    }
}


/*
------------------------------------------------------------------------------------------------------------
*/


namespace BaseApps {
    using namespace std;

    static void Help() {
        cout << "----- pomůžu -----" << endl << endl
            << "- nastaveni\t(nastavení systému)" << endl
            << "- vypnout\t(vypne se systém)" << endl
            << "- restart\t(restartuje systém)" << endl
            << "- info\t\t(vypíše informace ze systému a uživateli)" << endl
            << "- soubory\t(ukáže soubory a jak s nimi pracovat)" << endl
            << "- vyčistit\t(odstraní předchozí výstup operačního systému)" << endl
            << "- ucit\t\t(učit)"
            << endl << endl << endl;
        SystemIO::Beep();
    }

    static void Info() {
        cout << "----- Obecný info -----" << endl << endl
            << "Název zařízeni : " << Setup::Userinfo[1] << endl
            << "Jméno uživatele : " << Setup::Userinfo[0] << endl
            << "----------------------"
            << endl << endl << endl;
        SystemIO::Beep();
    }

    static void Novinky() {
        cout << "Co je nového v " << OSName << "?\n\n"
            << "- Lze příkazy použít \"kdekoliv\"" << endl
            << "- Optimalizace kódu"
            << endl << endl << endl;
    }

    static void Settings() {
        SystemIO::Beep();
        SystemIO::AppName = "nastavení";
        cout 
            << "----- Nastavení -----" << endl
            << "1. Změnit uživatelské iniciály" << endl
            << "2. Přizpůsobení vzhledu"
            << endl << endl
            << "Pokud se chcete dostat na konkrétní položku v nastavení, napište její čislo."
            << endl;
        SystemIO::CLine();
        while (true) {
            AppE = true;
            string prikaz;
            getline(cin, prikaz);
            if (prikaz.empty()) {
                SystemIO::CLine();
            }
            else if (prikaz == "1") {
                SystemIO::Beep();
                while (true) {
                    cout << "Napište číslo co chcete změnit:" << endl
                        << "1. Jméno uživatele" << endl
                        << "2. Jméno zařízení" << endl
                        << "3. Heslo uživatele."
                        << endl << endl;
                    SystemIO::BackInfo();
                    SystemIO::CLine();
                    getline(cin, prikaz);
                    if (prikaz.empty()) {
                        SystemIO::CLine();
                    }
                    if (prikaz == "zpet") {
                        SystemIO::Beep();
                        break;
                    }
                    if (prikaz == "1") {
                        Setup::Edit_User(0, DeviceLang);
                    }
                    else if (prikaz == "2") {
                        Setup::Edit_User(1, DeviceLang);
                    }
                    else if (prikaz == "3") {
                        Setup::Edit_User(2, DeviceLang);
                    }
                    else {
                        SystemIO::Error();
                    }
                }
            }
            else if (prikaz == "2") {
                SystemIO::Beep();
                while (true) {
                    cout << "Napište položku, u které chcete změnit barvu. \"Text\", \"Pozadi\" nebo \"Kombinace\".";
                    SystemIO::BackInfo();
                    SystemIO::CLine();
                    cin >> prikaz;
                    if (prikaz.empty()) {
                        SystemIO::CLine();
                    }
                    if (prikaz == "zpet") {
                        SystemIO::Beep();
                        break;
                    }
                    if (prikaz == "Pozadi" || prikaz == "pozadi") {
                        while (true) {
                            cout << "Vyber si barvu pozadi."
                                << endl << endl
                                << "1. bila" << endl
                                << "2. zelena" << endl
                                << "3. modra" << endl
                                << "4. cervena" << endl
                                << "5. fialova" << endl
                                << "6. oranzova" << endl
                                << "7. zluta"
                                << endl << endl;
                            SystemIO::BackInfo();
                            SystemIO::CLine();
                            cin >> prikaz;
                            if (prikaz == "zpet" || prikaz == "Zpet") {
                                SystemIO::Beep();
                                break;
                            }
                            if (prikaz == "1" || prikaz == "bila") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "2" || prikaz == "zelena") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "3" || prikaz == "modra") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "4" || prikaz == "cervena") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "5" || prikaz == "fialova") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "6" || prikaz == "oranzova") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "7" || prikaz == "zluta") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_RED);
                                SystemIO::Beep();
                                break;
                            }
                            else {
                                SystemIO::Beep();
                            }
                        }
                    }
                    else if (prikaz == "Text" || prikaz == "text") {
                        while (true) {
                            cout << "Vyber si barvu textu." << endl << endl
                                << "1. bila" << endl
                                << "2. zelena" << endl
                                << "3. modra" << endl
                                << "4.cervena" << endl
                                << "5.fialova" << endl
                                << "6.oranzova" << endl
                                << "7.zluta"
                                << endl << endl;
                            SystemIO::BackInfo();
                            SystemIO::CLine();
                            cin >> prikaz;
                            if (prikaz == "zpet" || prikaz == "Zpet") {
                                SystemIO::Beep();
                                break;
                            }
                            if (prikaz == "1" || prikaz == "bila") {
                                SetConsoleTextAttribute(hConsole, 7);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "2" || prikaz == "zelena") {
                                SetConsoleTextAttribute(hConsole, 2);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "3" || prikaz == "modra") {
                                SetConsoleTextAttribute(hConsole, 1);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "4" || prikaz == "cervena") {
                                SetConsoleTextAttribute(hConsole, 4);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "5" || prikaz == "fialova") {
                                SetConsoleTextAttribute(hConsole, 5);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "6" || prikaz == "oranzova") {
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "7" || prikaz == "zluta") {
                                SetConsoleTextAttribute(hConsole, 6);
                                SystemIO::Beep();
                                break;
                            }
                            else {
                                SystemIO::Beep();
                            }
                        }
                    }
                    else if (prikaz == "Kombinace" || prikaz == "kombinace") {
                        while (true) {
                            cout << "Vyber si kombinaci (pozadi/text)." << endl << endl
                                << "1. cerna/bila" << endl
                                << "2. zelena/modra" << endl
                                << "3. modra/oranzova" << endl
                                << "4. Matygamic"
                                << endl << endl;
                            SystemIO::BackInfo();
                            SystemIO::CLine();
                            cin >> prikaz;
                            if (prikaz == "zpet") {
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "1" || prikaz == "cerna/bila") {
                                SetConsoleTextAttribute(hConsole, 7);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "2" || prikaz == "zelena/modra") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_BLUE);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "3" || prikaz == "modra/oranzova") {
                                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                                SystemIO::Beep();
                                break;
                            }
                            else if (prikaz == "4" || prikaz == "Matygamic") {
                                SetConsoleTextAttribute(hConsole, 4);
                                SystemIO::Beep();
                                break;
                            }
                            else {
                                SystemIO::Beep();
                            }
                        }
                    }
                    else {
                        SystemIO::Beep();
                    }
                }
            }
            else if (prikaz == "odejit" || prikaz == "Odejit") {
                cout << endl << endl;
                return SystemIO::Beep();
            }
            else {
                Commands(prikaz, AppE);
                return;
            }
        }
    }

    static void Ornament() {
        SystemIO::Beep();
        cout << endl << endl
            << "|------------------------------------------------------------------------------|" << endl
            << "|---- #### ---------- ### - # -- # -- ##### -- #### ------ ### ------ ### -----|" << endl
            << "|--- # ---------------- # - # -- # -- # - # - # --------- # - # ---- # - # ----|" << endl
            << "|---- ### -- #### -- #### - # -- # -- # - # -- ### ------ # - # ------ ## -----|" << endl
            << "|------- # - # # # - #  # - # -- # -- # - # ----- # ----- # - # ---- # - # ----|" << endl
            << "|--- #### -- # # # - #### - ## - ## - ##### - #### ------- ### - # -- ### -----|" << endl
            << "|------------------------------------------------------------------------------|" << endl
            << endl << endl << endl;
    }

    static void Easteregg() {
        SystemIO::Beep();
        cout << "Nasel jsi skryty prikaz tohoto opeacniho systemu!" << endl
            << "--------------------" << endl
            << "| ---------------- |" << endl
            << "| -- Matygamicz -- |" << endl
            << "| ---------------- |" << endl
            << "| ---- Tvurce ---- |" << endl
            << "| ----- této ----- |" << endl
            << "| ---- apliace --- |" << endl
            << "| ---------------- |" << endl
            << "--------------------" << endl
            << endl << endl;
    }

    static void Soubory() {
        SystemIO::Beep();
        cout << "Zde jsou tvé soubory:\n\n";

        SystemIO::CLine();
    }
}


/*
------------------------------------------------------------------------------------------------------------
*/


namespace Apps {
    using namespace std;

    static void Learn() {
        SystemIO::Beep();
        SystemIO::AppName = "Učit";
        while (true) {
            AppE = true;
            cout << "----- Jdeme se ucit! -----" << endl << endl
                << "1. Matematika" << endl << endl
                << "2. Zemepis (nefunguje)" << endl << endl << endl
                << "Zadej jaky predmet se chces ucit(cislo nebo nazev)."
                << endl << endl;
            SystemIO::CLine();
            string prikaz;
            cin >> prikaz;
            if (prikaz == "odejit") {
                system("cls");
                cout << "Aplikace " << SystemIO::AppName << " ukoncena.\n\n\n";
                return SystemIO::Beep();
            }
            else if (prikaz == "matematika" || prikaz == "Matematika" || prikaz == "1") {
                SystemIO::Beep();
                while (true) {
                    system("cls");
                    cout << "Ucime se matematiku!\n\n\n";

                    srand(time(0));
                    int min = 1;
                    int max = 4;
                    int maxII = 50;
                    int zadani = min + rand() % (max - min + 1);
                    int randomI = min + rand() % (maxII - min + 1);
                    int randomII = min + rand() % (maxII - min + 1);
                    int randomIII = min + rand() % (maxII - min + 1);

                    int minS = 0;
                    int maxS = 2;
                    int Symboly = minS + rand() % (maxS - minS + 1);
                    int MatOperace[] = { 0, 1, 2, 3 };


                    if (zadani == 1) {
                        int vysledek = randomI - randomII + randomIII;
                        cout << "Kolik je?\n\n" << randomI << " - " << randomII << " + " << randomIII << " =\n";
                        SystemIO::CLine();
                        cin >> prikaz;
                        if (prikaz == to_string(vysledek)) {
                            cout << "Spravne!\n\n\n";
                        }
                        else {
                            cout << "Spatny vysledek!\n\n\n";
                        }
                    }

                    if (zadani == 2) {
                        int Vysledek;
                        string Priklad;

                        switch (MatOperace[Symboly]) {
                        case 0:
                            Vysledek = randomI + randomII;
                            Priklad = to_string(randomI) + " + " + to_string(randomII);
                            break;
                        case 1:
                            Vysledek = randomI - randomII;
                            Priklad = to_string(randomI) + " - " + to_string(randomII);
                            break;
                        case 2:
                            Vysledek = randomI * randomII;
                            Priklad = to_string(randomI) + " * " + to_string(randomII);
                            break;
                        case 3:
                            Vysledek = randomI / randomII;
                            Priklad = to_string(randomI) + " / " + to_string(randomII);
                            break;
                        }

                        cout << "Kolik je?\n\n" << Priklad << " =\n";
                        SystemIO::CLine();
                        cin >> prikaz;

                        if (prikaz == to_string(Vysledek)) {
                            cout << "Spravne!\n\n\n";
                        }
                        else {
                            cout << "Spatny vysledek!\n\n\n";
                        }
                    }

                    if (zadani == 3) {
                        int vysledekIII = randomI + randomII - randomIII + randomII + randomI + (randomI + randomI);
                        cout << "Kolik je?\n\n"
                            << randomI
                            << " + "
                            << randomII
                            << " - "
                            << randomIII
                            << " + "
                            << randomII
                            << " + "
                            << randomI
                            << " + "
                            << randomI + randomI
                            << " =\n";
                        SystemIO::CLine();
                        cin >> prikaz;
                        if (prikaz == to_string(vysledekIII)) {
                            cout << "Spravne!\n\n\n";
                        }
                        else {
                            cout << "Spatny vysledek!\n\n\n";
                        }
                    }

                    if (zadani == 4) {
                        int PVII = randomI + randomII;
                        int vysledekIV = PVII * randomIII;
                        cout << "Kolik je?\n\n(" << randomI << " + " << randomII << ") * " << randomIII << " =\n";
                        SystemIO::CLine();
                        cin >> prikaz;
                        if (prikaz == to_string(vysledekIV)) {
                            cout << "Spravne!\n\n\n";
                        }
                        else {
                            cout << "Spatny vysledek!\n\n\n";
                        }
                    }

                    bool ukoncit = false;

                    while (true) {
                        cout << "Chces pokracovat?\nAno nebo Ne?\n\n";
                        SystemIO::CLine();
                        cin >> prikaz;
                        if (prikaz == "Ano" || prikaz == "A" || prikaz == "a" || prikaz == "ano") {
                            cout << "Dobre, pokracujeme!\n";
                            break;
                        }
                        else if (prikaz == "Ne" || prikaz == "N" || prikaz == "n" || prikaz == "ne") {
                            system("cls");
                            cout << "Ukoncuju matematiku.\n\n";
                            ukoncit = true;
                            break;
                        }
                        else {
                            cout << "Zadal jsi neplatnou odpoved.\n\n\n";
                        }
                    }

                    if (ukoncit == true) {
                        break;
                    }
                }
            }
            else if (prikaz == "zemepis" || prikaz == "Zemepis" || prikaz == "2") {
                cout << "Nelze položku otevřít!" << endl;
                /*
                SystemIO::AppName = "Zemepis";
                while (true) {
                    system("cls");
                    cout << "Vyber si jake tema ze zemepisu se chces ucit. \n- Staty\n- Hlavni mesta Ceske repupliky.";
                    SystemIO::AppOffInfo();
                    SystemIO::CLine();
                    cin >> prikaz;
                    if () {

                    }
                }
                */
            }
            else {
                Commands(prikaz, AppE);
            }
        }
    }

    static void games() {
        SystemIO::Beep();

    }
}


/*
------------------------------------------------------------------------------------------------------------

Zde máš hlavní hlavní funkci (páteř) kódu operačního systému SmallOS.
Nad tímto řádkem máš potřebné funkce pro třídění kódu, jeho čistosti a funkčnosti.

------------------------------------------------------------------------------------------------------------
*/


int main() {
    setlocale(LC_ALL, "");
    using namespace std;
    Setup::User();
    Loading();
    Setup::Heslo();

    cout << "SmallOS by Matygamicz\nVítej v oparačním systému " << OSName << ". Zadej prikaz \"pomoc\" pro list prikazu...\n";
    

    while (true) {
        AppE = false;

        string prikaz;
        
        // SystemIO::CLine();
        //cin >> prikaz;
        getline(cin, prikaz);

        if (prikaz.empty()) {
            SystemIO::CLine();
        }
        else {
            Commands(prikaz, AppE);
        }
    }
    return 0;
}

void Commands(std::string cmd, bool AppExit) {
    using namespace std;

    if (cmd == "vypnout") {
        cout << "Ukončuji operační systém...\n";
        exit(0);
    }
    else if (cmd == "restart") {
        Setup::Heslo();
        Loading();
        cout << "RESTARTUJU...\n\n";
        system("cls");
        cout << "Vitej zpet " << Setup::Userinfo[0] << ".\n\n";
    }
    if (AppExit == true) {
        string YoN;
        cout << "Chcete odejít z aplikace " << AppName << endl
            << "Ano / Ne" << endl;
        SystemIO::CLine();
        cin >> YoN;
        if (YoN == "Ano" || YoN == "ano" || YoN == "a" || YoN == "A") {
        }
        else if (YoN == "Ne" || YoN == "ne" || YoN == "N" || YoN == "n") {
            AppE = false;
            return;
        }
    }
    if (cmd == "pomoc") {
        BaseApps::Help();
    }
    else if (cmd == "vycistit") {
        system("cls");
        SystemIO::Beep();
        SystemIO::CLine();
    }
    else if (cmd == "info") {
        BaseApps::Info();
    }
    else if (cmd == "nastaveni") {
        BaseApps::Settings();
    }
    else if (cmd == "ornament") {
        BaseApps::Ornament();
    }
    else if (cmd == "tajnost") {
        BaseApps::Easteregg();
    }
    else if (cmd == "soubory") {
        BaseApps::Soubory();
    }
    else if (cmd == "novinky") {
        system("cls");
        BaseApps::Novinky();
    }
    else if (cmd == "ucit") {
        Apps::Learn();
    }
    else {
        SystemIO::Error();
    }

    /*
    switch (cmd) {
    case "nastaveni" :
        BaseApps::Settings();
        break;
    default:
        SystemIO::Error();
    }
    */
}