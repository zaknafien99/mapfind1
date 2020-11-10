// mapfind1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This example shows how to use the global find_if() algorithm to find an
// element with a certain value (in contrast to finding a key with a certain value):

#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    // map with floats as key and value
    // - initializing keys and values are automatically converted to float
    map<float, float> coll = { {1,7},{2,4},{3,2},{4,3},{5,6},{6,1},{7,3} };

    // search an element with key 3.0 (logarithmic complexity)
    auto posKey = coll.find(3.0);
    if (posKey != coll.end()) {
        cout << "key 3.0 found ("
            << posKey->first << ":"
            << posKey->second << ")" << endl;
    }

    // search an element with value 3.0 (linear complexity)
    auto posVal = find_if(coll.begin(), coll.end(),
        [](const pair<float, float>& elem) {
            return elem.second == 3.0;
        });
    if (posVal != coll.end()) {
        cout << "value 3.0 found ("
            << posVal->first << ":"
            << posVal->second << ")" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
