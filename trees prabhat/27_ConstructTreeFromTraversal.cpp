// Problem-27 Give an algorithm for constructing binary tree from given Inorder and Preorder
// traversals.

// Algorithm: BuildTree()
// 1 Select an element from Preorder. Increment a Preorder index variable
// (preOrderIndex in code below) to pick next element in next recursive call.
// 2 Create a new tree node (newNode) from heap with the data as selected element.
// 3 Find the selected element’s index in Inorder. Let the index be inOrderIndex.
// 4 Call BuildBinaryTree for elements before inOrderIndex and make the built tree as left
// subtree of newNode.
// 5 Call BuildBinaryTree for elements after inOrderIndex and make the built tree as right
// subtree of newNode.
// 6 return newNode.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//this is for preorder and inorder
TreeNode* buildTree(vector<int>&preOrder,vector<int>&inOrder,int start,int end,int &preOrderIndex)
{
    
    if(start>end)
        return nullptr;
    TreeNode* newNode=new TreeNode(preOrder[preOrderIndex++]);
    if (start==end)
    {
        return newNode;
    }
    int inOrderIndex=find(inOrder.begin(),inOrder.end(),newNode->val)-inOrder.begin(); //** syntax to get index of an element
    newNode->left=buildTree(preOrder,inOrder,start,inOrderIndex-1,preOrderIndex);
    newNode->right=buildTree(preOrder,inOrder,inOrderIndex+1,end,preOrderIndex);
    return newNode;
}

//this is for postorder and inorder
TreeNode* buildTree_1(vector<int>&inOrder,vector<int>&postOrder,int start,int end,int &postOrderIndex)
{
    if(start>end)
        return nullptr;
    TreeNode* newNode=new TreeNode(postOrder[postOrderIndex--]);
    if (start==end)
    {
        return newNode;
    }
    int inOrderIndex=find(inOrder.begin(),inOrder.end(),newNode->val)-inOrder.begin(); // syntax to get index of an element
    newNode->right=buildTree_1(inOrder,postOrder,inOrderIndex+1,end,postOrderIndex);
    newNode->left=buildTree_1(inOrder,postOrder,start,inOrderIndex-1,postOrderIndex);
    return newNode;
}

//***********USE A MAP FOR INDICES TO DECREASE TIME LIMIT************************

// TreeNode* buildTreeHelper(vector<int>&preOrder,vector<int>&inOrder,int start,int end,int &preOrderIndex,unordered_map<int,int>&m)
// {
//     if(start>end)
//         return nullptr;
//     TreeNode* newNode=new TreeNode(preOrder[preOrderIndex++]);
//     if (start==end)
//     {
//         return newNode;
//     }
//     int inOrderIndex=m[newNode->val];
//     newNode->left=buildTreeHelper(preOrder,inOrder,start,inOrderIndex-1,preOrderIndex,m);
//     newNode->right=buildTreeHelper(preOrder,inOrder,inOrderIndex+1,end,preOrderIndex,m);
//     return newNode;
// }
// TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
//     unordered_map<int,int> m;
//     for(int i=0; i<A.size(); i++)
//     {
//         m[B[i]] = i;
//     }
//     int x=0;
//     return buildTreeHelper(A,B,0,A.size()-1,x,m);
// }
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
    vector<int> preorder = {1, 2, 3, 4, 5};
    vector<int> inorder = {3, 2, 4, 1, 5};
    vector<int> postorder = {3, 4, 2, 5, 1};
    int x=postorder.size()-1;
    TreeNode* res = buildTree_1(inorder,postorder,0,inorder.size()-1,x);
    // int y=0;
    // TreeNode* res1=buildTree(preorder,inorder,0,preorder.size()-1,y);
    print_inorder(res);
}