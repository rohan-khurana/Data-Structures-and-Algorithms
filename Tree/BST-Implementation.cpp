#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class BST{
    int data;
    BST* left;
    BST* right;
public:
    BST();
    BST(int);
    BST* insert(BST*,int);
    void inorder(BST*);
    int height(BST*);
};

BST ::BST(){
    this->data=0;
    this->left=NULL;
    this->right=NULL;
}
BST ::BST(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}

BST* BST ::insert(BST* root, int value){
    if(root==NULL){
        return new BST(value);
    }

    if(value > root->data){
        root->right=insert(root->right,value);
    }
    else if(value <= root->data){
        root->left=insert(root->left,value);
    }

    return root;
}

void BST ::inorder(BST* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

int BST::height(BST* root){
    if(root=NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1 + max(lh,rh);
}

int main(){
    int n;
    BST b, *root=NULL;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    root=b.insert(root, arr[0]);
    for(int i=1;i<n;i++){
        b.insert(root, arr[i]);
    }
    b.inorder(root);
    cout<<b.height(root);
}