#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

// (a) Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning.\n";
}

// (b) Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << value << " inserted at the end.\n";
}

// (c) Insert before a specific value
void insertBefore(int target, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Target " << target << " not found.\n";
    } else {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted before " << target << ".\n";
    }
}

// (c) Insert after a specific value
void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Target " << target << " not found.\n";
    } else {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted after " << target << ".\n";
    }
}

// (d) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

// (e) Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
}

// (f) Delete a specific node
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node " << value << " not found.\n";
    } else {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted: " << delNode->data << endl;
        delete delNode;
    }
}

// (g) Search for a node
void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << value << " not found in the list.\n";
}

// (h) Display list
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menu
int main() {
    int choice, value, target;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> value;
            insertBefore(target, value);
            break;
        case 4:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> value;
            insertAfter(target, value);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            searchNode(value);
            break;
        case 9:
            displayList();
            break;
        case 10:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
