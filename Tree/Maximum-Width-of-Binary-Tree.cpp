#include<bits/stdc++.h>
using namespace std;

int maxWidth(TreeNode *root){
    if(right==NULL){
        return 0;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    int result=0;

    while(!q.empty()){
        int n=q.size();
        result=max(result,n);
        
        while(count--){
            TreeNode *curr=q.front();
            q.pop();

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    return result;
}