#include <iostream>
#include <string>
using namespace std;

bool checkABRec(string s)
{
    if (s[0] == '\0')
        return true;
    
    if (s[0] == 'a' && 
    (s[1] == '\0' || 
    s[1] == 'a' || 
    (s[1] == 'b' && s[2] == 'b')))
        return checkABRec(s.substr(1));
    
    else if (s[0] == 'b' && s[1] == 'b' && 
    (s[2] == '\0' || s[2] == 'a'))
        return checkABRec(s.substr(2));
    
    return false;
}

bool checkAB(string s)
{
    if (s[0] == '\0')
        return true;
    else if (s[0] != 'a')
        return false;
    return checkABRec(s);
}

int main()
{
    string s;
    cin >> s;
    cout << (checkAB(s) ? "true" : "false") << "\n";
    return 0;
}