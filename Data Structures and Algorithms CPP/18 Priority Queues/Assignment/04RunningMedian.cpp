#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int *runningMedian(int *arr, int n)
{
    int *ans = new int[n];
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(arr[0]);
    ans[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i] > maxHeap.top() ? minHeap.push(arr[i]) : maxHeap.push(arr[i]);
        if ((int)(maxHeap.size() - minHeap.size()) > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if ((int)(minHeap.size() - maxHeap.size()) > 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (i & 1)
            ans[i] = (minHeap.top() + maxHeap.top()) / 2;
        else if ((int)maxHeap.size() > (int)minHeap.size())
            ans[i] = maxHeap.top();
        else
            ans[i] = minHeap.top();
    }
    return ans;
}

int main()
{
    int n, i;
    cin >> n;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    int *ans = runningMedian(arr, n);
    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
    delete []arr;
    delete []ans;
    return 0;
}