#include <iostream>
#include "09QueueArray.h"
using namespace std;

int main()
{
    QueueArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << "\n";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << "\n";
    cout << q.size() << " " << q.front() << "\n";
    cout << q.isEmpty() << "\n";

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << q.front() << " " << q.size() << "\n";
    cout << q.dequeue() << "\n";
    cout << q.front() << " " << q.size() << "\n";

    return 0;
}