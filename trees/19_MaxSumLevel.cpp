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

int maxSumLevel(TreeNode *root) {
    int currSum=root->val,currLevel,maxSum=root->val,maxLevel=0;
    TreeNode *temp = nullptr;
    TreeNode *marker = new TreeNode('#');
    queue<TreeNode *> q;
    if(!root)
        return 0;
    q.push(root);
    q.push(marker);

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp->val == '#' && q.size()>0) {
            maxSum = max(maxSum, currSum);
            cout<<currSum<<endl;
            if(maxSum == currSum)
                maxLevel = currLevel;
            currSum = 0;
            currLevel++;
            q.push(marker);
        }

        else if(temp->val == '#') {
            maxSum = max(maxSum, currSum);
            cout<<currSum<<endl;
            if(maxSum == currSum)
                maxLevel = currLevel;
            return maxLevel;
        }

        else {
            currSum += temp->val;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
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
    root->right->right->right->right=new TreeNode(22);
    cout<<maxSumLevel(root)<<endl;
    return 0;
}