// Problem-11 Give an algorithm for finding the height (or depth) of the binary tree without recursion

//Solution: using level order traversal. This is similar to BFS of Graph algorithms. End of
//level is identified with a marker

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *node)
{
    int result=0;
    TreeNode *temp = nullptr;
    TreeNode *marker = new TreeNode('#');  //using # as a marker for level completion
    queue<TreeNode *> q;
    if (!node)
        return 0;
    q.push(node);
    q.push(marker);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->val == '#'&&q.size()>0) //checking q.size() so as to not create an infinte loop
        {
            result++;
            q.push(marker);
        }

        else if (temp->val=='#')        //for the last marker
        {
            return ++result;
        }
        
        else
        {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
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
    root->right->right->right->right=new TreeNode(121);
    cout<<height(root);
}