#include <iostream>
using namespace std;

void rotateArr(int* A, int n, int d)
{
    int i;
    int* tA = new int[d];
    for (i = 0; i < d; i++)
        tA[i] = A[i];
    for (i = d; i < n; i++)
        A[i - d] = A[i];
    for (i = 0; i < d; i++)
        A[n - d + i] = tA[i];
    delete []tA;
}

int main()
{
    int t, n, i, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cin >> d;
        rotateArr(arr, n, d);
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
        delete []arr;
    }
    return 0;
}