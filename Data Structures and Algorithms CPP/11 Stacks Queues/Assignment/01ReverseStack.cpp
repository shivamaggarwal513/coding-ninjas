#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &s1, stack<int> &s2)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1 = s2;
}

int main()
{
    int n, val;
    stack<int> s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        s1.push(val);
    }

    reverseStack(s1, s2);
    
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";

    return 0;
}