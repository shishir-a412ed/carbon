// Given a binary search tree and a target node K.
// The task is to find the node with minimum absolute
// difference with given target value K.
// Time Complexity: O(log n) where n is the number of nodes in the BST.

#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

struct Node{
int data;
Node* left;
Node* right;
};

Node* insert(Node*, int);
Node* createNode(Node*, int);
void inorder(Node *);
int closestElement(Node *, int);
void calculateClosestElement(Node *, int, int&, int&);

int main(){
char ch='y';
int data=0;
int k;
Node *root=NULL;
cout<<"Enter the elements of the BST\n";
while(ch == 'y' || ch == 'Y'){
	cin>>data;
	root=insert(root, data);
	cout<<"Do you wish to enter another element [y/n]\n";
	cin>>ch;
}
cout<<"Inorder traversal of BST:\n";
inorder(root);
cout<<"\nEnter the value of K\n";
cin>>k;
cout<<"Closest element to K is: "<<closestElement(root, k)<<endl;
return 0;
}

void calculateClosestElement(Node *root, int k, int &min_diff, int &min_diff_key){
if (!root)
	return;

if (root->data == k){
   min_diff_key = root->data;
   return;
}

if (abs(root->data-k) < min_diff){
   min_diff = abs(root->data-k);
   min_diff_key = root->data;
  }

if (k<root->data)
   calculateClosestElement(root->left, k, min_diff, min_diff_key);
else
   calculateClosestElement(root->right, k, min_diff, min_diff_key);
}

int closestElement(Node *root, int k){
	int min_diff=INT_MAX;
	int min_diff_key=-1;
	calculateClosestElement(root, k, min_diff, min_diff_key);
	return min_diff_key;
}

void inorder(Node *root){
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

Node* insert(Node *root, int data){
if (!root)
        root=createNode(root, data);
else if (data <= root->data)
        root->left = insert(root->left, data);
else
        root->right = insert(root->right, data);
return root;
}
