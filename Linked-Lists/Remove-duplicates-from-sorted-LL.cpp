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

void removeDuplicates(Node* head){
    Node* current=head;
    Node* temp;
    if(current==NULL)
        return;
    
    while(current->next!=NULL){
        if(current->value==current->next->value){
            temp=current->next->next;
            free(current->next);
            current->next=temp;
        }
        else{
            current=current->next;
        }
    }
}

void printList(Node* head){
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->value<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    int n,x;
    Node* head=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtEnd(&head,x);
    }
    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}