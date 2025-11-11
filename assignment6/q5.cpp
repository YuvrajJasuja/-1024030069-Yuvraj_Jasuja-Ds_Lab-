#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertLast(int value) {
        Node* temp = new Node{value, nullptr};
        if (!head)
            head = temp;
        else {
            Node* p = head;
            while (p->next)
                p = p->next;
            p->next = temp;
        }
    }

    void makeCircular() {
        if (!head) return;
        Node* p = head;
        while (p->next)
            p = p->next;
        p->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;
        return (temp == head);
    }

    void display(int count = 10) {
        Node* p = head;
        for (int i = 0; p && i < count; i++) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertLast(2);
    list.insertLast(4);
    list.insertLast(6);
    list.insertLast(7);
    list.insertLast(5);

    list.makeCircular(); 

    cout << "List: ";
    list.display();

    if (list.isCircular())
        cout << "True";
    else
        cout << "False";
}
