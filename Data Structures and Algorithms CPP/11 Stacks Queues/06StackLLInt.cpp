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

class StackLL
{
private:
    Node *head;
    int stackSize;

public:
    StackLL()
    {
        head = nullptr;
        stackSize = 0;
    }

    void push(int val)
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        stackSize++;
    }

    int pop()
    {
        if (!head)
            return -1;
        int val = head->data;
        Node *toDel = head;
        head = head->next;
        delete toDel;
        stackSize--;
        return val;
    }

    int top()
    {
        return head ? head->data : -1;
    }

    int getSize()
    {
        return stackSize;
    }

    bool isEmpty()
    {
        return !head;
    }
};

int main()
{
    int q, a, b;
    StackLL s;
    cin >> q;
    while (q--)
    {
        cin >> a;
        switch (a)
        {
            case 1:
                cin >> b;
                s.push(b);
                break;
            case 2:
                cout << s.pop() << "\n";
                break;
            case 3:
                cout << s.top() << "\n";
                break;
            case 4:
                cout << s.getSize() << "\n";
                break;
            case 5:
                cout << (s.isEmpty() ? "true" : "false") << "\n";
                break;
        }
    }
    return 0;
}