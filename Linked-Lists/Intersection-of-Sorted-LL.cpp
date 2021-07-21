#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->next=NULL;
        this->value=value;
    }
};

void push(Node** head, int val){
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

Node* sortedIntersection(Node* headA, Node* headB){
    Node* result=NULL;
    Node** temp=&result;
    Node* A=headA;
    Node* B=headB;

    while(A!=NULL && B!=NULL){
        if(A->value==B->value){
            push(temp,A->value);
            temp=&((*temp)->next);
            A=A->next;
            B=B->next;
        }
        else if(A->value<B->value){
            A=A->next;
        }
        else{
            B=B->next;
        }
    }
    return result;
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
    int n1,n2,x;
    Node* headA=NULL;
    Node* headB=NULL;
    Node* headC=NULL;

    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>x;
        push(&headA,x);
    }

    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>x;
        push(&headB,x);
    }

    printList(headA);
    printList(headB);

    headC=sortedIntersection(headA, headB);

    printList(headC);
    return 0;
}