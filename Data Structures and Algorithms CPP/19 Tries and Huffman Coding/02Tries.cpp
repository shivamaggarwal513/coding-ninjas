#include <iostream>
#include <string>
#include "01Tries.h"
using namespace std;

int main()
{
    string w1 = "are", w2 = "and", w3 = "dot";
    Trie dict;
    dict.insert(w1);
    dict.insert(w2);
    dict.insert(w3);
    cout << (dict.search(w2) ? "true" : "false") << " ";
    dict.erase(w2);
    cout << (dict.search(w2) ? "true" : "false") << "\n";
    return 0;
}