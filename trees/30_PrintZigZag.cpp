// Problem-30 Zigzag Tree Traversal: Give an algorithm to traverse a binary tree in Zigzag
// order.For example, the output for the tree below should be: 1 3 2 4 5 6 7


//       1
//     /  \
//    2    3 
//   / \   / \
//  4   5  6  7        


// Solution: This problem can be solved easily using two stacks. Assume the two stacks are:
// currentLevel and nextLevel. We would also need a variable to keep track of the current level
// order (whether it is left to right or right to left).

// We pop from currentLevel stack and print the node’s value. Whenever the current level order is
// from left to right, push the node’s left child, then its right child, to stack nextLevel. Since a stack
// is a Last In First Out (LIFO) structure, the next time that nodes are popped off nextLevel, it will
// be in the reverse order.

// On the other hand, when the current level order is from right to left, we would push the node’s
// right child first, then its left child. Finally, don’t forget to swap those two stacks at the end of each
// level (i. e., when currentLevel is empty).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void zigzag(TreeNode* root)
{
    TreeNode* temp;
    int leftToRight=1;        //flag for direction
    if(!root)
        return;
    stack<TreeNode*>currLevel;
    stack<TreeNode*>nextLevel;
    currLevel.push(root);
    while(!currLevel.empty())
    {
        temp=currLevel.top();
        currLevel.pop();

        if(temp)
        {
            cout<<temp->val<<" ";
            if (leftToRight)
            {
                if(temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if(temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }   
        }
        if (currLevel.empty())
        {
            leftToRight=1-leftToRight;       //toggle 
            swap(currLevel,nextLevel);
        }
        
    }

}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->right->right->right=new TreeNode(8);
    root->right->right->right->right=new TreeNode(9);
    zigzag(root);
}