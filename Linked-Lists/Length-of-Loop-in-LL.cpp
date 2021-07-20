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

int countNodes(Node* ptr){
    int count=1;
    Node* temp=ptr;
    while(temp->next!=ptr){
        count++;
        temp=temp->next;
    }
    return count;
}

int loopLength(Node* head){
    Node* slowPtr=head;
    Node* fastPtr=head;
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        if(slowPtr->value==fastPtr->value){
            return countNodes(slowPtr);
        }
    }
    return 0;
}

int main(){
    Node* head=NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 2);
    head->next->next->next->next->next=head->next->next;
    cout<<loopLength(head);
    return 0;
}