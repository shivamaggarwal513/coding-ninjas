#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int* A, int n, int k)
{
    int i1 = 0, i2 = n - 1, pairs = 0;
    sort(A, A + n);
    while (i1 < i2)
    {
        if (A[i1] + A[i2] == k)
        {
            int c1 = 1, c2 = 1;
            i1++; i2--;
            if (i1 >= i2)
            { pairs++; break; }
            while (A[i1] == A[i1 - 1])
            { c1++; i1++; }
            while (A[i2] == A[i2 + 1])
            { c2++; i2--; }
            pairs += c1 * c2;
        }
        else if (A[i1] + A[i2] > k)
            i2--;
        else
            i1++;
    }
    return pairs;
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << pairSum(arr, n, k) << "\n";
        delete []arr;
    }
    return 0;
}