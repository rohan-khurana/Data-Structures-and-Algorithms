#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr);
    TreeNode(int x) : val(x), left(nullptr), right(nullptr);
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right);
};

bool pathSum(TreeNode* root, int targetSum){
    if(root==NULL){
        return false;
    }
    if(targetSum==root->val && root->left==NULL && root->right==NULL){
        return true;
    }
    return pathSum(root->left, targetSum-root->val) || pathSum(root->right, targetSum-root->val);
}

//Complexity: O(n)

void getAllPaths(TreeNode *root, int targetSum, vector<int> temp, vector<vector<int>> &result){
    if(root==NULL){
        return;
    }
    if(root->data==targetSum && root->left==NULL && root->right==NULL){
        temp.push_back(root->val);
        result.push_back(temp);
        return;
    }
    temp.push_back(root->val);
    getAllPaths(root->left, targetSum-root->val, temp, result);
    getAllPaths(root->right, targetSum-root->val, temp, result);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<vector<int> result;
    getAllPaths(root, targetSum, {}, result);
    return result;
}