// Problem-22 Give an algorithm for finding the sum of all elements in binary tree.

// Solution: Recursively, call left subtree sum, right subtree sum and add their values to current
// nodes data.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum(TreeNode* root)
{
    if(!root)
        return 0;
    return (root->val+sum(root->left)+sum(root->right));
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
    root->right->right->right->right=new TreeNode(22);
    cout<<sum(root);
}