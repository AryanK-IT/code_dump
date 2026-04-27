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

int main()
{
    int day;
    cout << "Enter a Number: ";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "\n\nmonday";
        break;
    case 2:
        cout << "\ntuesday";
        break;
    case 3:
        cout << "\nwednesday";
        break;
    case 4:
        cout << "\nthursday";
        break;
    case 5:
        cout << "\nfriday";
        break;
    case 6:
        cout << "\nsaturday";
        break;
    case 7:
        cout << "\nsunday";
        break;
    default:
        cout << "Invalid";
    }
    return 0;
}