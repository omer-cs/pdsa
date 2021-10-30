// Problem-8 Give an algorithm for printing the level order data in reverse order. 

//Solution: use a stack and level order

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_reverse_levelorder(TreeNode *node)
{
    TreeNode* temp=nullptr;
    stack<int>s;
    queue<TreeNode *> q;
    if (!node)
        return;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        s.push(temp->val);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }  
}
int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    print_reverse_levelorder(root);
}