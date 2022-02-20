#include<bits/stdc++.h>
using namespace std;

TreeNode* LCA(TreeNode* root, int n1, int n2){
    if(root == NULL) return root;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
 
    return root;
}