#include <iostream>
using namespace std;

int sumDigits(int n)
{
    if (n / 10 == 0)
        return 1;
    return 1 + sumDigits(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << sumDigits(n) << "\n";
    return 0;
}