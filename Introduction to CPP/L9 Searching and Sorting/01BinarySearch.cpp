#include <iostream>
using namespace std;

int binSearch(int* &A, int &n, int &k)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (*(A + mid) == k)
            return mid;
        else if (*(A + mid) > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int n, t, k; 
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> *(arr + i);
    cin >> t;
    while (t--)
    {
        cin >> k;
        cout << binSearch(arr, n, k) << "\n";
    }
    return 0;
}