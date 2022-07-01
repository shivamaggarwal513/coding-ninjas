#include <iostream>
#include "07HashMaps.h"
using namespace std;

int main()
{
    HashMaps<int> mp;
    for (int i = 0; i < 10; i++)
    {
        mp.insert("abc" + to_string(i), i + 1);
        cout << mp.loadFactor() << " ";
    }
    cout << "\n" << mp.size() << " ";
    cout << mp.erase("abc2") << " ";
    cout << mp.erase("abc7") << " ";
    cout << mp.size() << "\n";
    for (int i = 0; i < 10; i++)
        cout << mp.at("abc" + to_string(i)) << " ";
    cout << "\n";
    return 0;
}