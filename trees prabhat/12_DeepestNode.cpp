//Problem-12 Give an algorithm for finding the deepest node of the binary tree.

//Solution:just return the last element in level order

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* deepestNode(TreeNode *node)
{
   TreeNode* temp=nullptr;
    queue<TreeNode *> q;
    if (!node)
        return nullptr;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
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
    TreeNode* res=deepestNode(root);
    cout<<res->val;
}