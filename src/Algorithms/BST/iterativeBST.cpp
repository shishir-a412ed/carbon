// Iterative DFS Traversals in Binary search tree (BST).

#include <iostream>
#include <stack>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

Node* insert(Node*, int);
Node* createNode(Node*, int);
void iterativePreorder(Node*);

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
iterativePreorder(root);
return 0;
}

void iterativePreorder(Node *root){
if (!root)
    return;
stack<Node*> s;
s.push(root);
while(!s.empty()){
Node *top=s.top();
s.pop();
cout<<top->data<<" ";
if (top->right)
   s.push(top->right);
if (top->left)
   s.push(top->left);
}
cout<<endl;
}

Node* createNode(Node *root, int data){
   root=new Node();
   root->data=data;
   root->left=root->right=NULL;
   return root;
}

Node* insert(Node *root, int data){
if (!root)
   root=createNode(root, data);
else if (data <= root->data)
   root->left=insert(root->left, data);
else
   root->right=insert(root->right, data);
return root;
}
