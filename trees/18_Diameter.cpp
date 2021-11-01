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
// didn't understand the concept clearly
// try asking others if they got the logic correctly
// or alteast try to learn the logic from internet
int diameter(TreeNode *root, int &result) {
    if(root == nullptr)
        return 0;
    int l = diameter(root->left, result);
    int r = diameter(root->right, result);
    int temp = max(l,r)+1;
    int ans = max(temp, l+r+1);
    result = max(result, ans);
    return temp;
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
    root->right->right->right->right=new TreeNode(22);
    int result=0;
    diameter(root, result);
    cout<<result<<endl;    
    return 0;
}