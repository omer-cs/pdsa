// Problem-33 Given a tree with a special property where leaves are represented with ‘L’ and
// internal node with ‘I’. Also, assume that each node has either 0 or 2 children. Given
// preorder traversal of this tree, construct the tree.
// Example: Given preorder string => ILILL

//       I
//     /  \
//    L     I
//         / \
//         L  L    

// Solution: First, we should see how preorder traversal is arranged. Pre-order traversal means
// first put root node, then pre-order traversal of left subtree and then pre-order traversal of right
// subtree. In a normal scenario, it’s not possible to detect where left subtree ends and right subtree
// starts using only pre-order traversal. Since every node has either 2 children or no child, we can
// surely say that if a node exists then its sibling also exists. So every time when we are computing a
// subtree, we need to compute its sibling subtree as well.

// Secondly, whenever we get ‘L’ in the input string, that is a leaf and we can stop for a particular
// subtree at that point. After this ‘L’ node (left child of its parent ‘L’), its sibling starts. If ‘L’ node is
// right child of its parent, then we need to go up in the hierarchy to find the next subtree to compute.

// Keeping the above invariant in mind, we can easily determine when a subtree ends and the next
// one starts. It means that we can give any start node to our method and it can easily complete the
// subtree it generates going outside of its nodes. We just need to take care of passing the correct
// start nodes to different sub-trees.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(string &preorder,int i)
{
    TreeNode* newNode= new TreeNode(preorder[i]);
    
    if(i>preorder.size()-1)
        return nullptr;
    if(preorder[i]=='L')
    {
        return newNode;
    }
    i++;
    newNode->left=buildTree(preorder,i);
    i++;
    newNode->right=buildTree(preorder,i);
    return newNode;
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

int main()
{
    string s="ILILL";
    TreeNode* res=buildTree(s,0);
    print_inorder(res);  //L I L I L
}