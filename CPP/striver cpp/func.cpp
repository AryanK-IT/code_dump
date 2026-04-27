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

void printName(string name)
{
    cout << "Hey " << name;
}

void printArray(int arr[], int n)
{
    arr[0] += 100;
    cout << arr[0];
}

int main()
{
    int n = 5;
    int arr[n];
    
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    printArray(arr, n);

    return 0;
}