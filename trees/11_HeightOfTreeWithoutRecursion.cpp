#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int val): val(x), left(NULL), right(NULL) {}
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int height(TreeNode *root) {
    TreeNode* temp = nullptr;
    TreeNode* marker = new TreeNode('#');
    queue<TreeNode *>q;
    q.push(root);
    q.push(marker);
    int result = 0;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->val == '#' && q.size() >0) {
            result++;
            q.push(marker);
        }
        else if( temp->val == '#') {
            return ++result;
        }
        else {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return result;
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
    cout<<height(root)<<endl;
    return 0;
}