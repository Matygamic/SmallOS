#include <iostream>
#include <string>

using namespace std;

bool Exit = false;

class ClassUser {
    public:
        string Username;
        string Name;
        string Surname;
        string Password;
        
    public:
        ClassUser (string a, string b, string c, string d) {
            Username = a;
            Name = b;
            Surname = c;
            Password = d;
        }

};

ClassUser User("", "", "", "");