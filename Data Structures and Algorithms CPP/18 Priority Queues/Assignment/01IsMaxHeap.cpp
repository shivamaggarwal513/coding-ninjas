#include <iostream>
using namespace std;

bool isMaxHeap(int *arr, int n)
{
    for (int cI = 1; cI < n; cI++)
        if (arr[(cI - 1) / 2] < arr[cI])
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << (isMaxHeap(arr, n) ? "true" : "false") << "\n";
    delete []arr;
    return 0;
}