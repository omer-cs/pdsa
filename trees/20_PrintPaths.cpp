// Problem-20 Given a binary tree, print out all its root-to-leaf paths.

//Solution: Store path in an array then when you reach a leaf print it out
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"->";
    cout<<"end"<<endl;
}

void printPaths(TreeNode* root,vector<int>path) //dont pass the vector by reference  
{
    if(root==nullptr)
        return;
    path.push_back(root->val);

    if(!root->left&&!root->right)
    {
        print(path);
    }
    else
    {
        printPaths(root->left,path);
        printPaths(root->right,path);
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
    printPaths(root,A);
}