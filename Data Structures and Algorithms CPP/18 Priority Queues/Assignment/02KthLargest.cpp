#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    int i;
    priority_queue<int, vector<int>, greater<int>> q;
    for (i = 0; i < k; i++)
        q.push(arr[i]);
    for (i = k; i < n; i++)
    {
        if (arr[i] > q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << kthLargest(arr, n, k) << "\n";
    delete []arr;
    return 0;
}