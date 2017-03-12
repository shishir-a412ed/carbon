// Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void rootToLeafPaths(TreeNode *root, vector<string> &sv, string s){
        if (!root)
            return;

	s=s+(to_string(root->val))+"->";
	if (!root->left && !root->right)
        {
            sv.push_back(s.substr(0, s.length()-2));
        }
        rootToLeafPaths(root->left, sv, s);
        rootToLeafPaths(root->right, sv, s);
}

vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sv;
        string s="";
        rootToLeafPaths(root, sv, s);
        return sv;
}

TreeNode* createNode(int val){
	TreeNode *root=new TreeNode();
	root->val=val;
	root->left=root->right=NULL;
	return root;
}

int main(){
vector<string> sv;
TreeNode *root=NULL;
root=createNode(1);
root->left=createNode(2);
root->right=createNode(3);
root->left->right=createNode(5);
sv=binaryTreePaths(root);
cout<<"Root to leaf paths are:\n";
for(int i=0;i<sv.size();i++)
   cout<<sv[i]<<"\n";
return 0;
}
