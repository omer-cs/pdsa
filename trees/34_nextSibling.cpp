// Problem-34 Given a binary tree with three pointers (left, right and nextSibling), give an
// algorithm for filling the nextSibling pointers assuming they are NULL initially.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *nextSibling;  //cause the question said assume they exist and are NULL initally
    TreeNode(int x) : val(x), left(NULL), right(NULL), nextSibling(NULL) {}
};

void FillNextSiblings(TreeNode* root)
{
    TreeNode* temp;
    TreeNode* marker=new TreeNode('#');
    queue<TreeNode*>q;
    if(!root)
        return ;
    q.push(root);
    q.push(marker);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->val=='#'&&q.size()>0)
        {
            q.push(marker);
        }
        else if(temp->val=='#')   //important condition dont ever dare forget
            return ;
        else
        {
            temp->nextSibling=q.front()->val=='#'?nullptr:q.front();  //if next is marker then the node doesnt have any nextSibling
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    FillNextSiblings(root);
    cout<<root->left->right->nextSibling->val;
}