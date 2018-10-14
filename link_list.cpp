//linked list is sorted....,.

#include<iostream>

using namespace std;

//class node{
//
//	public :
//		int data;
//		node *next;
//		node(int data){
//			this->data=data;
//			this->next=NULL;
//		}
//};


//this code works efficiently.....
struct node{
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};

class linked_list{
	node *head;

	public:
	linked_list(){
		head=NULL;
	}

	void insertion(int item){
		if(head==NULL){
			head=new node(item);
			return;
		}

		node *np = new node(item);
		if(item<head->data){
			np->next=head;
			head=np;
			return;
		}
		node * temp=head->next;
		node * prev=head;
		while(temp!=NULL){
			if(item<temp->data){
				np->next=temp;
				prev->next=np;
				return;
			}
			prev=temp;
			temp=temp->next;
		}
		prev->next=np;
		return;
	}

	void deletion(int item){
		if(head==NULL){
			cout<<"\nunderflow condition.";
			return;
		}

		node* prev=NULL;
		node *current=head;
		while(current!=NULL){
				if(item==current->data && prev==NULL){
					head=head->next;
					return;
				}
				if(item<current->data){
					break;
				}
				if(item==current->data){
					node* temp = current;
					prev->next=current->next;
					delete temp;
					return;
				}
				prev=current;
				current=current->next;
		}
		cout<<"\nitem not found..";
		return;
	}



	void display(){
		node *temp=head;
		if(temp==NULL){
			cout<<"\nlist is empty ....";
			return;
		}
		while(temp!=NULL){
			cout<<temp->data;
			temp=temp->next;
		}
		return;
	}
};

int main(){
	linked_list l1;
	l1.display();
	l1.insertion(2);
	l1.insertion(6);
	l1.insertion(1);
	l1.insertion(5);
	l1.insertion(4);
	l1.display();
	l1.deletion(1);
	l1.deletion(5);
	l1.deletion(3);
	l1.deletion(0);
	l1.display();
	return 0;
}
