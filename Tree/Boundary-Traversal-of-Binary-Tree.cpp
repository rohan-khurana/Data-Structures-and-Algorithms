#include<bits/stdc++.h>
using namespace std;

void printleftboundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left){
        cout<<root->val;
        printleftboundary(root->left);
    }
    else if(root->right){
        cout<<root->val;
        printleftboundary(root->right);
    }
}

void printleaves(TreeNode* root){
    if(root == NULL) return;
    printleaves(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->val;
    }
    printleaves(root->right);
}

void printrightbouundary(TreeNode* root){
    if(root==NULL) return;
    if(root->right){
        printrightboundary(root->right);
        cout<<root->val;
    }
    else if(root->left){
        printrightboundary(root->left);
        cout<<root->val;
    }
}

void boundaryTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val;

    printleftboundary(root->left);
    printleaves(root->left);
    printleaves(root->right);
    printrightboundary(root->right);

}