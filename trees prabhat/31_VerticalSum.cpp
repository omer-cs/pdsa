// Problem-31 Give an algorithm for finding the vertical sum of a binary tree. For example, The
// tree has 5 vertical lines

//       1
//     /  \
//    2    3 
//   / \   / \
//  4   5  6  7        

// Vertical-1: nodes-4 => vertical sum is 4
// Vertical-2: nodes-2 => vertical sum is 2
// Vertical-3: nodes-1,5,6 => vertical sum is 1 + 5 + 6 = 12
// Vertical-4: nodes-3 => vertical sum is 3
// Vertical-5: nodes-7 => vertical sum is 7
// We need to output: 4 2 12 3 7

// Solution: We can do an inorder traversal and hash the column. We call
// VerticalSumlnBinaryTreefroot, 0) which means the root is at column 0. While doing the traversal,
// hash the column and increase its value by root → data.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int,int>m;   //used a map instead of a vector cause we have no idea of the left most node location

void VerticalSum(TreeNode* root,int col)
{
    if(root==nullptr)
        return;
    VerticalSum(root->left,col-1);
    m[col]+=root->val;
    VerticalSum(root->right,col+1);
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    m.clear();
    VerticalSum(root,0);
    auto it=m.begin();
    while(it!=m.end())
    {
        cout<<it->second<<" ";
        it++;
    }
}