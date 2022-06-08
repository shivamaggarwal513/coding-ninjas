#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node() {}
    
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class QueueLL
{
private:
    Node<T> *head;
    Node<T> *tail;
    int queueSize;

public:
    QueueLL()
    {
        head = nullptr;
        tail = nullptr;
        queueSize = 0;
    }

    void enqueue(T val)
    {
        Node<T> *newTail = new Node<T>(val);
        if (head)
            tail->next = newTail;
        else
            head = newTail;
        tail = newTail;
        queueSize++;
    }

    T dequeue()
    {
        if (!head)
        {
            std::cout << "Queue is empty\n";
            return 0;
        }
        T val = head->data;
        Node<T> *toDel = head;
        head = head->next;
        delete toDel;
        queueSize--;
        return val;
    }

    T front()
    {
        if (!head)
        {
            std::cout << "Queue is empty\n";
            return 0;
        }
        return head->data;
    }

    int size()
    {
        return queueSize;
    }

    bool isEmpty()
    {
        return !head;
    }
};