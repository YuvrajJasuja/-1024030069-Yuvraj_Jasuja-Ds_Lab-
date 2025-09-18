//h-1-1-2-2-1n k=1 2-2
#include<iostream>
using namespace std;
  int count=0;
class node{
    public:
    int data;
    node* next;
  
    node(int data){
       this->data=data;
       this->next=NULL;
    }};

    void insertHead(node* &head, int data) {
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;
         }
           void dele(int key,node* &head){
        node* temp=head;
        node* prev=NULL;
         while (temp != NULL && temp->data != key) 
        {
        prev = temp;
        temp = temp->next;
        }
        if (prev == NULL) { 
    head = temp->next; 
}
    else
    {prev->next = temp->next;}
    delete temp;
    }

    void remove(int key,node* &head){
        node* temp=head;
        while (temp!=NULL)
        {
            if(temp->data==key)
            {
                count++;
                dele(key,head);
                temp=head;
            }
            else
            temp=temp->next;
        }
        
    }
  

        void display(node* head) {
        node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node* head=NULL;
    insertHead(head, 10);
    insertHead(head, 30);
    insertHead(head, 20);
    insertHead(head, 10);

    cout << "Original list: ";
    display(head);

    remove(10, head);

    cout << "After removing 10: "<<endl;
    display(head);

    cout<<count;
return 0;
}