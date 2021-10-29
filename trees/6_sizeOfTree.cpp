// Problem-6 Give an algorithm for finding the size of binary tree.

// Solution: Calculate the size of left and right subtrees recursively, add 1 (current node) and return
// to its parent.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int size(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    return(size(root->left)+size(root->right)+1);
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
    cout<<size(root);
}

