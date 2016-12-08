// Reverse a singly linked list.
// https://www.hackerrank.com/challenges/reverse-a-linked-list

/*
Reverse a linked list and return pointer to the head
The input list will have at least one element  
Node is defined as 
struct Node
 {
 int data;
 struct Node *next;
 }
*/

Node* Reverse(Node *head)
{
// Complete this method
    if (!head)
        return head;
    
    Node *new_root=NULL;
    Node *next;
    while (head)
        {
        next=head->next;
        head->next=new_root;
        new_root=head;
        head=next;
    }
    return new_root;
}
