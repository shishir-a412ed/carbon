// Given a binary tree, print all root-to-leaf paths.

#include <iostream>
#include <stack>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};


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

Node* createBST(){
Node *root=NULL;
cout<<"Enter elements in the BST\n";
char ch='y';
int data;
while(ch == 'y' || ch == 'Y'){
     cout<<"Enter an element\n";
     cin>>data;
     root=insert(root, data);
     cout<<"Do you wish to enter another element\n";
     cin>>ch;
}
return root;
}

void inorder(Node *root){
if (root){
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
}

void printS(stack<int> &s){
if (s.empty())
   return;
int top=s.top();
s.pop();
printS(s);
cout<<top<<" ";
s.push(top);
}

void rootToLeaf(Node *root, stack<int> &s){
if (!root)
    return;

s.push(root->data);
if (!root->left && !root->right)
{
   printS(s);
   cout<<endl;
}

rootToLeaf(root->left, s);
rootToLeaf(root->right, s);
s.pop();
}

int main(){
Node *root=NULL;
stack<int> s;
root=createBST();
cout<<"inorder traversal BST:\n";
inorder(root);
cout<<"\nRoot to leaf paths are:\n";
rootToLeaf(root, s);
return 0;
}
