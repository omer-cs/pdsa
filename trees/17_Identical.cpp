// Problem-17 Given two binary trees, return true if they are structurally identical.
// Solution:
// Algorithm:
// • If both trees are NULL then return true.
// • If both trees are not NULL, then compare data and recursively check left and right
// subtree structures.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool identical(TreeNode* A,TreeNode* B){
    if(A==nullptr&&B==nullptr)
        return true;
    if(A==nullptr||B==nullptr)
        return false;
    return((A->val==B->val)&&identical(A->left,B->left)&&identical(A->right,B->right)); 
}

int main()
{
    
}