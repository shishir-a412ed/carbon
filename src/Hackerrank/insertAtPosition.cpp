/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    int i=0;
    if (!head){
        head=new Node;
        head->data=data;
        head->next=NULL;
    }else{
        Node *start=new Node;
        start->data=data;
        if (position == 0)
            {
            start->next=head;
            head=start;
        }else{
            Node *temp=head;
            while (i+1!=position)
                {
                temp=temp->next;
                i++;
            }
            start->next=temp->next;
            temp->next=start;
        }
    }
return head;
}
