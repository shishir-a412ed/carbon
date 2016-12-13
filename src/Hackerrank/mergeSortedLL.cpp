// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists
/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* MergeLists(Node *headA, Node* headB)
{
  if (!headA)
      return headB;
  if (!headB)
      return headA;
  // Create a precursor node.
  Node *new_head=new Node;
  new_head->data=0;
  new_head->next=NULL;
  Node *start=new_head;
  while (headA && headB)
      {
      if (headA->data <= headB->data)
          {
          start->next=headA;
          headA=headA->next;
      }else{
          start->next=headB;
          headB=headB->next;
      }
      start=start->next;
  }
  if (!headA)
     start->next=headB;
  if (!headB)
      start->next=headA;
 // Remove the precurse node and return the new_head
 Node *temp=new_head;
 new_head=new_head->next;
 delete(temp);
 return new_head;
}
