#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int age;
    string name;

    cout << "Enter your age : ";
    cin >> age;

    cin.ignore();

    cout << "You are " << age << " Years old." << endl;

    cout << "Enter your Name : ";
    getline(cin, name);
    cout << "Hello " << name << endl;

    return 0;
}

// Numbers

// int main()
// {
//     cout << 5 + 7 << endl;
//     cout << pow(2, 20) << endl;
//     cout << fmax(3,10) << endl;

//     return 0;
// }

// strings

// int main(int argc, char const *argv[])
// {
//     string phrase = "Hello \nWorld";

//     cout << phrase << endl;

//     cout << phrase.length() << endl;
//     cout << phrase.find("World", 0) << endl;
//     cout << phrase.substr(6, 3) << endl;

//     cout << phrase[0] << endl;
//     cout << phrase[4] << endl;

//     return 0;
// }

// Data types

// int main(int argc, char const *argv[])
// {
//     char grade = 'A';
//     string phrase = "Hello World";
//     int age = 50;
//     double gpa = 2.4;
//     bool answer = true;

//     return 0;
// }

// Variables

// int main(int argc, char const *argv[])
// {
//     string charName = "john";
//     int charAge;
//     charAge =35;

//     cout << "There once was a man named " << charName << endl;
//     cout << "he was " << charAge << " yeras old" << endl;
//     cout << "he liked the name " << charName << endl;
//     cout << "but he did not like being " << charAge << endl;

//     return 0;
// }
