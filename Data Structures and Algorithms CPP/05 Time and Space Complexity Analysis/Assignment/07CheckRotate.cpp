#include <iostream>
using namespace std;

int checkRotate(int* A, int n)
{
    int i = 0;
    while (i < n)
    {
        i++;
        if (A[i - 1] > A[i])
            break;
    }
    return i % n;
}

int main()
{
    int t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cout << checkRotate(arr, n) << "\n";
        delete []arr;
    }
    return 0;
}