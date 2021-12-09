#include <iostream>
#include <cstring>
using namespace std;

void replacePI(char* s)
{
    if (strlen(s) <= 1)
        return;
    replacePI(s + 1);
    if (s[0] == 'p' && s[1] == 'i')
    {
        for (int i = strlen(s) + 2; i > 3; i--)
            s[i] = s[i - 2];
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
    }
}

int main()
{
    char s[100];
    cin >> s;
    replacePI(s);
    cout << s << "\n";
    return 0;
}