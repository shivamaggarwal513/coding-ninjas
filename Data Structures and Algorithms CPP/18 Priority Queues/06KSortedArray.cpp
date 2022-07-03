#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int *arr, int n, int k)
{
    int i;
    priority_queue<int> q;
    for (i = 0; i < k; i++)
        q.push(arr[i]);
    for (i = k; i < n; i++)
    {
        arr[i - k] = q.top();
        q.pop();
        q.push(arr[i]);
    }
    for (i = n - k; i < n; i++)
    {
        arr[i] = q.top();
        q.pop();
    }
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    kSortedArray(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    delete []arr;
    return 0;
}