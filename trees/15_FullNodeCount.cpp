#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int fullNodeCount(TreeNode *root) {
    TreeNode *temp = nullptr;
    queue<TreeNode *>q;
    if(!root)
        return 0;
    q.push(root);
    int fc = 0;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->left && temp->right){
            // cout<<temp->val<<" ";
            fc++;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return fc;
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
    cout<<fullNodeCount(root)<<endl;
    return 0;
}