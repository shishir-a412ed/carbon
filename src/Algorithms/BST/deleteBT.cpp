// Given the root node of the binary tree, delete the entire tree.
// Time Complexity O(n). Delete the tree using postOrder traversal.

#include <iostream>

using namespace std;

struct Node{
   int data;
   Node *left;
   Node *right;
};

Node* getNode(int data){
    Node *root=new Node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}

void deleteBT(Node *root){
if (!root)
   return;
deleteBT(root->left);
deleteBT(root->right);
cout<<"Deleting Node with data: "<<root->data<<endl;
delete(root);
}

int main(){
Node *root=NULL;
root=getNode(1);
root->left=getNode(2);
root->right=getNode(3);
root->left->left=getNode(4);
root->left->right=getNode(5);
deleteBT(root);
root=NULL;
cout<<"Deletion completed\n";
return 0;
}

