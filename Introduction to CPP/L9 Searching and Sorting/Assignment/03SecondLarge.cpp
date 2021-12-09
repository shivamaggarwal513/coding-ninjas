#include <iostream>
using namespace std;
#define INT_MIN -2147483647 - 1

int secondLarge(int* &A, int &n)
{
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max1)
        {
            max2 = max1;
            max1 = A[i];
        }
        else if (A[i] > max2 && A[i] != max1)
            max2 = A[i];
    }
    
    return max2;
}

int main()
{
    int t, n, s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> *(arr + i);
        s = secondLarge(arr, n);
        cout << s << "\n";
    }
    return 0;
}