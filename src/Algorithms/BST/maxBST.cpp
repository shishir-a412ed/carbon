// Maximum element between two nodes of BST
// http://www.geeksforgeeks.org/maximum-element-two-nodes-bst/
// Time Complexity: O(h) and Space Complexity: O(h)

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

Node* insert(Node*, int);
Node* createNode(Node*, int);
void inorder(Node *);
Node* findLCA(Node *,int,int);
bool isExists(Node *,int);
int getMaxElement(Node *, int);

int main(){
Node *root=NULL;
int data, n1, n2;
char ch='y';
cout<<"Create a BST:\n";
while(ch == 'y' || ch == 'Y'){
     cout<<"Enter an element\n";
     cin>>data;
     root=insert(root, data);
     cout<<"Do you wish to enter another element [y/n]\n";
     cin>>ch;
}
cout<<"Inorder traversal of BST:\n";
inorder(root);
cout<<"\nEnter n1\n";
cin>>n1;
cout<<"Enter n2\n";
cin>>n2;
Node *lca=findLCA(root, n1, n2);
if (!lca)
{
cout<<"LCA not found: Either n1 or n2 or both do not exist in the BST\n";
exit(1);
}
cout<<"LCA of n1 and n2 is: "<<lca->data<<endl;
int target=(n1>n2)?n1:n2;
cout<<"Max element between n1 and n2 is: "<<getMaxElement(lca, target)<<endl;
return 0;
}

int getMaxElement(Node *lca, int target){
int max=lca->data;
while(lca){
if (lca->data > max)
   max=lca->data;
if (lca->data == target)
    break;
else if (target > lca->data)
     lca=lca->right;
else
     lca=lca->left;
}
return max;
}

bool isExists(Node *root, int n){
if (!root)
   return false;
if (n==root->data)
    return true;
else if (n<root->data)
    return isExists(root->left, n);
else
   return isExists(root->right, n);
}

Node* findLCA(Node *root, int n1, int n2){
if (!root)
   return root;

bool isN1, isN2;
isN1=isExists(root,n1);
isN2=isExists(root,n2);
if (!isN1 || !isN2)
   return NULL;

while(root){
   if (n1 <root->data && n2<root->data)
      root=root->left;
   else if(n1 >root->data && n2>root->data)
      root=root->right;
   else
      break;
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

