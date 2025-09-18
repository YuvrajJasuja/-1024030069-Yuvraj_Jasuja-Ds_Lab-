#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
    insertHead(int data,node* &head){

    }
};

int main() {
    node *head = NULL;
    int n=0;

    while(n!=10) {
        cout<<"\nEnter the task:"<<endl
            <<"2. Insertion at the beginning"<<endl
            <<"3. Insertion at the end"<<endl
            <<"4. Insertion in between"<<endl
            <<"5. Deletion from the beginning"<<endl
            <<"6. Deletion from end"<<endl
            <<"7. Delete a specific node"<<endl
            <<"8. Search a node"<<endl
            <<"9. Display all nodes"<<endl
            <<"10. Exit"<<endl;
        cin>>n;

        switch(n) {
            case 2: {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                insertHead(data, head);
                break;
            }
            case 3: {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                insertEnd(data, head);
                break;
            }
            case 4: {
                int data,pos;
                cout<<"Enter data: ";
                cin>>data;
                cout<<"Enter position: ";
                cin>>pos;
                insertAtPos(data,pos,head);
                break;
            }
            case 5:
                deleteHead(head);
                break;
            case 6:
                deleteEnd(head);
                break;
            case 7: {
                int val;
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteNode(val, head);
                break;
            }
            case 8: {
                int val;
                cout<<"Enter value to search: ";
                cin>>val;
                searchNode(val, head);
                break;
            }
            case 9:
                display(head);
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
