// Print Common Nodes in Two Binary Search Trees.
// m=number of nodes in BST1 and n=number of nodes in BST2.
// Time Complexity: O(m+n)
// Space Complexity: O(m+n)

#include <iostream>
#include <vector>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

Node* createNode(Node *, int);
Node* insert(Node *, int);
void saveInorderToVector(Node *, vector<int>&);
Node* createBST();
void printCommonNodes(vector<int>&, vector<int>&);

int main()
{
Node *root1, *root2;
vector<int> v1,v2;
vector<int>::iterator it;
cout<<"Create BST1:\n";
root1=createBST();
cout<<"Create BST2:\n";
root2=createBST();
cout<<"Inorder traversal BST1\n";
saveInorderToVector(root1, v1);
for(it=v1.begin();it!=v1.end();it++)
   cout<<*it<<" ";
cout<<"\nInorder traversal BST2\n";
saveInorderToVector(root2, v2);
for(it=v2.begin();it!=v2.end();it++)
   cout<<*it<<" ";
cout<<"\n";
cout<<"Common Nodes between BST1 and BST2:\n";
printCommonNodes(v1,v2);
return 0;
}

void printCommonNodes(vector<int> &v1, vector<int> &v2){
int i=0,j=0;
while(i<v1.size() && j<v2.size()){
if (v1[i] == v2[j]){
   cout<<v1[i]<<" ";
   i++;
   j++;
}else if (v1[i]<v2[j])
   i++;
else
   j++;  
}
cout<<endl;
}

Node* createBST(){
  Node *root=NULL;
  int data;
  char ch='y';
  while(ch == 'y' || ch == 'Y'){
     cout<<"Enter an element\n";
     cin>>data;
     root=insert(root, data);
     cout<<"Do you wish to enter another element [y/n]\n";
     cin>>ch;
  }
return root;
}


void saveInorderToVector(Node *root, vector<int> &v){
  if (root){
     saveInorderToVector(root->left,v);
     v.push_back(root->data);
     saveInorderToVector(root->right,v);
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
