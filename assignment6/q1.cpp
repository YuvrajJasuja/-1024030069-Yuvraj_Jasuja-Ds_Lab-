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

    void insertFirst(int value) {
        Node* temp = new Node{value, head, nullptr};
        if (head) head->prev = temp;
        head = temp;
    }

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

    void insertAfter(int key, int value) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) return;
        Node* temp = new Node{value, p->next, p};
        if (p->next) p->next->prev = temp;
        p->next = temp;
    }

    void insertBefore(int key, int value) {
        if (!head) return;
        if (head->data == key) { insertFirst(value); return; }
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) return;
        Node* temp = new Node{value, p, p->prev};
        p->prev->next = temp;
        p->prev = temp;
    }

    void deleteNode(int key) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) return;
        if (p == head) head = p->next;
        if (p->next) p->next->prev = p->prev;
        if (p->prev) p->prev->next = p->next;
        delete p;
    }

    void search(int key) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (p) cout << "Found " << key << endl;
        else cout << "Not found\n";
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

    void insertFirst(int value) {
        Node* temp = new Node{value, nullptr, nullptr};
        if (!head) {
            head = temp;
            temp->next = temp;
        } else {
            Node* p = head;
            while (p->next != head) p = p->next;
            temp->next = head;
            p->next = temp;
            head = temp;
        }
    }

    void insertLast(int value) {
        Node* temp = new Node{value, nullptr, nullptr};
        if (!head) {
            head = temp;
            temp->next = temp;
        } else {
            Node* p = head;
            while (p->next != head) p = p->next;
            p->next = temp;
            temp->next = head;
        }
    }

    void insertAfter(int key, int value) {
        if (!head) return;
        Node* p = head;
        do {
            if (p->data == key) {
                Node* temp = new Node{value, p->next, nullptr};
                p->next = temp;
                return;
            }
            p = p->next;
        } while (p != head);
    }

    void insertBefore(int key, int value) {
        if (!head) return;
        Node* p = head;
        Node* prev = nullptr;
        do {
            if (p->data == key) {
                Node* temp = new Node{value, p, nullptr};
                if (p == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = temp;
                    temp->next = head;
                    head = temp;
                } else prev->next = temp;
                return;
            }
            prev = p;
            p = p->next;
        } while (p != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *p = head, *prev = nullptr;
        do {
            if (p->data == key) {
                if (p == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (head->next == head) { delete head; head = nullptr; return; }
                    last->next = head->next;
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                } else {
                    prev->next = p->next;
                    delete p;
                }
                return;
            }
            prev = p;
            p = p->next;
        } while (p != head);
    }

    void search(int key) {
        if (!head) { cout << "Not found\n"; return; }
        Node* p = head;
        do {
            if (p->data == key) { cout << "Found " << key << endl; return; }
            p = p->next;
        } while (p != head);
        cout << "Not found\n";
    }

    void display() {
        if (!head) { cout << "Empty\n"; return; }
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
    int ch, type, val, key;

    while (true) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoose type: ";
        cin >> type;
        if (type == 3) break;
        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before\n5. Delete\n6. Search\n7. Display\n8. Back\n";
        while (true) {
            cout << "Enter choice: ";
            cin >> ch;
            if (ch == 8) break;
            cout << "Enter value: ";
            if (ch != 5 && ch != 6) cin >> val;
            if (ch == 3 || ch == 4 || ch == 5 || ch == 6) {
                cout << "Enter key: ";
                cin >> key;
            }

            if (type == 1) {
                if (ch == 1) dll.insertFirst(val);
                else if (ch == 2) dll.insertLast(val);
                else if (ch == 3) dll.insertAfter(key, val);
                else if (ch == 4) dll.insertBefore(key, val);
                else if (ch == 5) dll.deleteNode(key);
                else if (ch == 6) dll.search(key);
                else if (ch == 7) dll.display();
            } else {
                if (ch == 1) cll.insertFirst(val);
                else if (ch == 2) cll.insertLast(val);
                else if (ch == 3) cll.insertAfter(key, val);
                else if (ch == 4) cll.insertBefore(key, val);
                else if (ch == 5) cll.deleteNode(key);
                else if (ch == 6) cll.search(key);
                else if (ch == 7) cll.display();
            }
        }
    }
}
