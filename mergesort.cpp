#include<iostream>

using namespace std;

struct node{
    int data;
    node * next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class lists{
    node * head;
    // node * head1;
    // node * head2;
    // node * start;

    public:
        lists(){
            head = NULL;
            // head1 = NULL;
            // head2 = NULL;
            // start = NULL;
        }

        void inslis(int item){
            if(head==NULL){
                head=new node(item);
                return;
            }
            node* newnode1=new node(item);
            newnode1->next=head;
            head=newnode1;
            return;
        }

        void calmergesort(){
            node* i;
            for(i = head;i->next!=NULL;i=i->next);
            head = split(head,i);
            return;
        }

        // void inslis2(int item){
        //     if(head2==NULL){
        //         head2 = new node(item);
        //         return;
        //     }
        //     node* newnode2 =new node(item);
        //     newnode2->next=head2;
        //     head2=newnode2;
        //     return;
        // }

        // 

        node* split(node* beg,node* end){
            node* mid = NULL,*head1,*head2;
            end->next = NULL;
            if(beg == NULL){
                return NULL;
            }
            if(beg->next == NULL){
                return beg;
            }
            node* fast = beg;
            node* slow = beg;
            
            while(fast != NULL){
                fast = fast->next;
                if(fast != NULL){
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            mid = slow;
            if(mid->next == NULL)
                head2 = NULL;
            else        
                head2 = split(mid->next,end);
            
            head1 = split(beg,mid);
            beg = merge(head1,head2);
            return beg;
        }

        node* merge(node* ptr1,node *ptr2) {
            node * temp,*start = NULL;
            while (ptr1 != NULL && ptr2 != NULL) {
                if (ptr1->data < ptr2->data) {
                    temp = ptr1;
                    ptr1 = ptr1->next;
                    temp->next = start;
                    start = temp;
                }
                else if (ptr1->data > ptr2->data) {
                    temp = ptr2;
                    ptr2 = ptr2->next;
                    temp->next = start;
                    start = temp;
                }
                else {
                    temp = ptr2;
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                    temp->next = start;
                    start = temp;
                }
            }

            if (ptr1 != NULL) {
                while (ptr1 != NULL) {
                    temp = ptr1;
                    ptr1 = ptr1->next;
                    temp->next = start;
                    start = temp;

                }
            }

            if (ptr2 != NULL) {
                while (ptr2 != NULL) {
                    temp = ptr2;
                    ptr2 = ptr2->next;
                    temp->next = start;
                    start = temp;
                }
            }
            return start;
	    }

        void display() {
            node * temp = head;
            cout<<"\n";
            while (temp!= NULL) {
                cout << temp->data<<"\t";
                temp = temp->next;
            }
        }
};

int main(){
    lists m1;
    m1.inslis(5);
    m1.inslis(4);
    m1.inslis(6);
    m1.inslis(3);
    m1.inslis(1);
    m1.calmergesort();
    m1.display();
    system("pause");
    return 0;
}

    //void inslis(){
        //     node * temp;
        //     if(head1==NULL && head2==NULL){
        //         cout<<"\n\nboth lists are empty  now......";
        //         return;
        //     }
        //     if(head1==NULL){
        //         head->next=head2;
        //         head = head2;
        //         return;
        //     }
        //     if(head2==NULL){
        //         head->next=head1;
        //         head=head1;
        //         return;
        //     }

        //     if(head1->data < head2->data){
        //         temp = head1;
        //         head1 = head1->next;
        //         if(head == NULL){
        //             head=temp;
        //             start=head;
        //         }
        //         else{
        //             head->next=temp;
        //             head=temp;
        //         }
        //     }
        //     else{
        //         temp=head2;
        //         head2=head2->next;
        //         if(head == NULL){
        //             head=temp;
        //             start=head;
        //         }
        //         else{
        //             head->next=temp;
        //             head=temp;
        //         }
        //     }
        //     inslis();
        // }