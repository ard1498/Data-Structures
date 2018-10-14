//loop applied successfully......
#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};

class linked_list{
	node * head;
    node * start;
	public:
	linked_list(){
		head=NULL;
		start=NULL;
	}

	void insertion(int item){
		if(head==NULL){
			head=new node(item);
			start=head;
			return;
		}

		node *np = new node(item);
        start->next=np;
        start=np;
	}

	void makeloop(){
        if(head!=NULL){
            start->next=start;
        }
	}

    void checkloop(){
        int flag=0;
        node * ptr1 = head;
        node * ptr2 = head;
        while(ptr2 != NULL && ptr2->next != NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
            if(ptr1==ptr2){
                flag=1;
                cout<<"\nloop exists.";
                break;
            }
        }
        if(flag==0)
            cout<<"\ndoes not exists.";
        return;
    }

    void display(){
		node *temp=head;
		if(temp==NULL){
			cout<<"\nlist is empty ....";
			return;
		}
		while(temp!=NULL){
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		return;
	}
};

int main(){
    linked_list l1;
    l1.insertion(9);
    l1.insertion(2);
    l1.insertion(3);
    l1.insertion(4);
    l1.insertion(7);
    l1.makeloop();
    l1.checkloop();
    return 0;
}
