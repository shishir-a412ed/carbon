#include <iostream>
#include <cstdio>

using namespace std;

struct node{
int data;
node *next;
};

node* insert(node*,int);
void printLinkedList(node *);

int main()
{
node *head=NULL;
head=insert(head,5);
head=insert(head,6);
head=insert(head,7);
printLinkedList(head);
delete(head);
return 0;
}

void printLinkedList(node *head)
{
if (!head)
	return;
while(head)
{
	cout<<"Element: "<<head->data<<endl;
	head=head->next;
}
}

node* insert(node* head, int data)
{
	if (!head)
	{
	head=new node;
	head->data=data;
	head->next=NULL;
	}
	else if (head)
	{
	node *start=head;
		while (start->next != NULL)
		{
		start=start->next;
		}
	start->next=new node;
	start=start->next;
	start->data=data;
	start->next=NULL;
	}
return head;
}
