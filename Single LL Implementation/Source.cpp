#include<iostream>
using namespace std;
class Lnode {
public:

	int data;
	Lnode* next;

	Lnode(int d) {
		this->data = d;
		this->next = NULL;
	}

	~Lnode() {
		int displaydata = this->data;
		if (this->next != 0) {
			delete next;
			this->next = NULL;
		}
		cout << "Memory is free for node with Data: " << displaydata << endl;
	}

};

void insertathead(Lnode* &head, int data) {
	Lnode* temp = new Lnode(data);
	temp->next = head;
	head = temp;
}

void insertatTail(Lnode* &tail , int data) {
	Lnode* temp = new Lnode(data);
	tail->next = temp;
	tail = temp;
}

void displayfromHead(Lnode* &head) {
	Lnode* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void insertatanyposition(Lnode*& Head, Lnode*& Tail, int position, int data) {
	if (position == 1) {
		insertathead(Head, data);
		return;
	}

	Lnode* temp = Head;
	int count = 1;
	while (count < position - 1) {
		temp = temp->next;
		count++;
	}

	if (temp->next == NULL) {
		insertatTail(Tail, data);
		return;
	}

	Lnode* NodetoNext = new Lnode(data);
	NodetoNext->next = temp->next;
	temp->next = NodetoNext;
}

void deletenode(int position, Lnode*& Head,Lnode* &Tail) {
	if (position == 1) {
		Lnode* tempdelete = Head;
		Head = Head->next;
		tempdelete->next = NULL;
		delete tempdelete;
	}
	else {
		Lnode* curr = Head;
		Lnode* prev = NULL;

		int count = 1;
		while (count < position) {
			prev = curr;
			curr = curr->next;
			count++;
		}
		
		if (curr->next == NULL) {
			Tail = prev;
		}

		prev->next = curr->next; 
		curr->next = NULL;
		delete curr;
	}
}

int main() {
    Lnode* node1 = new Lnode(10);
    Lnode* Head = node1;
    Lnode* Tail = node1;

    int choice;
    do {
        cout << "\n====== Linked List Menu ======" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Insert at Any Position" << endl;
        cout << "4. Delete First Node" << endl;
        cout << "5. Delete Middle Node" << endl;
        cout << "6. Delete Last Node" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Show Head and Tail Values" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter value to insert at head: ";
            cin >> data;
            insertathead(Head, data);
            break;
        }
        case 2: {
            int data;
            cout << "Enter value to insert at tail: ";
            cin >> data;
            insertatTail(Tail, data);
            break;
        }
        case 3: {
            int pos, data;
            cout << "Enter position:";
            cin >> pos;
            cout << endl;
            cout<<"Enter the value: ";
            cin >> data;
            cout << endl;
            insertatanyposition(Head, Tail, pos, data);
            break;
        }
        case 4: {
            deletenode(1, Head, Tail);
            cout << "First node deleted.\n";
            break;
        }
        case 5: {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            deletenode(pos, Head, Tail);
            break;
        }
        case 6: {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            deletenode(pos, Head, Tail);
            cout << "Last node deleted.\n";
            break;
        }
        case 7:
            displayfromHead(Head);
            break;

        case 8:
            cout << "Head: " << (Head ? Head->data : -1) << endl;
            cout << "Tail: " << (Tail ? Tail->data : -1) << endl;
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}