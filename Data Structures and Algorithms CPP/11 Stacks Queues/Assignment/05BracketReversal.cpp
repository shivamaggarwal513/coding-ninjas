#include <iostream>
#include <string>
#include <stack>
using namespace std;

int bracketReversal(string &str)
{
    int length = 0;
    stack<char> brackets;
    for (auto it : str)
    {
        if (it == '{')
            brackets.push('{');
        else if (it == '}')
        {
            if (brackets.empty() || brackets.top() == '}')
                brackets.push('}');
            else
                brackets.pop();
        }
        length++;
    }
    if (length & 1)
        return -1;
    int count = 0;
    char c1, c2;
    while (!brackets.empty())
    {
        c1 = brackets.top();
        brackets.pop();
        c2 = brackets.top();
        brackets.pop();
        count += c1 == c2 ? 1 : 2;
    }
    return count;
}

int main()
{
    string str;
    cin >> str;
    cout << bracketReversal(str) << "\n";
    return 0;
}