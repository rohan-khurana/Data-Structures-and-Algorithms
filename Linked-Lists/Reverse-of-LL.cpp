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

void push(Node** head, int val){
    Node *node=new Node(val);
    Node *last= *head;

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

void printList(Node* head){
    Node *node=head;
    if(node==NULL){
        return;
    }
    while(node!=NULL){
        cout<<node->value<<"->";
        node=node->next;
    }
    cout<<endl;
    return;
}

void reverseLL(Node** head){
    Node *current=*head;
    Node *prev=NULL;
    Node *next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

int main(){
    int n,x;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        push(&head,x);
    }
    printList(head);
    reverseLL(&head);
    printList(head);
    return 0;
}