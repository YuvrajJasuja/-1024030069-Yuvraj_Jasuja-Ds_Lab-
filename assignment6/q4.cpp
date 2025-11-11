#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertLast(char value) {
        Node* temp = new Node{value, nullptr, nullptr};
        if (!head) head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
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

int main() {
    DoublyLinkedList dll;
    string word;
    cout << "Enter word: ";
    cin >> word;

    for (char c : word)
        dll.insertLast(c);

    cout << "List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << "True";
    else
        cout << "False";
}
