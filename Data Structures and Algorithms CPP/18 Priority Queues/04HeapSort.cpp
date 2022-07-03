#include <iostream>
#include <utility>
using namespace std;

template <typename T>
int parentChildMin(T *arr, int &n, int &pI)
{
    int min = pI, lC = 2 * pI + 1, rC = 2 * pI + 2;
    if (lC < n && arr[lC] < arr[min])
        min = lC;
    if (rC < n && arr[rC] < arr[min])
        min = rC;
    return min;
}

template <typename T>
void heapSort(T *arr, int n)
{
    int i, cI, pI;
    for (i = 0; i < n; i++)
    {
        cI = i, pI = (cI - 1) / 2;
        while (cI > 0 && arr[cI] < arr[pI])
        {
            swap(arr[cI], arr[pI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        pI = 0, cI = parentChildMin(arr, i, pI);
        while (cI != pI)
        {
            swap(arr[pI], arr[cI]);
            pI = cI;
            cI = parentChildMin(arr, i, pI);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    delete []arr;
    return 0;
}