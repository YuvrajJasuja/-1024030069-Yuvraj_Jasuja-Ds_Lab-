#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertLast(int value) {
        Node* temp = new Node{value, nullptr, nullptr};
        if (!head) head = temp;
        else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = temp;
            temp->prev = p;
        }
    }

    int size() {
        int count = 0;
        Node* p = head;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }

    void display() {
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertLast(int value) {
        Node* temp = new Node{value, nullptr, nullptr};
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

    int size() {
        if (!head) return 0;
        int count = 0;
        Node* p = head;
        do {
            count++;
            p = p->next;
        } while (p != head);
        return count;
    }

    void display() {
        if (!head) return;
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);

    cll.insertLast(5);
    cll.insertLast(15);
    cll.insertLast(25);
    cll.insertLast(35);

    cout << "Doubly Linked List: ";
    dll.display();
    cout << "Size: " << dll.size() << endl;

    cout << "Circular Linked List: ";
    cll.display();
    cout << "Size: " << cll.size() << endl;
}
