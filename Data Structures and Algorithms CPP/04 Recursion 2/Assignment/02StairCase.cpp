#include <iostream>
using namespace std;

int stairCase(int n)
{
    if (n <= 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return stairCase(n - 1) + stairCase(n - 2) + stairCase(n - 3);
}

int main()
{
    int n;
    cin >> n;
    cout << stairCase(n) << "\n";
    return 0;
}