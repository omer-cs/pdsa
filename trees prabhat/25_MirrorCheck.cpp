// Problem-25 Given two trees, give an algorithm for checking whether they are mirrors of
// each other.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//code to convert given Tree to its mirror
TreeNode* mirror(TreeNode* root)
{
    TreeNode* temp;
    if(root)
    {
        mirror(root->left);
        mirror(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}

bool isMirror(TreeNode* root1,TreeNode* root2)
{
    if(!root1&&!root2)
        return true;
    if(!root1||!root2)
        return false;
    if(root1->val!=root2->val)
        return false;
    return(isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left));
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
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);
    root1->left->right=new TreeNode(5);
    mirror(root1);
    print_inorder(root);
    cout<<endl;
    print_inorder(root1);
    cout<<endl;
    cout<<isMirror(root,root1);
    
}