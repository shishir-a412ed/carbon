#include <iostream>

using namespace std;

struct Node{
int data;
Node *left;
Node *right;
};

Node* insert(Node*, int);
Node* getNode(int);
bool search(Node*, int);
int findMin(Node *);
int findMax(Node *);

int main()
{
Node *root=NULL;
int val;
root=insert(root,15);
root=insert(root,10);
root=insert(root,20);
root=insert(root,25);
root=insert(root,5);
cout<<"Enter a number to be searched\n";
cin>>val;
if (search(root,val))
{
cout<<"Number exists in BST\n";
}else{
cout<<"Number does NOT exist in BST\n";
}
int min=findMin(root);
cout<<"Minimum element in the BST is: "<<min<<endl;
int max=findMax(root);
cout<<"Maximum element in the BST is: "<<max<<endl;
return 0;
}

int findMin(Node *root)
{
if (!root)
{
cout<<"Tree is empty\n";
return -1;
}
if (!root->left)
   return root->data;
findMin(root->left);
}

int findMax(Node *root)
{
if (!root)
{
cout<<"Tree is empty\n";
return -1;
}
if (!root->right)
   return root->data;
findMax(root->right);
}

Node* getNode(int data)
{
Node *root=new Node;
root->data=data;
root->left=root->right=NULL;
return root;
}

bool search(Node* root, int data)
{
if (!root)
   return false;
if (data == root->data)
   return true;
else if (data < root->data)
   return search(root->left, data);
else 
   return search(root->right, data);
}

Node* insert(Node* root, int data)
{
if (!root)
{
root=getNode(data);
}
else if (data <= root->data){
   root->left=insert(root->left, data);
}
else{
   root->right=insert(root->right, data);
}
return root;
}
