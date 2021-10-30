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

void deleteTree(TreeNode *root) {
    if(root == nullptr) return;
    if(root!=nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        cout<<"Deleting: "<<root->val<<" ";
        root->left = nullptr;
        root->right = nullptr;
        delete root;
    }
}
// Below is the prabhats implementation for delete tree functionccl

// void deleteTree(TreeNode *root) {
//     if(root == nullptr)
//         return;
//     deleteTree(root->left);
//     deleteTree(root->right);
//     delete root;
// }

int main() {
    TreeNode *root=new TreeNode(17);
    root->left=new TreeNode(41);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(29);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(81);
    root->right->right=new TreeNode(40);
    root->right->right->right=new TreeNode(121);
    deleteTree(root);
    
}