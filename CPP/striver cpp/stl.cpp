#include <bits/stdc++.h>
using namespace std;

void explainPair()
{
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << "\n";

    pair<int, pair<int, int>> p = {1, {2, 3}};
    cout << p.first << " " << p.second.second << " " << p.second.first << "\n";

    pair<int, int> arr[] = {{1, 2},
                            {3, 4},
                            {5, 6}};

    cout << arr[1].second;
}

void explainVector()
{
    /// vector is a container which is dynamic in nature

    vector<int> v;     /// here we created an empty container { }
    v.push_back(1);    /// this added 1 to the container {1}
    v.emplace_back(2); /// this fucntion is also similar to push_back but it is faster than it, and here we added

    vector<pair<int, int>> vec; /// created a vector of pair datatype
    vec.push_back({1, 2});      /// input has a curly brace "{}"
    vec.emplace_back(1, 2);     /// here the emplace_back funtion automatically assumes that the input is a pair so "{}" is not needed

    vector<int> v1(5, 10); /// here a conatainer of size 5 is declared with all instances being 10, {10, 10, 10, 10, 10}
    vector<int> v2(5);     /// here a container of size 5 is declared but with instances are 0 or any garbage value
    vector<int> v3(5, 20);
    vector<int> v4(v3); /// this creates a container v4 which is a copy of v3

    vector<int> vect = {10, 20, 30, 40};

    vector<int>::iterator it1 = vect.begin(); /// vect.begin() points to the memory address of the first element of the vector.
    cout << *(it1) << "\n";                   /// we use (*) the dereference operator to access the element at memory address it
    it1++;
    cout << *(it1) << "\n";

    vector<int>::iterator it2 = vect.end(); /// here vect.end() points to the memory location after 40

    vector<int>::reverse_iterator it3 = vect.rend();   /// reverse end, reverses the vector and then points to the memory before it which in this case is before 10, [here, {10,20,30,40}]
    vector<int>::reverse_iterator it4 = vect.rbegin(); /// reverse begin points to 40 and it++ will move to 30

    cout << v[0] << " " << vect.at(0);
    cout << vect.back() << " "; /// points to the element at the back, which is 40 in this case
    cout << "\n\n";

    cout << "printing the vector : \n";
    for (int i = 0; i < 4; i++)
    {
        cout << vect[i] << " ";
    }

    cout << "printing the vector using iterator : \n";
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << "\n\n";
    for (auto it = vect.begin(); it != vect.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << "\n\n";
    for (auto it : vect)
    {
        cout << it << " ";
    }

    
}
int main()
{
    explainVector();
}

/// cpp stl is divided into 4 parts
/// Algorithms
/// Containers
/// Funcrions
/// Iterators

/// pairs is a part of utility library
/// vectors are the first container that we learn, it is foundation of all other containers