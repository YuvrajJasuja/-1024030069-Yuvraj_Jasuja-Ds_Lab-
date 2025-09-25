//listA = [4,1,8,5], listB = [5,6,1,8,5]
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
void attach(node* &head,node* &common){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=common;
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
void intersection(node* &head1,node* &head2){
    cout<<endl<<"intersection ";
    node *temp1=head1;
    node *temp2=head2;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        while(temp2!=NULL){
            temp2=temp2->next;
            if(temp1->next==temp2->next){
                cout<<"found at "<<temp1->next->data;
            }
        }
    }


}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    node *common=NULL;

    insert(head1,4);
    insert(head1,1);
    insert(head2,5);
    insert(head2,6);
    insert(head2,1);
    insert(common,8);
    insert(common,5);

    attach(head1,common);
    attach(head2,common);

    display(head1);
    display(head2);

    intersection(head1,head2);

    return 0;
}