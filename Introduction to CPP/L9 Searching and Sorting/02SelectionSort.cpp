#include <iostream>
using namespace std;

void selectionSort(int* &A, int &n)
{
    int min, temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (A[min] > A[j])
                min = j;
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
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
        selectionSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}