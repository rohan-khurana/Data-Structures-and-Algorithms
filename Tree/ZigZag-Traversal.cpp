#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
} Node;


void zigzagTraversal(Node* root){
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    vector<int> zigzag;
    
    currentLevel.push(root);
    bool lefttoright=true;

    while(!currentLevel.empty()){
        Node* temp=currentLevel.top();
        currentLevel.pop();

        if(temp){
            zigzag.push_back(temp->data);

            if(lefttoright==true){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currentLevel.empty()){
            lefttoright=!lefttoright;
            swap(currentLevel,nextLevel);
        }
    }
}