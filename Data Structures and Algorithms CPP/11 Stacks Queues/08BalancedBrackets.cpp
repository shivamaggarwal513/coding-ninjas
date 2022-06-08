#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string &s)
{
    stack<char> brackets;
    for (auto it : s)
    {
        if (it == '(' || it == '[' || it == '{')
            brackets.push(it);
        else if (it == ')' || it == ']' || it == '}')
        {
            if ((it == ')' && brackets.top() == '(') ||
                (it == ']' && brackets.top() == '[') ||
                (it == '}' && brackets.top() == '{'))
                brackets.pop();
            else
                return false;
        }
    }
    return brackets.empty() ? true : false;
}

int main()
{
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "true" : "false") << "\n";
    return 0;
}