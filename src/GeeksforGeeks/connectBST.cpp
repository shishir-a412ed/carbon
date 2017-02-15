// Write a function to connect all the adjacent nodes at the same level in a binary tree.
// Method 1: Extend level order traversal or BFS. Time Complexity O(n) and Space Complexity O(n).

#include <iostream>
#include <queue>

using namespace std;

struct Node{
int data;
Node *left;
Node *right;
Node *next;
};

Node* insert(Node *, int);
Node* createNode(Node *, int);
void connectNext(Node *);
void printConnect(Node *);

int main(){
Node *root=NULL;
int data;
char ch='y';
cout<<"Create a BST:\n";
while(ch == 'y' || ch == 'Y'){
     cout<<"Enter an element\n";
     cin>>data;
     root=insert(root, data);
     cout<<"Do you wish to enter another element [y/n]\n";
     cin>>ch;
}
connectNext(root);
cout<<"Level order traversal (BFS) using printConnect:\n";
printConnect(root);
return 0;
}

void printConnect(Node *root){
if (!root)
    return;

while(root){
     Node *head=root;
     while(head){
          cout<<head->data<<" ";
          head=head->next;
     }
     root=root->left;
     cout<<endl;
}
}

void connectNext(Node *root){
if (!root)
   return;
Node *prev=NULL;
queue<Node *> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
     Node *front=q.front();
     q.pop();
     if (!front){
        prev->next=NULL;
        prev=NULL;
	if (!q.empty())
           q.push(NULL);
        continue;
     }
     if (prev)
        prev->next=front;
     prev=front;
     if (front->left)
        q.push(front->left);
     if (front->right)
        q.push(front->right);
}
}

Node* createNode(Node *root, int data){
root=new Node();
root->data=data;
root->left=root->right=root->next=NULL;
return root;
}

Node* insert(Node *root, int data){
if (!root){
   root=createNode(root, data);
}else if (data <= root->data){
     root->left=insert(root->left, data);
}else{
    root->right=insert(root->right, data);
}
return root;
}
