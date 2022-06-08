#include <iostream>
#include <string>
using namespace std;

bool ScontainT(string s, string t)
{
    if (t.empty())
        return true;
        
    size_t i = s.find(t[0]);
    if (i != string::npos)
        return ScontainT(s.substr(i), t.substr(1));
    return false;
}

int main()
{
    string s, t;
    cin >> s;
    cin.ignore();
    cin >> t;
    cout << (ScontainT(s, t) ? "true" : "false") << "\n";
    return 0;
}