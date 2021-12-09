#include <iostream>
using namespace std;

void bubbleSort(int* &A, int &n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
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
        bubbleSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}