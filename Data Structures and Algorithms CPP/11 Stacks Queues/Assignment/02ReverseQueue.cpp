#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty())
        return;
    int val = q.front();
    q.pop();
    reverseQueue(q);
    q.push(val);
}

int main()
{
    int t, n, i, val;
    queue<int> q;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
    return 0;
}