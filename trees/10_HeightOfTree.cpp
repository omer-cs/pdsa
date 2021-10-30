#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int height(TreeNode *root) {
    if(root == nullptr)
        return 0;
    return 1+max(height(root->left), height(root->right));
    // Below is the implementation of Prabhats program, I'm not sure why prabhat used the variables to store the height of left and right subtree
    // int l = height(root->left);
    // int r = height(root->right);
    // return 1+max(l,r);
}

int main() {
    TreeNode *root=new TreeNode(17);
    root->left=new TreeNode(41);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(29);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(81);
    root->right->right=new TreeNode(40);
    root->right->right->right=new TreeNode(121);
    cout<<height(root)<<endl;
    return 0;
}