// Invert a BST.

#include <iostream>
#include <queue>

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

void BFS(Node *root){
if (!root)
   return;
queue<Node *> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
     Node *front=q.front();
     q.pop();
     if (!front){
	if (!q.empty()){
	   cout<<endl;
           q.push(NULL);
	}
	continue;
     }
     cout<<front->data<<" ";
     if (front->left)
        q.push(front->left);
     if (front->right)
        q.push(front->right);

}
cout<<endl;
}
 
void invert(Node *root){
if (root){
   invert(root->left);
   invert(root->right);
   Node *temp=root->left;
   root->left=root->right;
   root->right=temp; 
}
}

int main(){
Node *root=NULL;
root=createBST();
cout<<"level order traversal BST (Before invert):\n";
BFS(root);
invert(root);
cout<<"level order traversal BST (After invert):\n";
BFS(root);
return 0;
}
