#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};
void push(Node** last, int val){
    Node *node=new Node(val);
    Node *ptr=*last;
    if(*last==NULL){
        *last=node;
        node->next=*last;
        return;
    }
    node->next=ptr->next;
    ptr->next=node;
    *last=node;
    return;
}

void printList(Node* last){
    if(last==NULL){
        return;
    }
    Node *node=last->next;
    do{
        cout<<node->value<<"->";
        node=node->next;
    }while(node!=last->next);
    cout<<endl;
    return;
}

int main(){
    int n,x;
    cin>>n;
    Node *last=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        push(&last, x);
    }
    printList(last);
    return 0;
}