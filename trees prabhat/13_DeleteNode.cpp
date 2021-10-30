// Problem-13 Give an algorithm for deleting an element (assuming data is given) from binary
// tree.

// Solution: The deletion of a node in binary tree can be implemented as
// 1.Starting at root, find the node which we want to delete.
// 2.Find the deepest node in the tree.
// 3.Replace the deepest node’s data with node to be deleted.
// 4.Then delete the deepest node.

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

void deleteNode(TreeNode* root,int value)
{
    TreeNode* Deep=deepestNode(root); //2
    TreeNode* temp=nullptr;
    queue<TreeNode *> q;
    if (!root)
        return;
    q.push(root);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->val==value)//1
        {
            int x=temp->val;      //3
            temp->val=Deep->val;
            Deep->val=x;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    delete Deep; //4
    Deep=nullptr;
}
void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->val<<" ";
        print_inorder(node->right);
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
    deleteNode(root,17);
    print_inorder(root);
}