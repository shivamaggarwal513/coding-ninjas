#include <iostream>
using namespace std;

int multiply(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    return m + multiply(m, n - 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiply(m, n) << "\n";
    return 0;
}