#include <iostream>
#include <string>


using namespace std;

class SystemApps {
    public:
        void Help() {
            cout << "----- I can help you! -----" << endl << endl
                << "- poweroff\t(vypne se systém)" << endl
                << "- reboot\t(restartuje systém)" << endl
                << "- clear\t\t(odstraní předchozí výstup operačního systému)" << endl
                << "- info\t\t(vypíše informace ze systému a uživateli)" << endl
                << "- settings\t(nastavení systému)" << endl
                << "- files\t\t(ukáže soubory a jak s nimi pracovat)" << endl
                << "- learn\t\t(učit)"
                << endl << endl << endl;
        }

        void Info(string OSName, string User_Name, string User_Surname, string User_Username) {
            cout << "----- Basic information -----" << endl << endl
                << "Název zařízeni : " << OSName << endl
                << "Jméno uživatele : " << User_Name << " " << User_Surname << endl
                << "Uživatelské jméno: " << User_Username << endl
                << "-----------------------------"
                << endl << endl << endl;
        }

        void EasterEgg() {
            cout << "";
        }
};

SystemApps BaseApps;