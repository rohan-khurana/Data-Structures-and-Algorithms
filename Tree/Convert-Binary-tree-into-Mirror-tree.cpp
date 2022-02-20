#include <bits/stdc++.h>
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
Node* constructBT(string s){
    Node* root=new Node(s[0]-'0');
    stack<Node*> st;

    for(int i=1;i<s.size();i++){
        if(s[i]=='('){
            st.push(root);
        }
        else if(s[i]==')'){
            root=st.top();
            st.pop();
        }
        else{
            if(root->left==nullptr){
                Node* left=new Node(s[i]-'0');
                root->left=left;
                root=root->left;
            }
            else if(root->right==nullptr){
                Node* right=new Node(s[i]-'0');
                root->right=right;
                root=root->right;
            }
        }
    }
    return root;
}
void preorder(Node* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    string s;
    getline(cin, s);
    Node* root=constructBT(s);
    preorder(root);
}