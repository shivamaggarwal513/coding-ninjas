#include <iostream>
#include <cstring>
using namespace std;

bool recurPalin(char* s, int len)
{
    if (len == 0 || len == 1)
        return true;
    else if (s[0] != s[len - 1])
        return false;
    return recurPalin(s + 1, len - 2);
}

int main()
{
    char s[1000];
    cin >> s;
    cout << (recurPalin(s, strlen(s)) ? "true" : "false") << "\n";
    return 0;
}