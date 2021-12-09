#include <iostream>
#include <cstring>
using namespace std;

void pairStar(char* s)
{
    if (strlen(s) == 0)
        return;
    pairStar(s + 1);
    if (s[0] == s[1])
    {
        for (int i = strlen(s) + 1; i > 1; i--)
            s[i] = s[i - 1];
        s[1] = '*';
    }
}

int main()
{
    char s[2000];
    cin >> s;
    pairStar(s);
    cout << s;
    return 0;
}