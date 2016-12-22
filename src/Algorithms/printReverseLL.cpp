#include <iostream>

using namespace std;

struct Node{
int data;
Node *next;
};

Node* insert(Node*,int);
void printLL(Node*);
void printReverse(Node*);

int main(){
Node *head, *start;
head=insert(head, 4);
head=insert(head, 6);
head=insert(head, 8);
head=insert(head, 10);
start=head;
cout<<"Linked list elements in forward order\n";
printLL(head);
cout<<"Linked List elements in reverse order\n";
printReverse(start);
return 0;
}

void printReverse(Node *head){
if (!head)
   return;
printReverse(head->next);
cout<<head->data<<endl;
}

void printLL(Node *head){
if (!head)
   return;
cout<<head->data<<endl;
printLL(head->next);
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


