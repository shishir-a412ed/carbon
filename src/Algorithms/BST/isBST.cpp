// WAP to check if a binary tree is BST or not.

#include <iostream>
#include <climits>

using namespace std;

struct Node{
 int data;
 Node *left;
 Node *right;
};

bool isBST(Node *, int&);
Node* createNode(Node *, int);
void inorder(Node *);

int main(){
// Create BT.
Node *root=NULL;
root=createNode(root, 4);
root->left=createNode(root->left, 2);
root->right=createNode(root->right, 5);
root->left->left=createNode(root->left->left, 1);
root->left->right=createNode(root->left->right, 0);
inorder(root);
cout<<"\n";

int prev=-(INT_MAX);
if(isBST(root, prev))
  cout<<"Binary tree is a BST\n";
else
  cout<<"Binary tree is NOT a BST\n";
return 0;
}

void inorder(Node* root){
if (root){
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
}

Node* createNode(Node* root, int data){
    root=new Node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}

bool isBST(Node *root, int& prev){
if (root){
   if (!isBST(root->left, prev))
      return false;
   if (root->data < prev)
      return false;
   prev=root->data;
   return isBST(root->right, prev);
}
return true;
}
