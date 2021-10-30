// Problem-5 Give an algorithm for inserting an element into binary tree.

// Solution: Since the given tree is a binary tree, we can insert the element wherever we want. To
// insert an element, we can use the level order traversal and insert the element wherever we find
// the node whose left or right child is NULL.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->val<<" ";
        print_inorder(node->right);
    }
}

void insert(TreeNode *node, int value)
{
    TreeNode *temp = nullptr;
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (!temp->left)
        {
            temp->left = new TreeNode(value);
            return;
        }
        if (temp->right)
            q.push(temp->right);
        if (!temp->right)
        {
            temp->right = new TreeNode(value);
            return;
        }
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
    print_inorder(root);
    cout<<endl;
    insert(root,111);
    print_inorder(root);
}