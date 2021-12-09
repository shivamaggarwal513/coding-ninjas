#include <iostream>
#include <cmath>
using namespace std;

float geometricSum(int k)
{
    if (k == 0)
        return 1.0;
    return (1.0 / pow(2.0, k)) + geometricSum(k - 1);
}

int main()
{
    int k;
    cin >> k;
    cout << geometricSum(k) << "\n";
    return 0;
}