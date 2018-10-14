#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node {

	int data;
	string sub;
	node* next;
	node* nextsame;

	node(int data, string sub) {
		this->data = data;
		this->sub = sub;
		this->next = NULL;
		this->nextsame = NULL;
	}

    node(){
        this->nextsame = this;
        this->next = this;
    }

};

class lists {

	node *head;
	vector<node*> heads;
public:

	lists() {
		head = new node();
		heads.resize(3);
		for (int i = 0; i<3; i++)
			heads[i] = new node();
	}

	void insertion(int item, string sub) {
		node *newnode = new node(item, sub);
        if (head->next == head) {
			head->next = newnode;
			newnode->next = head;
		}
		else {
            node* cur = head;
		    node* ptr = head->next;
			while((ptr != head) && (ptr->data < newnode->data)) {
				cur = ptr;
				ptr = ptr->next;
			}
			if (cur != head) {
				newnode->next = ptr;
				cur->next = newnode;
			}
			else {
				newnode->next = head->next;
				head->next = newnode;
			}
		}
		newnode = assignpos(newnode);
		return;
	}

	node* assignpos(node* ptr) {
		int i;
		if (ptr->sub == "m") {
			i = 0;
		}
		if (ptr->sub == "y") {
			i = 1;
		}
		if (ptr->sub == "s") {
			i = 2;
		}

		if(heads[i]->nextsame == heads[i]){
			heads[i]->nextsame = ptr;
			ptr->nextsame = heads[i]; 
		}
		else{
			node* cur = heads[i];
			node* ptr1 = heads[i]->nextsame;
			
			while (ptr1 != heads[i] && ptr1->data < ptr->data) {
				cur = ptr1;
				ptr1 = ptr1->nextsame;
			}
		
			if (cur == heads[i]) {
				ptr->nextsame = heads[i]->nextsame;
				heads[i]->nextsame = ptr;
			}
			else {
				ptr->nextsame = ptr1;
				cur->nextsame = ptr;
			}
		}
		return ptr;
	}

	void display() {
		cout << "\n";
		node* ptr = head->next;
		while (ptr != head) {
			cout << ptr->data << "->";
			ptr = ptr->next;
		}
		cout<<ptr->next->data;

		for (int i = 0; i<3; i++) {
			ptr = heads[i]->nextsame;
			cout << "\n";
			while (ptr != heads[i]) {
				cout << ptr->data << "->";
				ptr = ptr->nextsame;
			}
			cout<<ptr->nextsame->data;
		}
	}
};

int main() {
	lists l1;
	string sub;
	int ch, item;
	do {
		cout << "\nenter the item(int) and sub(string):";
		cin >> item >> sub;
		l1.insertion(item, sub);
		cout << "\nwant to enter more?(1 or 0):";
		cin >> ch;
	} while (ch == 1);
	cout << "\n";
	l1.display();
    system("pause");
	return 0;
}