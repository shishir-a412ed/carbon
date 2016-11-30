/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Insert(Node *head,int data)
{
  Node *start=NULL;
  if (!head)
      {
      head=new Node;
      head->data=data;
      head->next=NULL;
  }else{
      start=head;
      while(start->next)
          {
          start=start->next;
      }
      start->next=new Node;
      start=start->next;
      start->data=data;
      start->next=NULL;
  }
return head;
}
