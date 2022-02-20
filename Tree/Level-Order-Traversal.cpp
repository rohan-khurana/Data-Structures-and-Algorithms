#include<bits/stdc++.h>
using namespace std;

vector<int> levelOrder(TreeNode *root){
    if(root==NULL){
        return new vector<int>();
    }
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr=q.top();
        q.pop();

        result.push_back(curr->data);
        
        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }

    }
    return result;
}