#include <iostream>
using namespace std;

void pushZeroes(int* &A, int &n)
{
    int i = 0, j = 0;
    while (i < n)
        A[i] != 0
            ? A[j++] = A[i++]
            : i++;
    while (j < n)
        A[j++] = 0;
}

int main()
{
    int t, n; 
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> *(arr + i);
        pushZeroes(arr, n);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}