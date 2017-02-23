#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

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

Node* findMinimum(Node *root){
while(root->left)
     root=root->left;
return root;
}

Node* remove(Node *root, int data){
if (!root)
	return root;
else if (data < root->data)
	root->left=remove(root->left, data);
else if (data > root->data)
	root->right=remove(root->right, data);
else{
    // We have found the BST node to be deleted.
    // Case 1: Leaf Node
    if (!root->left && !root->right){
	delete root;
	root=NULL;
    //Case 2: Root has one child.
    }else if (!root->left){
	Node *temp=root;
	root=root->right;
	delete temp;
	temp=NULL;
    }else if (!root->right){
	Node *temp=root;
	root=root->left;
	delete temp;
	temp=NULL;
    //Case 3: Root has both child.
    }else{
	Node *temp=findMinimum(root->right);
	root->data=temp->data;
	root->right=remove(root->right, root->data);
    }
}
return root;
}

int main(){
Node *root=NULL;
int data;
char ch='y';
cout<<"Enter elements of the BST\n";
while(ch == 'y' || ch == 'Y'){
	cout<<"Enter an element\n";
     	cin>>data;
	root=insert(root, data);
  	cout<<"Do you wish to enter another element [y/n]\n";
	cin>>ch;
}
cout<<"Inorder traversal of BST is:\n";
inorder(root);
cout<<"\nEnter the element to be deleted from BST\n";
cin>>data;
root=remove(root, data);
cout<<"Inorder traversal after deletion\n";
inorder(root);
cout<<endl;
return 0;
}
