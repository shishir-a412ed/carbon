// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list
/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Delete(Node *head, int position)
{
// Complete this method
    int i=0;
    Node *start=head;
    Node *temp;
// Delete HEAD node
    if (i==position){
        head=head->next;
        delete(start);
        return head;
    }
// Delete middle and tail node
   while (head->next){
        if (i+1==position){
            temp=head->next;
            head->next=temp->next;
            delete(temp);
            break;
        }
        i++;
        head=head->next;
    }
   return start;
}
