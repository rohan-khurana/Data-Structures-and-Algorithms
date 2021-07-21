#include<iostream>
#include<unordered_set>
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
    unordered_set<int> seen;

    Node* current=head;
    Node* prev=NULL;
    if(current==NULL)
        return;
    
    while(current!=NULL){
        if(seen.find(current->value)!=seen.end()){
            prev->next=current->next;
            delete(current);
        }
        else{
            seen.insert(current->value);
            prev=current;
        }
        current=prev->next;
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