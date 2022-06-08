#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

bool checkRedundantBrackets(string &s)
{
    if (s.empty())
        return true;
    
    stack<pair<char, bool>> stk;
    for (auto it : s)
    {
        if (it == '(')
            stk.push(make_pair('(', false));
        else if (!stk.empty() && (it == '+' || it == '-' || it == '*' || it == '/'))
        {
            stk.pop();
            stk.push(make_pair('(', true));
        }
        else if (it == ')')
        {
            if (!stk.top().second)
                return true;
            stk.pop();
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << (checkRedundantBrackets(s) ? "true" : "false") << "\n";
    return 0;
}