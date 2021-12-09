#include <iostream>
using namespace std;

int* mergeSorted(int* &A1, int* &A2, int &n1, int &n2)
{
    int i1 = 0, i2 = 0, i = 0;
    int* A = new int[n1 + n2];

    while (i1 < n1 && i2 < n2)
        A1[i1] > A2[i2]
            ? A[i++] = A2[i2++]
            : A[i++] = A1[i1++];

    if (i1 == n1)
        while (i2 < n2)
            A[i++] = A2[i2++];
    else
        while (i1 < n1)
            A[i++] = A1[i1++];

    return A;
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int* arr1 = new int[n];
        int* arr2 = new int[m];
        for (int i = 0; i < n; i++)
            cin >> *(arr1 + i);
        for (int i = 0; i < m; i++)
            cin >> *(arr2 + i);
        int* arr = mergeSorted(arr1, arr2, n, m);
        for (int i = 0; i < n + m; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}