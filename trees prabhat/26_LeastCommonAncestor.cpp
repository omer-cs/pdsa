// Problem-26 Give an algorithm for finding LCA (Least Common Ancestor) of two nodes in a
// Binary Tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int LCA(TreeNode *root, int a, int b)
{
    if (!root)
        return -1;
    if(root->val==a||root->val==b)
        return root->val;
    int l=LCA(root->left,a,b);
    int r=LCA(root->right,a,b);
    if(l!=-1&&r!=-1)     //if both are returning non negative values then they have been found in subtrees
        return root->val;
    return(l!=-1?l:r); //return whaterver is not -1
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
    cout<<LCA(root,81,22);
}