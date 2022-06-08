#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node() {}
    
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class QueueLL
{
private:
    Node *head;
    Node *tail;
    int queueSize;

public:
    QueueLL()
    {
        head = nullptr;
        tail = nullptr;
        queueSize = 0;
    }

    void enqueue(int val)
    {
        Node *newTail = new Node(val);
        if (head)
            tail->next = newTail;
        else
            head = newTail;
        tail = newTail;
        queueSize++;
    }

    int dequeue()
    {
        if (!head)
            return -1;
        int val = head->data;
        Node *toDel = head;
        head = head->next;
        delete toDel;
        queueSize--;
        return val;
    }

    int front()
    {
        return head ? head->data : -1;
    }

    int getSize()
    {
        return queueSize;
    }

    bool isEmpty()
    {
        return !head;
    }
};

int main()
{
    int q, a, b;
    QueueLL qu;
    cin >> q;
    while (q--)
    {
        cin >> a;
        switch (a)
        {
            case 1:
                cin >> b;
                qu.enqueue(b);
                break;
            case 2:
                cout << qu.dequeue() << "\n";
                break;
            case 3:
                cout << qu.front() << "\n";
                break;
            case 4:
                cout << qu.getSize() << "\n";
                break;
            case 5:
                cout << (qu.isEmpty() ? "true" : "false") << "\n";
                break;
        }
    }
    return 0;
}