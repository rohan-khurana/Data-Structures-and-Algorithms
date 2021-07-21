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

Node* sortedUnion(Node* headA, Node* headB){
    Node* result=NULL;
    Node* A=headA;
    Node* B=headB;

    while(A!=NULL && B!=NULL){
        if(A->value<B->value){
            push(&result,A->value);
            A=A->next;
        }
        else if(B->value<A->value){
            push(&result,B->value);
            B=B->next;
        }
        else{
            push(&result,A->value);
            A=A->next;
            B=B->next;
        }
    }
    while(A!=NULL){
        push(&result,A->value);
        A=A->next;
    }
    while(B!=NULL){
        push(&result,B->value);
        B=B->next;
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

    headC=sortedUnion(headA, headB);

    printList(headC);
    return 0;
}