// Problem-24 Give an algorithm for converting a tree to its mirror. Mirror of a tree is another
// tree with left and right children of all non-leaf nodes interchanged.


#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirror(TreeNode* root)
{
    TreeNode* temp;
    if(root)
    {
        mirror(root->left);
        mirror(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}

void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->val<<" ";
        print_inorder(node->right);
    }
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    print_inorder(root);
    cout<<endl;
    mirror(root);
    print_inorder(root);
}