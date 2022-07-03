#include <iostream>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
    int ans = 0;
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }
    while (q.front() != k || pq.top() > arr[q.front()])
    {
        if (pq.top() > arr[q.front()])
            q.push(q.front());
        else
        {
            pq.pop();
            ans++;
        }
        q.pop();
    }
    return ans + 1;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << buyTicket(arr, n, k) << "\n";
    delete []arr;
    return 0;
}