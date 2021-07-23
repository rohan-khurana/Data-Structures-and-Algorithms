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

void push(Node** head,int val){
    Node* node=new Node(val);
    if(*head==NULL){
        *head=node;
        return;
    }
    Node* last=*head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=node;
    return;
}

void EvenOddLL(Node** head){
    Node* last=*head;
    Node* current=*head;
    Node* prev=NULL;
    while(last->next!=NULL){
        last=last->next;
    }
    Node* lastptr=last;
    while(current->value%2!=0 && current!=last){
        lastptr->next=current;
        current=current->next;
        last->next->next=NULL;
        lastptr=lastptr->next;
    }
    if(current->value%2==0){
        *head=current;
        while(current!=last){
            if(current->value%2==0){
                prev=current;
                current=current->next;
            }
            else{
                prev->next=current->next;
                current->next=NULL;
                lastptr->next=current;
                lastptr=current;
                current=prev->next;
            }
        }
    }
    else{
        prev=current;
    }
    if (lastptr != last && (last->value) % 2 != 0)
    {
        prev->next = last->next;
        last->next = NULL;
        lastptr->next = last;
    }
    return;
}

void printList(Node* head){
    if(head==NULL){
        return;
    }
    while(head!=NULL){
        cout<<head->value<<"->";
        head=head->next;
    }
    cout<<endl;
}


int main(){
    Node* head=NULL;
    int n,x;
    for(int i=0;i<n;i++){
        cin>>x;
        push(&head,x);
    }
    printList(head);
    EvenOddLL(&head);
    printList(head);
    return 0;
}