#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

/*
int main()
{
    int age;
    cin >> age;

    if (age <= 18)
        cout << "You are a minor";
    else
        cout << "You are not a minor";
    return 0;
}
*/

int main()
{
    int marks;
    cout << "Enter your marks: ";
    cin >> marks;

    if (marks >= 80)
    {
        cout << "\nYour grade is A.";
    }
    else if (marks >= 60)
    {
        cout << "\nYour grade is B.";
    }
    else if (marks >= 50)
    {
        cout << "\nYour grade is C.";
    }
    else if (marks >= 45)
    {
        cout << "\nYour grade is D.";
    }
    else if (marks >= 25)
    {
        cout << "\nYour grade is E.";
    }
    else
    {
        cout << "\nYour grade is F.";
    }

    return 0;
}