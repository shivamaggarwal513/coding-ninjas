#include <iostream>
using namespace std;

void insertionSort(int* &A, int &n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        for (j = i - 1; j >= 0 && A[j] > temp; j--)
                A[j + 1] = A[j];
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
        insertionSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}