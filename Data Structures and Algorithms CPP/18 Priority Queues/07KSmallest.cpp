#include <iostream>
#include <queue>
using namespace std;

int *kSmallest(int *arr, int n, int k)
{
    int i = 0, *ans = new int[k];
    priority_queue<int> q;
    for (i = 0; i < k; i++)
        q.push(arr[i]);
    for (i = k; i < n; i++)
    {
        if (arr[i] < q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    for (i = 0; i < k; i++)
    {
        ans[i] = q.top();
        q.pop();
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    int *ans = kSmallest(arr, n, k);
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << "\n";
    delete []arr;
    delete []ans;
    return 0;
}