#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

bool identical(TreeNode *A, TreeNode *B) {
    if(A==nullptr && B==nullptr)
        return true;
    if(A==nullptr || B==nullptr)
        return false;
    return ((A->val == B->val) && identical(A->left, B->left) && identical(A->right, B->right));
}

int main() {

    TreeNode *roota=new TreeNode(17);
    roota->left=new TreeNode(41);
    roota->right=new TreeNode(9);
    roota->left->left=new TreeNode(29);
    roota->left->right=new TreeNode(6);
    roota->right->left=new TreeNode(81);
    roota->right->right=new TreeNode(40);
    roota->right->right->right=new TreeNode(121);

    TreeNode *rootb=new TreeNode(17);
    rootb->left=new TreeNode(41);
    rootb->right=new TreeNode(9);
    rootb->left->left=new TreeNode(29);
    rootb->left->right=new TreeNode(6);
    rootb->right->left=new TreeNode(81);
    rootb->right->right=new TreeNode(40);
    rootb->right->right->right=new TreeNode(111);
    cout<<identical(roota, rootb)<<endl;
    return 0;
}