#include<iostream>
#include<vector>

using namespace std;

struct node{
    int roll;
    char sub;
    node *next,*prev,*nextsame,*prevsame;
    
    node(){
        this->next = this;
        this->nextsame = this;
        this->prev = this;
        this->prevsame = this;
    }

    node(int r,char s){
        this->roll = r;
        this->sub = s;
        this->next = NULL;
        this->nextsame = NULL;
        this->prev = NULL;
        this->prevsame = NULL;
    }

};

class lists{
    node* head;
    vector<node*> heads;
    public:

    lists(){
        head = new node();
        heads.push_back(new node());
        heads.push_back(new node());
    }

    void insertion(int roll,char sub){
        node * n = new node(roll,sub);

        if(head->next == head){
            head->next = n;
            n->prev = head;
            n->next = head;
        }
        else{
            node *cur = head,*ptr = head->next;
            while(ptr != head){
                if((n->roll < ptr->roll) && (cur !=head)){
                    n->next = ptr;
                    n->prev = cur;
                    cur->next = n;
                    break;
                }
                else if(n->roll < ptr->roll && cur == head){
                    n->next = head->next;
                    n->prev = head;
                    head->next = n;
                    break;
                }
                else if(n->roll > ptr->roll && ptr->next == head){
                    ptr->next = n;
                    n->prev = ptr;
                    n->next = head;
                    break;
                }
                else{
                    cur = ptr;
                    ptr = ptr->next;
                }
            }
        }
        n = assignlist(n);
        return;
    }

    node* assignlist(node* n){
        int i;
        if(n->sub == 'y')
            i = 0;
        else if(n->sub == 'm')
            i = 1;
        else
            return n;
        
        if(heads[i]->nextsame == heads[i]){
            heads[i]->nextsame = n;
            n->prevsame = heads[i];
            n->nextsame = heads[i];
        }
        else{
            node* cur = heads[i], *ptr = heads[i]->nextsame;
            while(ptr != heads[i]){
                if((n->roll < ptr->roll) && (cur !=heads[i])){
                    n->nextsame = ptr;
                    n->prevsame = cur;
                    cur->nextsame = n;
                    break;
                }
                else if(n->roll < ptr->roll && cur == heads[i]){
                    n->nextsame = heads[i]->nextsame;
                    n->prevsame = heads[i];
                    heads[i]->nextsame = n;
                    break;
                }
                else if(n->roll > ptr->roll && ptr->nextsame == heads[i]){
                    ptr->nextsame = n;
                    n->prevsame = ptr;
                    n->nextsame = heads[i];
                    break;
                }
                else{
                    cur = ptr;
                    ptr = ptr->nextsame;
                }
            }
        }
        return n;
    }

    void display(int i){
        node* ptr;
        switch(i){
            case 1 :    ptr = head->next;
                        while(ptr != head){
                        cout<<ptr->roll<<"\t";
                        ptr = ptr->next;
                        }
                        cout<<"\n";
                        break;
            case 2 :    ptr = heads[0]->nextsame;
                        while(ptr!= heads[0]){
                        cout<<ptr->roll<<"\t";
                        ptr = ptr->nextsame;
                        }
                        cout<<"\n";
                        break;
            case 3 :    ptr = heads[1]->nextsame;
                        while(ptr != heads[1]){
                        cout<<ptr->roll<<"\t";
                        ptr = ptr->nextsame;
                        }
                        cout<<"\n";
                        break;
            default:    cout<<"\nhi";
        }
    }

};

int main(){
    lists l1;
    int ch ,r,i;
    char s;
    do{
        cout<<"\nenter the roll no.:";
        cin>>r;
        cout<<"\nenter the subject(y / m):";
        cin>>s;
        l1.insertion(r,s);
        cout<<"\nwant to add more(1/0):";
        cin>>ch;
    }while(ch == 1);

    do{
        cout<<"\nenter the list to be displayed:"
            <<"\n 1. full lists"
            <<"\n 2. yoga lists"
            <<"\n 3. music lists";
        cin>>i;
        l1.display(i);
        cout<<"\nwant any other lists(1/0):";
        cin>>ch;
    }while(ch == 1);
    system("pause");
    return 0;
}