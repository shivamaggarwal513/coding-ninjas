#include <iostream>

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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

Node *takeInput()
{
    int data;
    std::cin >> data;

    if (data != -1)
    {
        Node *head = new Node(data), *temp1, *temp2;
        temp1 = head;
        std::cin >> data;
        while (data != -1)
        {
            temp2 = new Node(data);
            temp1->next = temp2;
            temp1 = temp2;
            std::cin >> data;
        }
        return head;
    }
    return nullptr;
}

int lengthLL(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int ithNode(Node *head, int idx)
{
    Node *temp = head;
    while (idx && temp)
    {
        temp = temp->next;
        idx--;
    }
    if (!idx && temp)
        return temp->data;
    return -1;
}

Node *insertNode(Node *head, int idx, int x)
{
    Node *newNode = new Node(x);
    if (idx == 0)
    {
        newNode->next = head;
        return newNode;
    }
    int i = 0;
    Node *temp = head;
    while (temp && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp && i == idx - 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *deleteNode(Node *head, int idx)
{
    if (head && idx == 0)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    int i = 0;
    Node *temp = head;
    while (temp && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp && temp->next && i == idx - 1)
    {
        Node *del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    return head;
}

int lengthLLRec(Node *head)
{
    if (!head)
        return 0;
    return 1 + lengthLLRec(head->next);
}

Node *insertNodeRec(Node *head, int idx, int x)
{
    if (!head && idx)
        return nullptr;
    if (!idx)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        return newNode;
    }
    head->next = insertNodeRec(head->next, idx - 1, x);
    return head;
}

Node *deleteNodeRec(Node *head, int idx)
{
    if (!head)
        return nullptr;
    if (!idx)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    head->next = deleteNodeRec(head->next, idx - 1);
    return head;
}