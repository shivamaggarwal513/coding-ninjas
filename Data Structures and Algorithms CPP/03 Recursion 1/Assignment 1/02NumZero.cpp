#include <iostream>
using namespace std;

int numZeroes(int n)
{
    if (n == 0)
        return 1;
    else if (n < 10)
        return 0;
    else if (n % 10 == 0)
        return 1 + numZeroes(n / 10);
    return numZeroes(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << numZeroes(n) << "\n";
    return 0;
}