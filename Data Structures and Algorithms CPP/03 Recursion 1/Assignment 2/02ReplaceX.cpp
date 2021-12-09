#include <iostream>
#include <cstring>
using namespace std;

void removeX(char* s)
{
    if (strlen(s) < 1)
        return;
    removeX(s + 1);
    if (s[0] == 'x')
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            s[i] = s[i + 1];
    }
}

int main()
{
    char s[1000];
    cin >> s;
    removeX(s);
    cout << s << "\n";
    return 0;
}