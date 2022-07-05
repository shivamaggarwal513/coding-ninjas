#include <iostream>
#include <vector>
#include <string>
#include "..\01Tries.h"
using namespace std;

vector<string> autoComplete(string *words, int n, string word)
{
    vector<string> ans;
    Trie dict;
    for (int i = 0; i < n; i++)
        dict.insert(words[i]);
    TrieNode *x = dict.searchWord_startsWith(word);
    dict.fillWords(x, ans, word);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string *words = new string[n], word;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> word;
    vector<string> ans = autoComplete(words, n, word);
    for (string &x: ans)
        cout << x << "\n";
    delete []words;
    return 0;
}