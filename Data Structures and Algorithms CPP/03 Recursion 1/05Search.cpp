#include <iostream>
using namespace std;

bool search(int* arr, int n, int x)
{
    if (n == 0)
        return false;
    else if (arr[0] == x)
        return true;
    return search(arr + 1, n - 1, x);
}

int main()
{
    int n, x;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << (search(arr, n, x) ? "true" : "false") << "\n";
    return 0;
}