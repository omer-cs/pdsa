// Problem-21 Give an algorithm for checking the existence of path with given sum. That
// means, given a sum, check whether there exists a path from root to any of the nodes.
// Solution: For this problem, the strategy is: subtract the node value from the sum before calling its
// children recursively, and check to see if the sum is 0 when we run out of tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root,int sum)
{
    if(root==nullptr)
        return sum==0;
    else
    {
        int remSum=sum-root->val;

        if((root->left&&root->right)||(!root->left&&!root->right))
            return hasPathSum(root->left,remSum)||hasPathSum(root->right,remSum);
        else if(root->left)
            return hasPathSum(root->left,remSum);
        else
            return hasPathSum(root->right,remSum);
    }
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
    cout<<hasPathSum(root,107);
}