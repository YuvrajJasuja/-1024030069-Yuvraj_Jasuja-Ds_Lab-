#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insert(node* &head,int data){
    node *newnode=new node(data); 
    if (head == NULL) {   
        head = newnode;
        return;
    }
        
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
}

void display(node* &head)
{
    cout<<" head -> ";
    node* temp=head;
    while(temp!=NULL){
        
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

void reverse(node* &head,int key){
    node* prev=NULL;
    node* curr=head;
    node* next=curr->next;
    node* check=head;
    
    while(check!=NULL){
    
    for(int i=0;i<=key;i++)
    {
        if(check==NULL){
            return;
        }
        check=check->next;
    }
    if(check->next!=NULL){
        while(next!=check->next){
        if(prev==NULL){
            next->next=head;
            next=next->next;
            prev=curr;
            curr=curr->next;
        }
        else 
        next->next=curr->next;
        next=next->next;
        prev=curr;
        curr=curr->next;
    }}}}


int main(){
    int key=3;
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    display(head);

    reverse(head,key);
    cout<<"endl";
    display(head);

    return 0;
}