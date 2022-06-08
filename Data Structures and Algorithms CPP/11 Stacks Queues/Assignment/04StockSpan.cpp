#include <iostream>
#include <stack>
using namespace std;

int *stockSpan(int *price, int n)
{
    int *span = new int[n];
    stack<int> s;
    span[0] = 1;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[s.top()])
        {
            while (!s.empty() && price[i] > price[s.top()])
                s.pop();
            span[i] = s.empty() ? i + 1 : i - s.top();
        }
        else
            span[i] = 1;
        s.push(i);
    }
    return span;
}

int main()
{
    int n;
    cin >> n;
    int *price = new int[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int *span = stockSpan(price, n);
    for (int i = 0; i < n; i++)
        cout << span[i] << " ";
    cout << "\n";
    delete []price;
    delete []span;
    return 0;
}