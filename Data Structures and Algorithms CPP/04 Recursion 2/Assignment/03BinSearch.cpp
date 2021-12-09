#include <iostream>
using namespace std;

int binarySearch(int* A, int start, int end, int key)
{
    if (start > end)
        return -1;
    
    int mid = start + (end - start) / 2;

    if (A[mid] == key)
        return mid;
    else if (A[mid] > key)
        return binarySearch(A, start, mid - 1, key);
    else
        return binarySearch(A, mid + 1, end, key);
}

int main()
{
    int n, x;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;

    cout << binarySearch(arr, 0, n - 1, x) << "\n";

    delete []arr;
    return 0;
}