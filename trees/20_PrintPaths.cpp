#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

void print(vector<int>A) {
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<"->";
    }
    cout<<"NULL\n";
}

void printPath(TreeNode *root, vector<int>path) {
    if(root == nullptr)
        return;
    path.push_back(root->val);
    
    if(!root->left && !root->right)
        print(path);
    else{
        printPath(root->left, path);
        printPath(root->right, path);
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
    vector<int>A;
    printPath(root,A);
}