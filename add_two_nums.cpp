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
	node * head;
	node * head1;
	node * head2;
	node * start;
	node * start1;
	node * start2;

public:
	lists() {
		head = NULL;
		head1 = NULL;
		head2 = NULL;
		start = NULL;
		start1 = NULL;
		start2 = NULL;
	}

	void ins1(int item) {
		if (start1 == NULL) {
			start1 = new node(item);
			//head1 = start1;
			return;
		}
		node * newnode1 = new node(item);
		newnode1->next = start1;
		start1 = newnode1;
	}

	void ins2(int item) {
		if (start2 == NULL) {
			start2 = new node(item);
			//head2 = start2;
			return;
		}
		node * newnode2 = new node(item);
		newnode2->next = start2;
		start2 = newnode2;
	}

	void ins(int sum) {
		if (start == NULL) {
			start = new node(sum);
			head = start;
			return;
		}
		else {
			node * newnode = new node(sum);
			newnode->next = start;
			start = newnode;
		}
	}

	void revlist(int n) {
		node * ptr;
		switch (n) {
		case 1:
			while (start1 != NULL) {
				ptr = start1;
				start1 = start1->next;
                ptr->next = head1;
                head1 = ptr;
			}
			break;

		case 2:
			while (start2 != NULL) {
				ptr = start2;
				start2 = start2->next;
                ptr->next = head2;
                head2 = ptr;
			}
			break;
		default:
			cout<<"\nhi";
			break;
		}
	}

	void add(int carry, node * ptr1, node * ptr2) {
		int sum;

		if (carry != 0) {
			sum = carry;
			carry--;
		}
		else
			sum = 0;

		if (ptr1 == NULL && ptr2 == NULL) {
			ins(sum);
			return;
		}

		if (ptr2 == NULL && ptr1 != NULL) {
			sum += ptr1->data;
			if (sum >= 10) {
				sum -= 10;
				carry++;
			}
			ins(sum);
			ptr1 = ptr1->next;
		}

		if (ptr1 == NULL && ptr2 != NULL) {
			sum += ptr2->data;
			if (sum >= 10) {
				sum -= 10;
				carry++;
			}
			ins(sum);
			ptr2 = ptr2->next;
		}

		if (ptr1 != NULL && ptr2 != NULL) {
			sum += ptr1->data + ptr2->data;
			if (sum >= 10) {
				sum -= 10;
				carry++;
			}
			ins(sum);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}


		add(carry, ptr1, ptr2);
		return;
	}

	void calladd() {
		add(0, start1, start2);
		return;
	}

	void display() {
		node * ptr;
		ptr = head1;
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->next;
		}
		cout << "\n+\n";
		ptr = head2;
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->next;
		}

		cout<<"\n-----------\n";
		ptr = start;
		while(ptr != NULL){
		cout<<ptr->data;
		ptr=ptr->next;
		}
		cout<<"\n-----------\n";

		return;
	}
};

int main() {
	lists l1;
	l1.ins1(1);
	l1.ins1(9);
	l1.ins1(9);
	l1.ins2(1);
	l1.ins2(7);
	l1.calladd();
	l1.revlist(1);
	l1.revlist(2);
	l1.display();
	return 0;
}
