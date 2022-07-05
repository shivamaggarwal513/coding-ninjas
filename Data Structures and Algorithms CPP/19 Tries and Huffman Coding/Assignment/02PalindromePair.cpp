#include <iostream>
#include <algorithm>
#include <string>
#include "..\01Tries.h"
using namespace std;

bool isPairPalindrome(string *words, int n)
{
    string rev;
    Trie dict;
    for (int i = 0; i < n; i++)
        dict.insert(words[i]);
    for (int i = 0; i < n; i++)
    {
        rev = words[i];
        rev.pop_back();
        reverse(rev.begin(), rev.end());
        if (dict.search(rev))
            return true;
        rev.insert(0, 1, words[i].back());
        if (dict.search(rev))
            return true;
        rev.insert(0, 1, 'a');
        for (; rev[0] <= 'z'; rev[0]++)
            if (dict.search(rev))
                return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    string *words = new string[n];
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cout << (isPairPalindrome(words, n) ? "true" : "false") << "\n";
    delete []words;
    return 0;
}