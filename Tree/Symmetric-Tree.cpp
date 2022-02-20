#include<bits/stdc++.h>
using namespace std;

bool isSymTree(TreeNode *root){
    if(root == NULL){
        return true;
    }
    return solve(root->left && root->right);
}

bool solve(TreeNode *l, TreeNode *r){
    if(l==NULL && r==NULL) return true;
    else if(l==NULL || r==NULL) return false;
    else if(l->val != r->val) return false;

    return solve(l->left,r->right) && solve(l->right, r->left);
}