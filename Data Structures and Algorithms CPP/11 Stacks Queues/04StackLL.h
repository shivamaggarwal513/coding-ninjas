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
class StackLL
{
private:
    Node<T> *head;
    int stackSize;

public:
    StackLL()
    {
        head = nullptr;
        stackSize = 0;
    }

    void push(T val)
    {
        Node<T> *newHead = new Node<T>(val);
        newHead->next = head;
        head = newHead;
        stackSize++;
    }

    T pop()
    {
        if (!head)
        {
            std::cout << "Stack is empty\n";
            return 0;
        }
        T val = head->data;
        Node<T> *toDel = head;
        head = head->next;
        delete toDel;
        stackSize--;
        return val;
    }

    T top()
    {
        if (!head)
        {
            std::cout << "Stack is empty\n";
            return 0;
        }
        return head->data;
    }

    int size()
    {
        return stackSize;
    }

    bool isEmpty()
    {
        return !head;
    }
};