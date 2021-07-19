#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    
};
void insertAtBegin(Node** head, int val){
    Node* node=new Node();
    node->value=val;
    node->next=(*head);
    *head=node;

}
void insertAtEnd(Node** head, int val){
    Node* node=new Node();
    node->value=val;
    node->next=NULL;
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

void deleteNode(Node** head, int val){
    Node* ptr=*head;
    Node* prev=NULL;
    if(ptr!=NULL && ptr->value==val){
        *head=ptr->next;
        delete ptr;
        return;
    }
    else{
        while(ptr!=NULL && ptr->value!=val){
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            return;
        }
        prev->next=ptr->next;
        delete ptr;
    }
}

void printList(Node* node){
    while(node!=NULL){
        cout<<node->value<<"->";
        node=node->next;
    }
}
int main(){
    Node* head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtEnd(&head,x);
    }
    printList(head);
    cout<<"\n Delete:";
    cin>>x;
    deleteNode(&head,x);
    printList(head);
    return 0;
}