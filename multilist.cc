#include<iostream>

using namespace std;

struct node {
    int roll;
    char act;
    node* next,*snext,*mnext;
    node()
    {
        this->next =this; 
        this->mnext =this; 
        this->snext =this; 
    }
    node (int a, char b)
    {
        this->roll = a;
        this ->act = b;
    }
} ;

node* sptr,*mptr;

void insert(node* head,node* headm,node* heads)
{
    int r;
    char a;
    cout <<"enter roll" << endl;
    cin >> r;
    cout <<"enter act" <<endl;
    cin >> a;
    node* p = new node(r,a);
    node* cur,*prev;
    if (head->next == head)
    {
        head -> next = p;
        p-> next = head;
                if (a=='s')
                p->snext = heads;
                if (a=='m')
                p->mnext = headm;
    }
    else
    {
        cur = head->next;
        while(cur != head)
        {
            if(cur->roll < r && cur->next ==head)
            {
                cur ->next = p;
                p->next = head;
                if (a=='s')
                p->snext = heads;
                if (a=='m')
                p->mnext = headm;
            }

            else if (cur-> roll > r && cur->next !=head)
            {
                prev->next = p;
                p->next  = cur;
                if (a=='s')
                p->snext = heads;
                if (a=='m')
                p->mnext = headm;
            }
            // else if(cur-> roll < r && cur-> next != head)
            // {
                prev=cur;
                cur= cur->next;
            // }
            // csur
        }

    }
    cur = head->next;
    while (cur!=head)
    {
        if (cur->act == 's')
        {
            if (heads->snext == heads)
            {
                heads->snext = cur;
                cur-> snext =  heads;
                sptr = cur;
            }
            else
            {
                sptr->snext = cur;
                sptr = cur;
                cur -> snext = heads;
            }
        }
        if (cur->act == 'm')
           {
            if (headm->mnext == headm)
            {
                headm->mnext = cur;
                cur-> mnext =  headm;
                mptr = cur;
            }
            else
            {
                mptr->mnext = cur;
                mptr = cur;
                cur -> mnext = headm;
            }
        }
        cur = cur->next;
    }
}

int main()
{
    int i;
    char ch ='y';
    node* head = new node;
    node* heads = new node;
    node* headm = new node;
    
    while(ch=='y')
    {
        insert(head,headm,heads);
        cout << "enter more ?";
        cin >> ch ;
    }
    node* ptr=head->next;
    node* ptr1=heads->snext;
    node* ptr2=headm->mnext;
    cout<<  "main list "<< endl; 
    while (ptr!=head)
    {
        cout << ptr-> roll << " " ;
        ptr = ptr->next;
    }
    cout <<"sports list"<< endl;
    while (ptr1!=heads)
    {
        cout << ptr1->roll << " ";
        ptr1=ptr1->snext;
    }
    cout << endl;
    while (ptr2!= headm)
    {
        cout << ptr2->roll<< " ";
        ptr2 = ptr2->mnext;
    }
    return 0;
}