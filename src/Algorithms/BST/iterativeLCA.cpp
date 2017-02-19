// Iterative Lowest Common Ancestor (LCA) in a Binary Search Tree.

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
void inorder(Node *);
Node* findLCA(Node *,int, int);

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
cout<<"LCA of n1 and n2 is: "<<lca->data<<endl;
return 0;
}

Node* findLCA(Node *root, int n1, int n2){
if (!root)
   return root;
stack<Node*> s;
Node *new_root=root;
while(root && new_root){
     if (root == new_root)
         s.push(root);
     if (new_root->data == n1 && root->data == n2)
        break;

     if (n1 < new_root->data)
        new_root=new_root->left;
     else if (n1 > new_root->data)
        new_root=new_root->right;

     if (n2 < root->data)
        root=root->left;
     else if (n2 > root->data)
        root=root->right;
}
return s.top();
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

