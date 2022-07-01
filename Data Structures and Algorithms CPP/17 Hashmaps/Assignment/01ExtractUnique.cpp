#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string extractUnique(string &s)
{
    string ans;
    unordered_map<char, int> seenMap;
    for (char &ch: s)
    {
        if (seenMap.find(ch) == seenMap.end())
        {
            ans.push_back(ch);
            seenMap[ch]++;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << extractUnique(s) << "\n";
    return 0;
}