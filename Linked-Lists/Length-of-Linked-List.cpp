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

int count(Node* node){
    int count=0;
    while(node!=NULL){
        count++;
        node=node->next;
    }
    return count;
}
void printList(Node* node){
    while(node!=NULL){
        cout<<node->value<<"->";
        node=node->next;
    }
}
int main(){
    Node* head=NULL;
    char ch;
    int x;
    do{
        cin>>x;
        insertAtBegin(&head,x);
        cout<<"Do you want to add more?(Y/N)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    cout<<count(head)<<"\n";
    printList(head);
}