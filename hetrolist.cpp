#include<iostream>

using namespace std;

struct node1;
struct node2;

struct node1 {
	int data;
	node2 * next;

	node1(int data) {
		this->data = data;
		this->next = NULL;
	}
};

struct node2 {
	char data;
	node1 * next;

	node2(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class list {
	node1 * head1;
	node1 * start;
	node2 * head2;
	int n;
public:
	list() {
		start = NULL;
		head1 = NULL;
		head2 = NULL;
		n = 0;
	}

	void insert_int(int ele) {
		if (start == NULL) {
			start = new node1(ele);
			head1 = start;
			cout << "\nhead 1 is created:" << head1->data;
			n++;
			return;
		}
		while (head1->next->next != NULL) {
			head1 = head1->next->next;
		}
		node1 * newnode = new node1(ele);
		head1->next->next = newnode;
		head1 = newnode;
		n++;
		cout << "\nvalue inserted at last." << head1->data;
		return;
	}

	void insert_char(char ele) {
		if (start == NULL) {
			cout << "\nnot possible...";
			return;
		}
		if (start->next == NULL) {
			head2 = new node2(ele);
			cout << "\nhead 2 created:" << head2->data;
			start->next = head2;
			n++;
			return;
		}
		while (head2->next->next != NULL) {
			head2 = head2->next->next;
		}
		node2 * newnode = new node2(ele);
		head2->next->next = newnode;
		head2 = newnode;
		n++;
		cout << "\nelement inserted at last." << head2->data;
		return;
	}

	void display() {
		if (start == NULL) {
			cout << "\nlist is empty....";
			return;
		}

		cout << "\n";
		cout << "\nn is:" << n << "\n";
		node1 * ptr = start;

		if (n % 2 == 0 && head2!=NULL) {
			while (ptr != head2->next) {
				cout << ptr->data;
				cout << ptr->next->data;
				ptr = ptr->next->next;
			}
		}
		else {
			while (ptr != head1) {
				cout << ptr->data;
				cout << ptr->next->data;
				ptr = ptr->next->next;
			}
			cout << ptr->data;
		}

		return;
	}

	void deletion() {
		node1 * ptr = start;
		if (head1 == start) {
			if (start->next == head2 && head2!=NULL) {
				head2=NULL;
				head1->next = NULL;
				return;
			}
			cout << "\ndeletion not posible";
			return;
		}
		else{
			if (n % 2 != 0) {
				node1 * temp = head1;
				while (ptr->next->next != head1) {
					ptr = ptr->next->next;
				}
				head1 = ptr;
				head2 = ptr->next;
				delete temp;
				n--;
				return;
			}
			else {
				node2 * temp = head2;
				while (ptr->next->next->next != head2) {
					ptr = ptr->next->next;
				}
				head2 = ptr->next;
				head1 = ptr->next->next;
				delete temp;
				n--;
				return;
			}
		// else{
		//     cout<<"nothing";
		//     return;
		}
	}
	void displayheads() {
		cout << head1->data;
		cout << head2->data;
	}
};

int main() {
	list l1;

	l1.insert_int(9);
	l1.insert_char('w');
	l1.insert_int(8);
	l1.insert_char('m');
	l1.insert_int(7);
	l1.display();
	// 9w8m7
	//cout << "\ndisplaying heads:";
	//l1.displayheads();

	l1.deletion();
	cout << "\n";
	l1.display();
	//9w8m

	l1.deletion();
	cout << "\n";

	//l1.displayheads();
	//cout << "\n";
	l1.display();
	//9w8

	l1.deletion();

	cout << "\n";
	l1.display();
	//9w

	l1.deletion();

	cout << "\n";
	l1.display();
	//9
	l1.deletion();

	cout << "\n";
	l1.display();
	//not possible.
	//l1.deletion();

	return 0;
}
