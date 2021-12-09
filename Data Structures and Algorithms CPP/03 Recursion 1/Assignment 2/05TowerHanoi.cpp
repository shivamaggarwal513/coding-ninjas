#include <iostream>
using namespace std;

void towerOfHanoi(int n, char s = 'a', char a = 'b', char d = 'c')
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, s, d, a);
    cout << s << " " << d << "\n";
    towerOfHanoi(n - 1, a, s, d);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n);
    return 0;
}