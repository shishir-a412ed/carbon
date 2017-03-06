// Given a binary tree, print all root-to-leaf paths.

#include <iostream>
#include <vector>

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

void printV(vector<int> v){
vector<int>::iterator it;
for(it=v.begin();it!=v.end();it++)
   cout<<*it<<" ";
cout<<endl;
}

void rootToLeaf(Node *root, vector<int> v){
if (!root)
    return;

v.push_back(root->data);
if (!root->left && !root->right)
{
   printV(v);
   return;
}

rootToLeaf(root->left, v);
rootToLeaf(root->right, v);
}

int main(){
Node *root=NULL;
vector<int> v;
root=createBST();
cout<<"inorder traversal BST:\n";
inorder(root);
cout<<"\nRoot to leaf paths are:\n";
rootToLeaf(root, v);
return 0;
}
