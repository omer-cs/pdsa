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

void print(vector<int>A) {
    for(int i=0; i<A.size(); i++)
        cout<<A[i]<<"->";
    cout<<"NULL\n";
}

void pathWithSum(TreeNode *root, vector<int>path, int target) {
    if(root == nullptr)
        return;
    path.push_back(root->val);
    
    if(!root->left && !root->right) {
        int sum =0;
        for(auto it:path)
            sum+=it;
        if(sum == target)
            print(path);
    }
    else {
        pathWithSum(root->left, path, target);
        pathWithSum(root->right, path, target);
    }
}

bool hasPathSum(TreeNode *root, int sum) {
    if(root == nullptr)
        return sum == 0;
    else {
        int remSum = sum - root->val;
        if((root->left&&root->right)||(!root->left&&!root->right))
            return hasPathSum(root->left, remSum)||hasPathSum(root->right, remSum);
        else if(root->left)
            return hasPathSum(root->left, remSum);
        else
            return hasPathSum(root->right, remSum);
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
    pathWithSum(root,A, 209);
    cout<<hasPathSum(root, 209)<<endl;
}