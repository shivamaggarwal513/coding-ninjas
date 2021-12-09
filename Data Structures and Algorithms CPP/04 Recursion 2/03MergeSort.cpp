#include <iostream>
using namespace std;

void mergeSorted(int* A, int start, int mid, int end)
{
    int i1, i2, i;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* A1 = new int[n1];
    int* A2 = new int[n2];

    for (i1 = 0; i1 < n1; i1++)
        A1[i1] = A[start + i1];
    for (i2 = 0; i2 < n2; i2++)
        A2[i2] = A[mid + 1 + i2];
    
    i1 = 0; i2 = 0; i = start;

    while (i1 < n1 && i2 < n2)
        A[i++] = A1[i1] <= A2[i2] ? A1[i1++] : A2[i2++];
    
    while (i1 < n1)
        A[i++] = A1[i1++];
    while (i2 < n2)
        A[i++] = A2[i2++];
    
    delete []A1;
    delete []A2;
}

void mergeSort(int* A, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(A, start, mid);
    mergeSort(A, mid + 1, end);

    mergeSorted(A, start, mid, end);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    delete []arr;
    return 0;
}