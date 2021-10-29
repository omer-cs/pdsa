// Problem-3 Give an algorithm for searching an element in binary tree.

// Solution: Given a binary tree, return true if a node with data is found in the tree. Recurse down
// the tree, choose the left or right branch by comparing data with each node’s data.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool search(TreeNode* root,int value){
    if(root==nullptr)
    {
        return false;
    }
    if(root->val==value)
    {
        return true;
    }
    return search(root->left,value)||search(root->right,value);
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
    cout<<search(root,120);
}
