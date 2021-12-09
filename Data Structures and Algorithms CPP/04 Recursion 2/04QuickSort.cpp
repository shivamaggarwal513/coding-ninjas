#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int quickPartition(int* A, int start, int end) 
{
    int p = A[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
        if (A[j] < p)
            swap(A[++i], A[j]);
    
    swap(A[i + 1], A[end]);

    return i + 1;
}

void quickSort(int* A, int start, int end)
{
    if (start >= end)
        return;
    int pivot = quickPartition(A, start, end);

    quickSort(A, start, pivot - 1);
    quickSort(A, pivot + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    delete []arr;
    return 0;
}