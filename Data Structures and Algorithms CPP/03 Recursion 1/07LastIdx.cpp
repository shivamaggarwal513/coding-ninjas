#include <iostream>
using namespace std;

int search(int* arr, int n, int x)
{
    if (n == 0)
        return -1;
    
    int small = search(arr + 1, n - 1, x);
    if (small != -1)
        return small + 1;
    else if (arr[0] == x)
        return 0;
    else
        return -1;
}

int main()
{
    int n, x;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << search(arr, n, x) << "\n";
    return 0;
}