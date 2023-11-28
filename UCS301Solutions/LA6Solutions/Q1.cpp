#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertFirst(int data);
    void insertLast(int data);
    void insertAfter(int key, int data);
    void insertBefore(int key, int data);
    void deleteNode(int key);
    void searchNode(int key);
    void display();
};

void LinkedList::insertFirst(int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::insertLast(int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void LinkedList::insertAfter(int key, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        cout << "List is empty. Cannot insert after a specific node.\n";
        return;
    }

    Node* current = head;
    while (current->data != key) {
        current = current->next;
        if (current == head) {
            cout << "Node with key " << key << " not found.\n";
            return;
        }
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void LinkedList::insertBefore(int key, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        cout << "List is empty. Cannot insert before a specific node.\n";
        return;
    }

    Node* current = head;
    while (current->data != key) {
        current = current->next;
        if (current == head) {
            cout << "Node with key " << key << " not found.\n";
            return;
        }
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    if (current == head) {
        head = newNode;
    }
}

void LinkedList::deleteNode(int key) {
    if (!head) {
        cout << "List is empty. Cannot delete a node.\n";
        return;
    }

    Node* current = head;
    Node* toDelete = nullptr;

    while (current->data != key) {
        current = current->next;
        if (current == head) {
            cout << "Node with key " << key << " not found.\n";
            return;
        }
    }

    toDelete = current;

    if (toDelete == head) {
        head = toDelete->next;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
}

void LinkedList::searchNode(int key) {
    if (!head) {
        cout << "List is empty. Cannot search for a node.\n";
        return;
    }

    Node* current = head;
    int position = 1;

    do {
        if (current->data == key) {
            cout << "Node with key " << key << " found at position " << position << ".\n";
            return;
        }
        current = current->next;
        position++;
    } while (current != head);

    cout << "Node with key " << key << " not found.\n";
}

void LinkedList::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    LinkedList circularList;

    int choice, data, key;

    do {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert at the Beginning\n";
        cout << "2. Insert at the End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                circularList.insertFirst(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                circularList.insertLast(data);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter data to insert after " << key << ": ";
                cin >> data;
                circularList.insertAfter(key, data);
                break;
            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter data to insert before " << key << ": ";
                cin >> data;
                circularList.insertBefore(key, data);
                break;
            case 5:
                cout << "Enter key of node to delete: ";
                cin >> key;
                circularList.deleteNode(key);
                break;
            case 6:
                cout << "Enter key to search for: ";
                cin >> key;
                circularList.searchNode(key);
                break;
            case 7:
                cout << "Circular Linked List: ";
                circularList.display();
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}
