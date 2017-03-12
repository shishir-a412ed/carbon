// Lowest Common Ancestor in a Binary Tree.
// Time Complexity O(n). Space Complexity O(h).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node{
   int val;
   Node *left;
   Node *right;
};

bool populatePath(Node *root, Node *target, vector<Node *> &path){
        if (!root)
            return false;

	if (root==target || populatePath(root->left, target, path) || populatePath(root->right, target, path)){
	   path.push_back(root);
	   return true;
	}
	return false;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        vector<Node *> pPath, qPath;
	unordered_set<Node *> s;
	unordered_set<Node *>::iterator it;
        if (!root)
            return root;
            
        populatePath(root, p, pPath);
        populatePath(root, q, qPath);
       
        for(int i=0;i<pPath.size();i++)
	    s.insert(pPath[i]);

	for(int i=0;i<qPath.size();i++)
	{
	        it=s.find(qPath[i]);
		if (it == s.end())
		   continue;
		break;
	}
	return *it;
}

Node* createNode(int val){
     Node *root=new Node();
     root->val=val;
     root->left=root->right=NULL;
     return root;
}


int main(){
Node *root=NULL;
root=createNode(1);
root->left=createNode(2);
root->right=createNode(3);
root->left->right=createNode(4);
Node *lca=lowestCommonAncestor(root, root->left->right, root);
cout<<"LCA IS: "<<lca->val<<"\n";
return 0;
}

