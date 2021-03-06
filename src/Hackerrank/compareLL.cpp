// https://www.hackerrank.com/challenges/compare-two-linked-lists
/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int CompareLists(Node *headA, Node* headB)
{
// This is a "method-only" submission. 
// You only need to complete this method 
 while (headA && headB){
      if (headA->data == headB->data){
          headA=headA->next;
          headB=headB->next;       
      }else{
          break;
      }
  }
    if (!headA && !headB)
      return 1;
    if (!headA || !headB)
        return 0;
return 0;
}
