// Problem-9 Give an algorithm for deleting the tree.

// Solution:To delete a tree, we must traverse all the nodes of the tree and delete them one by one. So which
// traversal should we use: Inorder, Preorder, Postorder or Level order Traversal?
// Before deleting the parent node we should delete its children nodes first. We can use postorder
// traversal as it does the work without storing anything.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deletetree(TreeNode* root)
{
    if(root==nullptr)
        return;
    deletetree(root->left);
    deletetree(root->left);
    delete root;
}