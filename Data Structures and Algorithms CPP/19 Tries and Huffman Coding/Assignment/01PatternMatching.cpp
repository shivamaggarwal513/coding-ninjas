#include <iostream>
#include <string>
#include "..\03SuffixTries.h"
using namespace std;

bool isPatternPresent(string *words, int n, string pattern)
{
    SuffixTrie s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < words[i].size(); j++)
            s.insert(words[i].substr(j));
    return s.search(pattern);
}

int main()
{
    int n;
    cin >> n;
    string *words = new string[n], pattern;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> pattern;
    cout << (isPatternPresent(words, n, pattern) ? "true" : "false") << "\n";
    delete []words;
    return 0;
}