#include <iostream>
using namespace std;

int main()
{
    int t, n, Ai, x, i;
    cin >> t;
    while (t--)
    {
        x = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> Ai;
            x += Ai;
        }
        cout << x - ((n - 1) * (n - 2) / 2) << "\n";
    }
    return 0;
}