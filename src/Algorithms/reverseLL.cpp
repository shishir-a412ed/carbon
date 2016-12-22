#include <iostream>

using namespace std;

struct Node{
int data;
Node *next;
};

Node *head;
Node* insert(Node*, int);
void reverse(Node *);

int main(){
head=insert(head,1);
head=insert(head,2);
head=insert(head,3);
head=insert(head,4);
head=insert(head,5);
reverse(head);
while(head)
{
  cout<<head->data<<endl;
  head=head->next;
}
return 0;
}

void reverse(Node *p)
{
if (!p->next)
{
head=p;
return;
}
reverse(p->next);
Node *q=p->next;
q->next=p;
p->next=NULL;
}


Node* insert(Node *head, int data)
{
if (!head){
	head=new Node;
	head->data=data;
	head->next=NULL;
}else{
	Node *start=head;
	while(start->next){
		start=start->next;
	}
	start->next=new Node;
	start=start->next;
	start->data=data;	
	start->next=NULL;
}
return head;
}

