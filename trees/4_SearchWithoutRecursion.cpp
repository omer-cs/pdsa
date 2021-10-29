// Problem-4 Give an algorithm for searching an element in binary tree without recursion.

// Solution: We can use level order traversal for solving this problem. The only change required in
// level order traversal is, instead of printing the data, we just need to check whether the root data is
// equal to the element we want to search.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool search(TreeNode *node,int value)
{
    TreeNode* temp=nullptr;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->val==value)//just check while popping
            return true; 
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return false;
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
    cout<<search(root,121);
}