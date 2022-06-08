#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(int* A, int n)
{
    sort(A, A + n);
    int max = A[0] * n, temp;
    for (int i = 1; i < n; i++)
    {
        temp = A[i] * (n - i);
        if (max < temp)
            max = temp;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxProfit(arr, n) << "\n";
    return 0;
}