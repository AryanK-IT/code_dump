#include <bits/stdc++.h>

#include <map>
using namespace std;

void explainPair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << "\n";

    pair<int, pair<int, int>> p = {1, {2, 3}};
    cout << p.first << " " << p.second.second << " " << p.second.first << "\n";

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << arr[1].second;
}

void explainVector() {
    // vector is a container which is dynamic in nature

    vector<int> v;      // here we created an empty container { }
    v.push_back(1);     // this added 1 to the container {1}
    v.emplace_back(2);  // this fucntion is also similar to push_back but it is
                        // faster than it, and here we added

    vector<pair<int, int>> vec;  // created a vector of pair datatype
    vec.push_back({1, 2});       // input has a curly brace "{}"
    vec.emplace_back(1, 2);      // here the emplace_back funtion automatically assumes
                                 // that the input is a pair so "{}" is not needed

    vector<int> v01(5, 10);  // here a conatainer of size 5 is declared with all
                             // instances being 10, {10, 10, 10, 10, 10}
    vector<int> v02(5);      // here a container of size 5 is declared but with
                             // instances are 0 or any garbage value
    vector<int> v03(5, 20);
    vector<int> v04(v03);  // this creates a container v04 which is a copy of v03

    vector<int> vect = {10, 20, 30, 40};

    vector<int>::iterator it1 =
        vect.begin();        // vect.begin() points to the memory address of the first
                             // element of the vector.
    cout << *(it1) << "\n";  // we use (*) the dereference operator to access the
                             // element at memory address it
    it1++;
    cout << *(it1) << "\n";

    vector<int>::iterator it2 =
        vect.end();  // here vect.end() points to the memory location after 40

    vector<int>::reverse_iterator it3 =
        vect.rend();  // reverse end, reverses the vector and then points to the
                      // memory before it which in this case is before 10, [here,
                      // {10,20,30,40}]
    vector<int>::reverse_iterator it4 =
        vect.rbegin();  // reverse begin points to 40 and it++ will move to 30

    cout << v[0] << " " << vect.at(0);
    cout << vect.back()
         << " ";  // points to the element at the back, which is 40 in this case
    cout << "\n\n";

    cout << "printing the vector : \n";
    for (int i = 0; i < 4; i++) {
        cout << vect[i] << " ";
    }

    cout << "printing the vector using iterator : \n";
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++) {
        cout << *(it) << " ";
    }

    cout << "\n\n";
    for (auto it = vect.begin(); it != vect.end(); it++) {
        cout << *(it) << " ";
    }

    cout << "\n\n";
    for (auto it : vect) {
        cout << it << " ";
    }

    // .erase() method takes an address as an argument and deletes it
    vect.erase(vect.begin() + 1);  // here 20 gets deleted

    vect.emplace_back(50);
    vect.emplace_back(60);
    vect.emplace_back(70);

    // currentlt vect = [ 10 30 40 50 60 70 ]
    // if i want to remove 30 to 50 we use .erase() method with range as argument

    vect.erase(vect.begin() + 1, vect.begin() + 4);  // .erase(start, end)

    // currentlt vect = [ 10 60 70 ]

    vector<int> v2(2, 100);           // [100,100]
    v2.insert(v.begin(), 300);        // .insert(address, value) -> [300,100,100]
    v2.insert(v.begin() + 1, 2, 10);  //  [300,10,10,100,100]

    vector<int> copy(2, 50);                         // [50,50]
    v2.insert(v.begin(), copy.begin(), copy.end());  // [50,50,300,10,10,100,100]

    cout << v2.size();  // 7

    v2.swap(vect);         // swaps v2 with vect
    v2.clear();            // clears the vector to make it an empty vector
    cout << vect.empty();  // tells if the vector isEmpty or not (true or false)
}

void explainList() {
    list<int> ls;

    // insert method in a vector is very costy
    // a doubly linked-list is maintained for a list whereas a singly linked list is maintained for a vector

    ls.push_back(2);     // [2]
    ls.emplace_back(4);  //[2,4]
    ls.push_front(5);    // [5,2,4]this method is very cheap in terms of time complexity
    ls.emplace_front(10);
}

void explainStack() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);     // [3,3,2,1]
    st.emplace(5);  // [5,3,3,2,1]

    cout << st.top();  // 5
    st.pop();          // removes 5

    cout << st.size();
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);  // [1,2,4]

    q.back() += 5;      //[1,2,9]
    cout << q.back();   // prints 9
    cout << q.front();  // prints 1

    q.pop();  // [2,9]
    // size swap empty same as stack
}

void explainPriorityQueue() {
    // a tree is maintained for a priority queue even tho it might look linear
    // also known as max-heap
    priority_queue<int> pq;

    pq.push(5);      // [5]
    pq.push(2);      // [5,2]
    pq.push(8);      // [8,5,2]
    pq.emplace(10);  // [10,8,5,2]

    cout << pq.top();  // prints 10

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);      // [5]
    pq1.push(2);      // [2,5]
    pq1.push(8);      // [2,5,8]
    pq1.emplace(10);  // [2,5,8,10]

    cout << pq1.top();  // prints 2
}

void explainSet() {
    // a set has two rules : it is always sorted and all its elements are unique
    // even here a tree is maintained
    // every action takes logarithimic time complexity
    set<int> st;

    st.insert(1);  // [1]
    st.emplace(2);
    st.insert(2);  // [1,2]
    st.insert(4);
    st.insert(3);  // [1,2,3,4]

    auto it1 = st.find(3);  // the find method returns an iterator that points to 3 in the set
    auto it2 = st.find(6);  // here because 6 does not exist so the iterator points to the end of the list or st.end()

    st.erase(4);  // erases 4 from the set and takes logarithimic time

    int cnt = st.count(1);

    auto it3 = st.find(2);
    auto it4 = st.find(4);
    st.erase(it1, it2);

    auto it5 = st.lower_bound(2);
    auto it6 = st.upper_bound(3);
}

void explainMultiset() {
    // same as set but it can have multiple instances of the same element

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);  // [1,1,1]

    ms.erase(1);  // [] all 1's are erased

    int cnt = ms.count(1);
    auto it = ms.find(1);
    advance(it, 2);
    ms.erase(ms.find(1));  // only a single one is erased
    ms.erase(ms.find(1), it);
}

void explainUnorderedSet() {
    // very similar to set but it just dosent store in sorted order
    // has unique / distinct elements
    // all operations are same as set but lower_bound and upper_bound does not work
    // all operations are of O(n) time complexity
}

void explainMap() {
    // unique keys are stored and are ordered
    map<int, int> mpp1;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp;

    // --- Inserting into a map with pair keys ---
    mpp[{1, 0}] = 2;
    mpp.emplace(make_pair(3, 1), 5);
    mpp.insert({{2, 4}, 8});
    mpp[{2, 4}] = 10;  // This overwrites the 8 with 10 for the key {2,4}

    cout << "Printing mpp:\n";
    for (auto it : mpp) {
        cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
    }

    // --- Working with a map with integer keys (mpp1) ---
    mpp1[1] = 100;  // Adding some dummy data to mpp1 so we can search it
    mpp1[3] = 300;
    mpp1[5] = 500;

    cout << "\nAccessing mpp1:\n";
    cout << mpp1[1] << "\n";  // Prints 100
    cout << mpp1[5] << "\n";  // Prints 500

    // Using .find()
    auto it = mpp1.find(3);
    if (it != mpp1.end()) {          // Always good practice to check if it was actually found!
        cout << it->second << "\n";  // Correct syntax: it->second
    }

    auto it2 = mpp1.find(5);  // Points to the element with key 5

    // Using lower_bound and upper_bound
    auto it3 = mpp1.lower_bound(2);
    auto it4 = mpp1.upper_bound(3);

    // erase, swap, size, empty are the same as above
}

void explainMultiMap() {
    // evrything is same as map but the only difference here is that it can store multiple keys
    // only mpp[key] cannot be used here
}

void explainUnorderedMap() {
    // same as set and unordered_set difference
    //  even here the time complexity will be O(1)
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // they are same
    if (p1.first > p2.first) return true;
    return false;
}

void explainExtra() {
    int a[] = {1, 5, 3, 2};
    vector<int> v = {6, 2, 7, 3, 9, 5};

    sort(a, a + 4);
    sort(v.begin(), v.end());  // for vectors
    sort(a + 2, a + 4);
    sort(a, a + 4, greater<int>());  // sorts it in descending order using the comparator (greater<int>)

    pair<int, int> aa[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same,then sort
    // it according to first element but in descending

    sort(aa, aa + 3, comp);  // here comp is a custom comparator

    int num = 7;                        // is  111 in binary
    int cnt = __builtin_popcount(num);  // returns number of set bits, which is 3 in this case

    long long num2 = 815462347231328;
    int cnt2 = __builtin_popcountll(num2);

    cout << cnt << endl;
    cout << cnt2 << endl;

    string s = "123";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));  // prints all permutations of a string, but only if starts from the first permutation in textbook order

    int max = *max_element(a, a + 4);  // gives address of maximum element
    int max = *min_element(a, a + 4);  // gives address of minimum element
}

int main() { explainExtra(); }

// cpp stl is divided into 4 parts
// Algorithms
// Containers
// Funcrions
// Iterators

// pairs is a part of utility library
// vectors are the first container that we learn, it is foundation of all other
// containers