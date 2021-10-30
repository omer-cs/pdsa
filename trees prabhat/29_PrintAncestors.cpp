// Problem-29 Give an algorithm for printing all the ancestors of a node in a Binary tree.

// Solution: Apart from the Depth First Search of this tree, we can use the following recursive way
// to print the ancestors.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int printAncestors(TreeNode* root,TreeNode* value)
{
    if(root==nullptr)
        return 0;
    if(root->left==value||root->right==value||printAncestors(root->left,value)||printAncestors(root->right,value))
    {
        cout<<root->val<<endl;
        return 1;
    }
    return 0;
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
    TreeNode* x=new TreeNode(22);
    root->right->right->right->right=x;
    printAncestors(root,x);
}