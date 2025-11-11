#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertLast(int value) {
        Node* temp = new Node{value, nullptr};
        if (!head) {
            head = temp;
            temp->next = head;
        } else {
            Node* p = head;
            while (p->next != head) p = p->next;
            p->next = temp;
            temp->next = head;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty";
            return;
        }
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << head->data << endl;  
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertLast(20);
    cll.insertLast(100);
    cll.insertLast(40);
    cll.insertLast(80);
    cll.insertLast(60);

    cout << "Output: ";
    cll.display();
}
