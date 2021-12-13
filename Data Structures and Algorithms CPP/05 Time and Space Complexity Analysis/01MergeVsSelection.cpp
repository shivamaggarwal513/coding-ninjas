#include <iostream>
#include <chrono>
#include <ctime>
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

void selectionSortTime(int* &A, int &n)
{
    auto start = chrono::system_clock::now();
    selectionSort(A, n);
    auto end = chrono::system_clock::now();
    chrono::duration<double> seconds = end - start;
    cout << seconds.count();
}

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

void mergeSortTime(int* &A, int &n)
{

    auto start = chrono::system_clock::now();
    mergeSort(A, 0, n - 1);
    auto end = chrono::system_clock::now();
    chrono::duration<double> seconds = end - start;
    cout << seconds.count();
}

int main()
{
    int* arr = new int[10e6];
    cout << "n \t\tMerge Sort \t Selection Sort \n";
    for (int n = 10; n <= 1e6; n *= 10)
    {
        cout << n << " \t\t";
        for(int i = 0; i < n; i++)
            arr[i] = n - i;
        mergeSortTime(arr, n);
        cout << " \t";

        for(int i = 0; i < n; i++)
            arr[i] = n - i;
        selectionSortTime(arr, n);
        cout << " \n";
    } // for n = 1e6, selection sort took 15 minutes
    delete []arr;
    return 0;
}