#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
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

int NthNode(Node* head, int index){
    int count=0;
    Node* curr=head;
    while(curr!=NULL){
        if(count==index){
            return curr->value;
        }
        count++;
        curr=curr->next;
    }
    return (-1);
}

int main(){
    Node* head=NULL;
    int n,x,index;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtEnd(&head,x);
    }
    cin>>index;
    cout<<NthNode(head,index-1);
    return 0;
}
