#include <iostream>
using namespace std;

void removeDup(char* s)
{
    if (s[0] == '\0')
        return;
    removeDup(s + 1);
    if (s[0] == s[1])
        for (int i = 0; s[i] != '\0'; i++)
            s[i] = s[i + 1];
}

int main()
{
    char s[100];
    cin >> s;
    removeDup(s);
    cout << s;
    return 0;
}