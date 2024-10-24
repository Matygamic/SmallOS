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
#include <vector>

// including local files
#include "ClassUser.cpp"
#include "BaseApps.cpp"
#include "Apps.cpp"

/*
------------------------------------------------------------------------------------------------------------
*/


// #pragma comment(lib, "winmm.lib");

// HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


/*
------------------------------------------------------------------------------------------------------------
*/
/* List of basic functions */

// function with basic commands
void Commands(std::string cmd/*, std::bool AppExit*/);

void Loading() {
    for (int i = 0; i <= 101; i++) {
        cout << i 
            << " %" 
            << endl;
    }
    system("cls");
}







/*
------------------------------------------------------------------------------------------------------------
*/
/* Global variables */

std::string OSName = "SmallOS 0.3";

std::string SystemLang; 


/*
------------------------------------------------------------------------------------------------------------
*/
/* Classes & Objects */

class SystemStuff {
    public:
        void CLine() {
            cout << User.Username << "-SmallOS: ";
        }

        void Error() {
            cout << "Syntax error!" 
                << endl 
                << endl;
        }

        void Beep() {
            cout << "BEEEEEEEEEP!"
                << endl 
                << endl;
        }
};

SystemStuff SystemIO;



/*
------------------------------------------------------------------------------------------------------------
*/

// function of system setup
static void Setup() {
    using namespace std;

    bool ExitSetup = false;
    string input;

    cout
        << "------------------------------------------------------------------------------" << endl
        << "---- #### ---------- ### - # -- # -- ##### -- #### ------ ### ----- # --------" << endl
        << "--- # ---------------- # - # -- # -- # - # - # --------- # - # ---- # - # ----" << endl
        << "---- ### -- #### -- #### - # -- # -- # - # -- ### ------ # - # ---- ##### ----" << endl
        << "------- # - # # # - #  # - # -- # -- # - # ----- # ----- # - # -------- # ----" << endl
        << "--- #### -- # # # - #### - ## - ## - ##### - #### ------- ### - # ----- # ----" << endl
        << "------------------------------------------------------------------------------" << endl
        << endl
        << "Welcome to SmallOS setup!" << endl
        << "--------------------------------------" << endl
        << "Select your system language:" << endl
        << "- CZ/cs, Česko" << endl
        << "- EN/uk, English United Kingdom" << endl
        << "--------------------------------------" << endl
        << "Select a language with capital letters only!" << endl << "(\"CZ\" / \"EN\")" << endl
        << endl << "> ";

        while(true) {
            getline(cin, input);
            if (input.empty()) {
                cout << "Please type language."
                    << endl << endl;
            }
            else if(input == "CZ") {
                // Store Device language
                SystemLang = "CZ"; 

                // Setup Name for user
                while (true) {
                    int i = 0;
                    cout << "Jméno uživatele:" << endl 
                        << "> ";

                    getline(cin, input);
                    User.Name = input;

                    for (char c : User.Name) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znacích.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            ExitSetup = true;
                        }
                    }
                    if (ExitSetup == true) {
                        ExitSetup = false;
                        break;
                    }
                }

                // Setup Surname for user
                while (true) {
                    int i = 0;
                    cout << "Příjmení uživatele:" << endl 
                        << "> ";

                    getline(cin, input);
                    User.Surname = input;
                    
                    for (char c : User.Surname) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znacích.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            ExitSetup = true;
                        }
                    }
                    if (ExitSetup == true) {
                        ExitSetup = false;
                        break;
                    }
                }

                // Setup Username for user
                while (true) {
                    int i = 0;
                    cout << "Uživatelské jméno uživatele:" << endl 
                        << "> ";

                    getline(cin, input);
                    User.Username = input;
                    
                    for (char c : User.Surname) {
                        if (!isascii(c)) {
                            i++;
                            system("cls");
                            cout << "Zadávejte pouze ASCII znacích.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else {
                            ExitSetup = true;
                        }
                    }
                    if (ExitSetup == true) {
                        ExitSetup = false;
                        break;
                    }
                }

                // Setup password for user
                while (true) {
                    int i = 0;
                    cout << "Heslo pro uživatele: " << User.Username << endl 
                        << "> ";
                    
                    getline(cin, input);
                    User.Password = input;

                    for (char c : User.Password) {
                        if (!isascii(c)) {
                            i++;
                            cout << "Zadávejte pouze ASCII znaky.\n\n";
                            if (i == 1) {
                                break;
                            }
                        }
                        else if (User.Password.length() < 8) {
                            system("cls");
                            cout << "Krátké heslo." 
                                << endl << endl;
                        }
                        else {
                            ExitSetup = true;
                        }
                    }
                    if (ExitSetup == true) {
                        break;
                    }
                }
                if (ExitSetup == true) {
                    break;
                }
            }
            else if(input == "EN") {
                cout << "Sucsess!";
            }
        }
}



/*

MAIN PROGRAM of SmallOS

*/

int main() {
    using namespace std;

    setlocale(LC_ALL, "cs_CZ.utf8");

    Setup();
    Loading();
    
    // User type password
    while(true) {
        string b;
        if (SystemLang == "CZ") {
            cout << "Zadejte uživatelské jméno:" << endl;
            getline(cin, b);
            if(User.Username == b) {
                while(true) {
                    cout << "Zadejte heslo:" << endl;
                    getline(cin, b);

                    if (User.Password == b) {
                        system("cls");
                        cout << "Odemčeno!" << endl << endl;
                        // PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                        break;
                    }
                    else {
                        system("cls");
                        cout << "Špatné heslo, zadejte znovu." 
                            << endl 
                            << endl;
                        // PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                    }
                }
                break;
            }
            else {
                cout << "Neznámý uživatel." << endl;
            }
        }
        else if (SystemLang == "EN") {
            cout << "Enter password:\n";
            getline(cin, b);
            if (User.Password == b) {
                system("cls");
                cout << "Unlocked!" <<endl << endl;
                // PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
                break;
            }
            else {
                system("cls");
                cout << "Wrong password, enter password again." 
                    << endl 
                    << endl;
                // PlaySound(TEXT("Enter.wav"), NULL, SND_FILENAME | SND_SYNC);
            }
        }
    }

    if (SystemLang == "CZ") {
        cout << "Aplikaci SmallOS vytvořil Matygamicz" << endl 
            << "Vítej v \"oparačním systému\" " << OSName << ". Zadej příkaz \"help\" pro list příkazů..."
            << endl;
    }
    if (SystemLang == "EN") {
        cout << "SmallOS by Matygamic" << endl 
            << "welcome to terminal application " << OSName << ". Enter \"help\" for list of commands..."
            << endl;
    }

    while (true) {
        string command;

        SystemIO.CLine();

        getline(cin, command);

        if (command.empty()) {
            cout << endl;
        }
        else {
            Commands(command);
        }
    }

    return 0;
}

void Commands(std::string cmd/*, bool AppExit*/) {
    using namespace std;

    if (cmd == "poweroff") {
        cout << "Turning systen off...\n";
        exit(0);
    }
    else if (cmd == "restart") {
        cout << "Rebooting...\n\n";
        Loading();
        system("cls");
        cout << "Welcome back " << User.Username << "!"
            << endl 
            << endl;
    }

    // list of commands
    if (cmd == "help") {
        BaseApps.Help();
    }
    else if (cmd == "info") {
        BaseApps.Info(OSName, User.Name, User.Surname, User.Username);
        SystemIO.Beep();
    }
    else if (cmd == "clear") {
        system("cls");
        SystemIO.Beep();
    }
    else if (cmd == "users") {
        // BaseApps.Users();
    }
    else if (cmd == "") {
        // bla bla
    }
    else {
        SystemIO.Error();
    }
}