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

void insertAtEnd(Node** head,int val){
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

int midElement(Node* head){
    Node* ptr1=head;
    Node* ptr2=head;
    if(head!=NULL){
        while(ptr2!=NULL && ptr2->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
        }
        return ptr1->value;
    }
    return -1;
}

int main(){
    int n,x;
    cin>>n;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtEnd(&head,x);
    }
    cout<<midElement(head);
    return 0;
}