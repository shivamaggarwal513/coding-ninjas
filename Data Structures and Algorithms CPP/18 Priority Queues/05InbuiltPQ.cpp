#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> mnQ;
    for (int i = 10; i > 0; i--)
        mnQ.push(i);
    cout << mnQ.size() << " " << mnQ.empty() << " " << mnQ.top() << "\n";
    while (!mnQ.empty())
    {
        cout << mnQ.top() << " ";
        mnQ.pop();
    }
    cout << "\n";

    priority_queue<int> mxQ;
    for (int i = 1; i <= 10; i++)
        mxQ.push(i);
    cout << mxQ.size() << " " << mxQ.empty() << " " << mxQ.top() << "\n";
    while (!mxQ.empty())
    {
        cout << mxQ.top() << " ";
        mxQ.pop();
    }
    cout << "\n";

    return 0;
}