// Find the maximum sum leaf to root path in a Binary Tree.
// Time Complexity O(n). Space Complexity O(h).

#include <iostream>
#include <climits>
#include <stack>
#include <vector>

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

void findMax(vector<int> &v, stack<int> &result, int &max){
vector<int>::iterator it;
int sum=0;
for(it=v.begin();it != v.end(); it++)
    sum=sum+(*it);
if (sum > max){
   max=sum;
   while(!result.empty())
        result.pop();
   for(it=v.begin();it!=v.end();it++)
      result.push(*it);
}
}

void getMaxPathSum(Node *root, vector<int> &v, stack<int> &result, int &max){
if (!root)
   return;

v.push_back(root->data);
if (!root->left && !root->right)
   findMax(v, result, max);
getMaxPathSum(root->left, v, result, max);
getMaxPathSum(root->right, v, result, max);
v.pop_back();
}

int main(){
Node *root=NULL;
root=createBST();
vector<int> v;
stack<int> result;
int max=-(INT_MAX);
getMaxPathSum(root, v, result, max);
cout<<"Max path sum in binary tree:\n";
while(!result.empty()){
     int item=result.top();
     result.pop();
     cout<<item<<" ";
}
cout<<endl;
return 0;
}

