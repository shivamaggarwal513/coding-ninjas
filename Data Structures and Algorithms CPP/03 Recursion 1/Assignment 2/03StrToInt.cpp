#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int strToInt(char* s)
{
    int len = strlen(s);
    if (len == 1)
        return s[0] - '0';
    return strToInt(s + 1) + pow(10, len - 1) * (s[0] - '0');
}

int main()
{
    char s[10];
    cin >> s;
    int n = strToInt(s);
    cout << n;
    return 0;
}