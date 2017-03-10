// Print root to leaf paths without using recursion
// Time Complexity O(n). Space Complexity O(n).

#include <iostream>
#include <stack>
#include <unordered_map>

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

void printPath(Node *leaf, unordered_map<Node *, Node *> &m){
Node *parent;
stack<Node *> s;
while(leaf){
     parent=m[leaf];
     s.push(leaf);
     leaf=parent;
}
while(!s.empty()){
Node *top=s.top();
s.pop();
cout<<top->data<<" ";
}
cout<<endl;
}

void rootToLeafPath(Node *root){
stack<Node *> s;
unordered_map<Node *, Node *> m;
if (!root)
    return;
s.push(root);
m[root]=NULL;
while(!s.empty()){
Node *top=s.top();
s.pop();
if (!top->left && !top->right){
   printPath(top, m);
}
if (top->right)
{
    s.push(top->right);
    m[top->right]=top;
}
if (top->left)
{
    s.push(top->left);
    m[top->left]=top;
}
}
}

int main(){
Node *root=NULL;
root=createBST();
cout<<"Root to leaf paths are:\n";
rootToLeafPath(root);
return 0;
}
