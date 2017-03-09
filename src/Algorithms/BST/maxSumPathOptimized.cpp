// Find the maximum sum leaf to root path in a Binary Tree.
// Time Complexity O(n).

#include <iostream>
#include <climits>

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

void getLeaf(Node *root, Node **leaf, int currentSum, int &maxSum){
if (!root)
   return;
currentSum=currentSum+root->data;
if (!root->left && !root->right){
   if (currentSum > maxSum)
   {
   maxSum=currentSum;
   *leaf=root;
   }
}
getLeaf(root->left, leaf, currentSum, maxSum);
getLeaf(root->right, leaf, currentSum, maxSum);
}

bool printPath(Node *root, Node *leaf){
if (!root)
   return false;

if (root==leaf || printPath(root->left, leaf) || printPath(root->right, leaf))
{
cout<<root->data<<" ";
return true;
}
return false;
}

void printMaxSumPath(Node *root){
Node *leaf=NULL;
int currentSum=0;
int maxSum=-(INT_MAX);
getLeaf(root, &leaf, currentSum, maxSum);
printPath(root, leaf);
}

int main(){
Node *root=NULL;
root=createBST();
printMaxSumPath(root);
return 0;
}

