// Problem-1 Give an algorithm for finding maximum element in binary tree.

// Solution: One simple way of solving this problem is: find the maximum element in left subtree,
// find the maximum element in right sub tree, compare them with root data and select the one which
// is giving the maximum value. This approach can be easily implemented with recursion.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxElement(TreeNode* root)
{
    if(root==nullptr)
        return INT32_MIN;
    int l=maxElement(root->left);
    int r=maxElement(root->right);
    return max({l,r,root->val});
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
    cout<<maxElement(root);
}