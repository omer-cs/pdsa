#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool search(TreeNode *root, int key) {
    if(root == nullptr)
        return false;
    if(root->val == key)
        return true;
    // if(search(root->left, key))
    //     return true;
    // if(search(root->right, key))
    //     return true;
    // return false;
    return search(root->left, key)||search(root->right,key);
    //line number 26 is short form for above commented lines
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
    cout<<search(root,40)<<endl;
    return 0;
}