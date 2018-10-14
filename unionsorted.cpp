//union + intersection in sorted lists.......


#include<iostream>

using namespace std;

struct node {
	int data;
	node * next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class lists {
	node * start;
	node *start1;
	node *start2;
	node *head1;
	node *head2;
public:

	lists() {
		start = NULL;
		start1 = NULL;
		start2 = NULL;
		head1 = NULL;
		head2 = NULL;
	}

	void ins1(int item) {
		if (start1 == NULL) {
			start1 = new node(item);
			head1 = start1;
			return;
		}
		node * newnode1 = new node(item);
		start1->next = newnode1;
		start1 = newnode1;
	}

	void ins2(int item) {
		if (start2 == NULL) {
			start2 = new node(item);
			head2 = start2;
			return;
		}
		node * newnode2 = new node(item);
		start2->next = newnode2;
		start2 = newnode2;
	}
    void intersection(){
        node * ptr1 = head1;
		node * ptr2 = head2;
		node * temp;
		//cout << "\n in union function.";
		while (ptr1 != NULL && ptr2 != NULL) {
			//cout << "\nin while.";
            if (ptr1->data > ptr2->data) {
				ptr2 = ptr2->next;
            }
			else if (ptr1->data < ptr2->data) {
				ptr1 = ptr1->next;
			}
            else{
				temp = ptr1;
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
				temp->next = start;
				start = temp;
			}
		}
    }

	void _union() {
		node * ptr1 = head1;
		node * ptr2 = head2;
		node * temp;
		//cout << "\n in union function.";
		while (ptr1 != NULL && ptr2 != NULL) {
			//cout << "\nin while.";
			if (ptr1->data > ptr2->data) {
				temp = ptr2;
				ptr2 = ptr2->next;
				temp->next = start;
				start = temp;

			}
			else if (ptr1->data < ptr2->data) {
				temp = ptr1;
				ptr1 = ptr1->next;
				temp->next = start;
				start = temp;

			}
			else {
				temp = ptr1;
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
				temp->next = start;
				start = temp;
			}
		}

		if (ptr1 != NULL) {
			//cout << "\nin if of ptr1";
			while (ptr1 != NULL) {
				//cout << "\nin while of if1.:";
				temp = ptr1;
				ptr1 = ptr1->next;
				temp->next = start;
				start = temp;

			}
		}

		if (ptr2 != NULL) {
			//cout << "\nin if of ptr2.";
			while (ptr2 != NULL) {
				temp = ptr2;
				ptr2 = ptr2->next;
				temp->next = start;
				start = temp;

			}
		}
		//cout << "\n out of union function.''";
	}

	void display() {
		node * ptr = head1;
		while (ptr != NULL) {
			cout << ptr->data<<"\t";
			ptr = ptr->next;
		}
		cout << "\n";
		ptr = head2;
		while (ptr != NULL) {
			cout << ptr->data<<"\t";
			ptr = ptr->next;
		}

	}

	void display1() {
		node * ptr;
		ptr = start;
		while (ptr != NULL) {
			cout << ptr->data << "\t";
			ptr = ptr->next;
		}
	}
};

int main() {
	lists l1;

	l1.ins1(2);
	l1.ins1(9);
	l1.ins1(11);
	l1.ins1(12);

	l1.ins2(2);
	l1.ins2(3);
	l1.ins2(9);
	l1.ins2(11);
	l1.ins2(12);
	l1.ins2(17);
	l1.display();
	//l1._union();
	l1.intersection();
	cout<<"\n";
	l1.display1();
	return 0;
}
