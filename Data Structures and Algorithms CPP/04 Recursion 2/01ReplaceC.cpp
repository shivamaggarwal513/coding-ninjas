#include <iostream>
using namespace std;

void replaceC(char* s, char& c1, char& c2)
{
    if (s[0] == '\0')
        return;
    replaceC(s + 1, c1, c2);
    if (s[0] == c1)
        s[0] = c2;
}

int main()
{
    char s[100], c1, c2;
    cin >> s;
    cin.clear();
    cin >> c1 >> c2;
    replaceC(s, c1, c2);
    cout << s;
    return 0;
}