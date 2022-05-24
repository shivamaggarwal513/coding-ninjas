#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    // Statically
    Node n1(1), n2(2), n3(3), n4(4), n5(5);
    Node *head1 = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    printLL(head1);
    
    // cout << n1.data << " " << n2.data << "\n";
    // cout << head1->data << " " << head1->next->data << "\n";

    // // Dynamically
    // Node *n3 = new Node(10);
    // Node *head2 = n3;
    // Node *n4 = new Node(20);
    // n3->next = n4;
    // // cout << n3->data << " " << n4->data << "\n";
    // cout << head2->data << " " << head2->next->data << "\n";

    return 0;
}