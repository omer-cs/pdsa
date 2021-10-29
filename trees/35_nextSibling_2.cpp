// Problem-35 Is there any other way of solving Problem-34?

// Solution: The trick is to re-use the populated nextSibling pointers. As mentioned earlier, we just
// need one more step for it to work. Before we pass the left and right to the recursion function
// itself, we connect the right child’s nextSibling to the current node’s nextSibling left child. In order
// for this to work, the current node nextSibling pointer must be populated, which is true in this
// case.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *nextSibling;  //cause the question said assume they exist and are NULL initally
    TreeNode(int x) : val(x), left(NULL), right(NULL), nextSibling(NULL) {}
};

void FillNextSiblings(TreeNode* root)
{
    if(!root)
        return;
    if(root->left)
        root->left->nextSibling=root->right;
    if(root->right)
        root->right->nextSibling=(root->nextSibling)?root->nextSibling->left:nullptr; //check if your root has a next sibling only then you root->right will have a next sibling
    FillNextSiblings(root->left);
    FillNextSiblings(root->right);
}

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    FillNextSiblings(root);
    cout<<root->left->right->nextSibling->val;
}