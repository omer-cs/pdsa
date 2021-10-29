// Problem-18 Give an algorithm for finding the diameter of the binary tree. The diameter of a
// tree (sometimes called the width) is the number of nodes on the longest path between two
// leaves in the tree.

// Solution: To find the diameter of a tree, first calculate the diameter of left subtree and right
// subtrees recursively. Among these two values, we need to send maximum value along with
// current level (+1).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameter(TreeNode* root,int &result)  //result will have the final ans
{
    if(root==NULL)
        return 0;
    int l=diameter(root->left,result);
    int r=diameter(root->right,result);

    int temp=max(l,r)+1;
    int ans=max(temp,l+r+1);
    result=max(result,ans);
    return temp;
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
    int result=0;
    diameter(root,result);
    cout<<result;
}