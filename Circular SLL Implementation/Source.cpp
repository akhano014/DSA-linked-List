#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed by deleting the value: " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int data) {
    if (tail == NULL) {
        Node* newNode = new Node(data);
        newNode->next = newNode;
        tail = newNode;
        return;
    }

    Node* curr = tail;
    do {
        if (curr->data == element) {
            Node* temp = new Node(data);
            temp->next = curr->next;
            curr->next = temp;
            if (curr == tail)
                tail = temp;
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element " << element << " not found in the list!" << endl;
}

void display(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void deleteNode(Node*& tail, int element) {
    if (tail == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev->next;

    while (curr->data != element) {
        prev = curr;
        curr = curr->next;
        if (curr == tail->next) {
            cout << "Element " << element << " not found!" << endl;
            return;
        }
    }

    prev->next = curr->next;

    if (curr == prev) {
        tail = NULL;
    }
    else if (curr == tail) {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

int main() {
    Node* tail = NULL;
    int choice, element, data;

    while (true) {
        cout << "\n==== Circular Linked List Menu ====\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element after which to insert (if list empty, enter -1): ";
            cin >> element;
            cout << "Enter data to insert: ";
            cin >> data;
            insertNode(tail, element, data);
            break;

        case 2:
            cout << "Enter element to delete: ";
            cin >> element;
            deleteNode(tail, element);
            break;

        case 3:
            cout << "Current List: ";
            display(tail);
            break;

        case 4:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
