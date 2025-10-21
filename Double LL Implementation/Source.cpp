#include<iostream>
using namespace std;

class Lnode {
public:
	int data;
	Lnode* next;
	Lnode* prev;

	Lnode(int d) {
		this->data = d;
		this->next = NULL;
		this->prev = NULL;
	}

	~Lnode() {
		int displaydata = this->data;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "Memory is free for node with Data: " << displaydata << endl;
	}
};

void insertathead(Lnode*& head, Lnode*& tail, int data) {
	if (head == NULL) {
		Lnode* temp = new Lnode(data);
		head = temp;
		tail = temp;
	}
	else {
		Lnode* temp = new Lnode(data);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void insertatTail(Lnode*& head, Lnode*& tail, int data) {
	if (tail == NULL) {
		Lnode* temp = new Lnode(data);
		head = temp;
		tail = temp;
	}
	else {
		Lnode* temp = new Lnode(data);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

void displayfromHead(Lnode*& head) {
	Lnode* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void insertatanyposition(Lnode*& Head, Lnode*& Tail, int position, int data) {
	if (position == 1) {
		insertathead(Head, Tail, data);
		return;
	}

	Lnode* temp = Head;
	int count = 1;
	while (count < position - 1) {
		temp = temp->next;
		count++;
	}

	if (temp->next == NULL) {
		insertatTail(Head, Tail, data);
		return;
	}

	Lnode* NodetoInsert = new Lnode(data);
	NodetoInsert->next = temp->next;
	temp->next->prev = NodetoInsert;
	temp->next = NodetoInsert;
	NodetoInsert->prev = temp;
}

void deletenode(int position, Lnode*& Head, Lnode*& Tail) {
	if (position == 1) {
		Lnode* tempdelete = Head;
		if (tempdelete->next != NULL) {
			Head = Head->next;
			Head->prev = NULL;
		}
		else {
			Head = NULL;
			Tail = NULL;
		}
		tempdelete->next = NULL;
		delete tempdelete;
	}
	else {
		Lnode* curr = Head;
		int count = 1;
		while (count < position) {
			curr = curr->next;
			count++;
		}

		curr->prev->next = curr->next;

		if (curr->next != NULL) {
			curr->next->prev = curr->prev;
		}
		else {
			Tail = curr->prev;
		}

		curr->next = NULL;
		curr->prev = NULL;
		delete curr;
	}
}

int main() {
	Lnode* node1 = new Lnode(10);
	Lnode* Head = node1;
	Lnode* Tail = node1;

	int choice;
	do {
		cout << "\n====== Doubly Linked List Menu ======" << endl;
		cout << "1. Insert at Head" << endl;
		cout << "2. Insert at Tail" << endl;
		cout << "3. Insert at Any Position" << endl;
		cout << "4. Delete First Node" << endl;
		cout << "5. Delete Middle Node by Position" << endl;
		cout << "6. Delete Last Node by Position" << endl;
		cout << "7. Display List" << endl;
		cout << "8. Show Head and Tail Values" << endl;
		cout << "9. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int data;
			cout << "Enter value to insert at head: ";
			cin >> data;
			insertathead(Head, Tail, data);
			break;
		}
		case 2: {
			int data;
			cout << "Enter value to insert at tail: ";
			cin >> data;
			insertatTail(Head, Tail, data);
			break;
		}
		case 3: {
			int pos, data;
			cout << "Enter position";
			cin >> pos;
			cout << endl;
		    cout<<"Enter the value: ";
			cin >>data;
			cout << endl;
			insertatanyposition(Head, Tail, pos, data);
			break;
		}
		case 4: {
			if (Head) {
				deletenode(1, Head, Tail);
				cout << "First node deleted.\n";
			}
			else {
				cout << "List is empty.\n";
			}
			break;
		}
		case 5: {
			if (Head) {
				int pos;
				cout << "Enter position to delete: ";
				cin >> pos;
				deletenode(pos, Head, Tail);
			}
			else {
				cout << "List is empty.\n";
			}
			break;
		}
		case 6: {
			if (Head) {
				int pos;
				cout << "Enter position of the last node to delete: ";
				cin >> pos;
				deletenode(pos, Head, Tail);
			}
			else {
				cout << "List is empty.\n";
			}
			break;
		}
		case 7:
			displayfromHead(Head);
			break;

		case 8:
			cout << "Head: " << (Head ? Head->data : -1) << endl;
			cout << "Tail: " << (Tail ? Tail->data : -1) << endl;
			break;

		case 9:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice! Try again.\n";
		}

	} while (choice != 0);

	if (Head != NULL) {
		delete Head;
		Head = NULL;
		Tail = NULL;
	}

	return 0;
}