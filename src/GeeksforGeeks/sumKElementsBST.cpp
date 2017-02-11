// Sum of K smallest elements in a BST.

#include <iostream>

using namespace std;

struct Node{
int data;
Node* left;
Node* right;
};

Node* insert(Node*, int);
Node* createNode(Node*, int);
int sumK(Node*, int, int&);
void inorder(Node *);

int main(){
char ch='y';
int data=0;
Node *root=NULL;
cout<<"Enter the elements of the BST\n";
while(ch == 'y' || ch == 'Y'){
	cin>>data;
	root=insert(root, data);
	cout<<"Do you wish to enter another element [y/n]\n";
	cin>>ch;
}
cout<<"BST Inorder traversal:\n";
inorder(root);
int count=0;
int k=0;
cout<<"\nEnter k\n";
cin>>k;
cout<<sumK(root, k, count);
cout<<endl; 
return 0;
}

void inorder(Node *root){
if (root){
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
}

int sumK(Node* root, int k, int &count){
if (!root)
   return 0;
int result = sumK(root->left, k, count);
if (count >= k)
   return result;
result = result + root->data;
count++;
if (count >= k)
   return result;
return result + sumK(root->right, k, count);
}

Node* createNode(Node* root, int data){
	root=new Node();
	root->data=data;
	root->left=root->right=NULL;
	return root;	
}

Node* insert(Node *root, int data){
if (!root)
	root=createNode(root, data);
else if (data <= root->data)
	root->left = insert(root->left, data);
else 
	root->right = insert(root->right, data);
return root;
}
