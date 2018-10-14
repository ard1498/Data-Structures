#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>

using namespace std;

struct node;

struct edge{
    node* dest;
    edge* link;
    
    edge(node* n){
        this->dest = n;
        this->link = NULL;
    }
};

struct node{

    string nname;
    int state;
    node* next;
    edge* link;
    edge* start;
    
    node(string nname){
        this->nname = nname;
        this->state = 1;
        this->next = NULL;
        this->link = NULL;
        this->start = NULL;
    }

    void insertedge(node* dest){
        if(start == NULL){
            start = new edge(dest);
            this->link = start;
            return;
        }
        edge * newedge = new edge(dest);
        start->link = newedge;
        start = newedge;
        return;
    }

    edge* findedge(node* id){
        for(edge* i = this->link; i != NULL; i = i->link){
            if(i->dest == id){
                return i;
            }
        }
        return NULL;
    }

    void deleteedge(node* id){
        edge* eptr = findedge(id);
        if(eptr == NULL){
            cout<<"\nthis edge not exist.";
            return ;
        }

        if(this->link == eptr){
            this->link = this->link->link;
        }
        else{
            edge * i;
            for(i = this->link; i->link != eptr; i = i->link);
            i->link = i->link->link;
        }
        cout<<"\nedege deleted is:"<<eptr->dest->nname;
        delete eptr;
        return;
    }

    void displayedge(){
        for(edge* i = this->link;i != NULL;i=i->link){
            cout<<"\t"<<i->dest->nname;
        }
    }

};

class graph{
    
    node * start,*head;

public:
    
    graph(){
        start = NULL;  
        head = NULL;  
    }

    node* insertnode(string item){
        if(start == NULL){
            start = new node(item);
            head = start;
            return start;
        }
        node * newnode = new node(item);
        start->next = newnode;
        start = newnode;
        return start;
    }

    node* findnode(string id){
        for(node* i = head;i != NULL;i = i->next){
            if(i->nname == id){
                return i;
            }
        }
        return NULL;
    }

    void deletenode(string n){
        node* node1 = findnode(n);
        if( node1 == NULL){
            cout<<"\nnode not present .";
            return;
        }

        node* j;
        for( node * i = head;i != NULL ; i = i->next){
            if(i->next == node1){
                j = i;
            }
            i->deleteedge(node1);    
        }

        if(j == NULL)
            head = head->next;
        else
            j->next=j->next->next;

        cout<<"\nnode to be deleted:"<<node1->nname;
        delete node1;
    }

    void getedges(string n,vector<string> edges){
        node* k = findnode(n);
        if(k == NULL){
            cout<< "\n(in getedges)node is not present.";
            return;
        }
        for(int i = 0;i<edges.size();i++){
            node* node1 = findnode(edges[i]);
            if(node1 != NULL)
                k->insertedge(node1);
        }
    }

    void graphdisplay(){
        cout<<"\n";
        for( node* i = head; i != NULL; i = i->next){
            cout<<i->nname<<"->";
            i->displayedge();
            cout<<"\n";
        }
    }

    void calinsert(string n){
        node * start = insertnode(n);
        return;
    }

    void findmenode(string n){
        node* i = findnode(n);
        if( i == NULL){
            cout<<"\nnode not present";
            return;
        }
        cout<<"\nnode found";
        return;
    }

    void bfs(){
        queue<node*> q;
        q.push(head);
        cout<<"\n";
        while(!q.empty()){
            node* n = q.front();
            q.pop();
            for(edge* i = n->link;i != NULL;i=i->link){
                if(i->dest->state == 1){
                    i->dest->state = 2;
                    q.push(i->dest);
                }
            }
            cout<<n->nname<<"\t";
            n->state = 3;
        }
    }

    void dfs(){
        stack<node*> q;
        q.push(head);
        cout<<"\n";
        while(!q.empty()){
            node* n = q.top();
            q.pop();
            for(edge* i = n->link;i != NULL;i=i->link){
                if(i->dest->state == 1){
                    i->dest->state = 2;
                    q.push(i->dest);
                }
            }
            cout<<n->nname<<"\t";
            n->state = 3;
        }
    }

    int caloutdegree(string n){
        node * n1 = findnode(n);
        if(n1 != NULL){
            int outdeg = 0;
            for(edge* i = n1->link; i != NULL;i=i->link){
                outdeg++;
            }
            return outdeg;
        }
        return -1;
    }

    int calindegree(string n){
        node * n1 = findnode(n);
        if(n1 != NULL){
            int indeg = 0;
            for( node* i = head;i != NULL;i=i->next){
                for(edge* j = i->link; j != NULL; j=j->link ){
                    if(j->dest == n1){
                        indeg++;
                    }
                }
            }
            return indeg;
        }
        return -1;
    }

    void degree(){
        int ch, t;
        string n;
        do{
            cout<<"\n what do you want (1)indegree or (2)outdegree :";
            cin>>ch;
            
            switch(ch){
                case 1 :    cout<<"\nenter node:";
                            cin>>n;
                            t = calindegree(n);
                            if(t == -1){
                                cout<<"\nnode not present.";
                            }
                            else{
                                cout<<"indeg is:"<<t;
                            }
                            break;
                
                case 2 :    cout<<"\nenter node:";
                            cin>>n;
                            t = caloutdegree(n);
                            if(t == -1){
                                cout<<"\nnode not present.";
                            }
                            else{
                                cout<<"outdeg is:"<<t;
                            }
                            break;
                
                default : 
                            return;
            }
        }while(ch==1 || ch==2);
    }
};

int main(){
    graph g1;
    g1.calinsert("n1");
    g1.calinsert("n2");
    g1.calinsert("n3");
    g1.calinsert("n4");
    g1.calinsert("n5");

    g1.getedges("n1",{"n2","n3","n4"});
    g1.getedges("n2",{"n3"});
    g1.getedges("n4",{"n3","n5"});
    g1.getedges("n5",{"n3"});

    g1.graphdisplay();
    g1.dfs();
    g1.degree();

    g1.deletenode("n5");

    g1.graphdisplay();
    system("pause");
}