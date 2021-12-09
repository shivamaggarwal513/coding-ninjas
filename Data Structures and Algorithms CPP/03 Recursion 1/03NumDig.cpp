#include <iostream>
using namespace std;

int numDigits(int n)
{
    if (n < 10)
        return 1;
    return 1 + numDigits(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << numDigits(n) << "\n";
    return 0;
}