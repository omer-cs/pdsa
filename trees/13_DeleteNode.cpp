#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* deepestNode(TreeNode *root) {
    TreeNode *temp = nullptr;
    queue<TreeNode *>q;
    if(!root)
        return nullptr;
    q.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return temp;
}

void deleteNode(TreeNode *root, int val) {
    bool flag =false;
    TreeNode *temp = nullptr;
    queue<TreeNode *>q;
    if(!root)
        return;
    q.push(root);
    TreeNode *Deep = deepestNode(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->val == val ){
            temp->val = Deep->val;
            flag = true;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(flag) {
        delete temp;
        temp = nullptr;
    }
}

void print_inorder(TreeNode *root) {
    if(root != nullptr) {
        print_inorder(root->left);
        cout<<root->val<<" ";
        print_inorder(root->right);
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
    print_inorder(root);
    cout<<endl;
    deleteNode(root, 0);
    print_inorder(root);
    cout<<endl;
}