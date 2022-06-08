#include <iostream>
#include "04StackLL.h"
using namespace std;

int main()
{
    StackLL<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.pop() << " ";
    cout << s.top() << " ";
    cout << s.pop() << "\n";
    cout << s.isEmpty() << "\n";
    cout << s.size() << " ";
    cout << s.top();
    return 0;
}