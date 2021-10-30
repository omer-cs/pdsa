// Problem-10 Give an algorithm for finding the height (or depth) of the binary tree.

// Solution: Recursively calculate height of left and right subtrees of a node and assign height to the
// node as max of the heights of two children plus 1. This is similar to PreOrder tree traversal (and
// DFS of Graph algorithms)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root){
    if(root==nullptr)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}

int main(){
    TreeNode *root=new TreeNode(17);
    root->left=new TreeNode(41);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(29);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(81);
    root->right->right=new TreeNode(40);
    root->right->right->right=new TreeNode(121);
    cout<<height(root);
}