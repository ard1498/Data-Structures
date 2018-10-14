#include<iostream>

using namespace std;

struct node {
    int data;
    node * next;

    node(int data){
        this->data=data;
        this->next = NULL;
    }
};

class lists{
    node * start;
    public:
    lists(){
        start = NULL;
    }
    void insertion(int item){
        if(start == NULL){
            start = new node(item);
            return;
        }
        node * n1= new node(item);
        n1->next = start;
        start = n1;
    }
    void checkduplicates(){
        node * ptr = start;
        while(ptr != NULL){
            node* ptr1 = ptr;
            while(ptr1->next != NULL){
                if(ptr->data == ptr1->next->data) 
                    ptr1->next=ptr1->next->next;
                else
                    ptr1=ptr1->next;
            }
            ptr=ptr->next;
        }
    }

    void  display(){
        node * ptr =start;
        while(ptr!=NULL){
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        return;
    }
};

int main(){
    lists l1;
    l1.insertion(9);
    l1.insertion(7);
    l1.insertion(9);
    l1.insertion(7);
    l1.insertion(5);
    l1.display();
    l1.checkduplicates();
    l1.display();
    return 0;
}
