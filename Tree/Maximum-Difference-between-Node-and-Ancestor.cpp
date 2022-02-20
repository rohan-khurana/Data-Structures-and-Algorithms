#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

int res;

void maxDifference(Node* root, int maxs, int mins){
    if(!root){
        return;
    }

    int maxs=max(root->val, maxs);
    int mins=min(root->val, mins);

    res=max(res, maxs-mins);

    maxDifference(root->left, maxs, mins):
    maxDifference(root->right, maxs, mins);
}


int main(){

}