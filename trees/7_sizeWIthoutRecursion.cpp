// Problem-7 Give an algorithm for finding the size of binary tree without recursion

// Solution: level order traversal

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int size(TreeNode *node)
{
    int result=0;
    TreeNode* temp=nullptr;
    queue<TreeNode *> q;
    if (!node)
        return 0;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        result++;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return result;
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
    cout<<size(root);
}

