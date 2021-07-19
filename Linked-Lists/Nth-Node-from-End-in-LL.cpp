#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};

void insertAtEnd(Node** head, int val){
    Node* node=new Node(val);
    Node* last=*head;
    if(*head==NULL){
        *head=node;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=node;
    return;
}

int NthNodeFromEnd(Node* head,int index){
    int len=0;
    Node* ptr=head;
    while(ptr!=NULL){
        len++;
        ptr=ptr->next;
    }
    if(index>len || index<1){
        return (-1);
    }
    ptr=head;
    for(int i=0;i<len-index;i++){
        ptr=ptr->next;
    }
    return ptr->value;
}

int main(){
    int n,x, index;
    Node* head=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtEnd(&head,x);
    }
    cin>>index;
    cout<<NthNodeFromEnd(head,index);
    return 0;
}