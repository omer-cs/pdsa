// Problem-23 Give an algorithm for finding the sum of all elements in binary tree without recursion

// Solution: We can use level order traversal with simple change. Every time after deleting an
// element from queue, add the nodes data value to sum variable.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum(TreeNode *node)
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
        result+=temp->val;
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
    root->right->right->right->right=new TreeNode(22);
    cout<<sum(root);
}