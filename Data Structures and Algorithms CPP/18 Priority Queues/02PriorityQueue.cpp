#include <iostream>
#include "01PriorityQueue.h"
using namespace std;

int main()
{
    int i;

    MinPriorityQueue<int> mnQ;
    for (i = 10; i > 0; i--)
        mnQ.insert(i);
    cout << mnQ.size() << " " << mnQ.isEmpty() << " " << mnQ.getMin() << "\n";
    while (!mnQ.isEmpty())
        cout << mnQ.remove() << " ";
    cout << "\n";

    MaxPriorityQueue<int> mxQ;
    for (i = 1; i <= 10; i++)
        mxQ.insert(i);
    cout << mxQ.size() << " " << mxQ.isEmpty() << " " << mxQ.getMax() << "\n";
    while (!mxQ.isEmpty())
        cout << mxQ.remove() << " ";
    cout << "\n";
    
    return 0;
}