#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class btreenode{
    int *keys;
    int t;//min degree
    btreenode **c;//child pointers
    bool leaf;//is leafnode or not
    int n;//no .of keys.
public:
    btreenode(int t , bool leaf){
        this->t = t;
        this->leaf = leaf;
        keys = new int [2*t -1];
        c = new btreenode* [2*t];
        n = 0;
    }

    void insertnotful(int item){
        int i = n-1;

        if(leaf == true){
            while(i >=0 && keys[i]>item){
                keys[i+1] = keys[i];
                i--;
            }
            keys[i+1] = item;
            n++;
        }
        else{
            while(i >= 0 && keys[i] > item){
                i--;
            }
            if(c[i+1]->n == 2*t-1){
                splitchild(i+1,c[i+1]);
                if(keys[i+1] < item)
                    i++;
            }
            c[i+1]->insertnotful(item);
        }
    }

    void splitchild(int i , btreenode * y){
        btreenode *newnode = new btreenode(y->t,y->leaf);
        newnode->n = t-1;

        for(int j = 0 ; j < t-1; j++){
            newnode->keys[j]=y->keys[j+t];
        }

        if(y->leaf == false){
            for(int j =0;j<t;j++)
                newnode->c[j]=y->c[j+t];
        }

        y->n = t-1;

        for(int j = n;j>=i+1;j--){
            c[j+1]=c[j];
        }
        c[i+1] = newnode;

        for(int j = n-1;j>=i;j--){
            keys[j+1] = keys[j];
        }

        keys[i] = y->keys[t-1];
        n++;
    }

    //for traversing in nodes(not in tree)
    void traverse(){
        int i;
        for(i = 0;i < n;i++){
            if(leaf == false){
                c[i]->traverse();
            }
            cout<<"\t"<<keys[i];
        }
        if(leaf == false){
            c[n+1]->traverse();
        }
    }

    btreenode* search(int item){
        int i = 0;
        while(i<n && item > keys[i])
            i++;
        if(item == keys[i]){
            return this;
        }
        if(leaf == true){
            return NULL;
        }
        return c[i]->search(item);
    }

    friend class btree;
};

class btree{
    btreenode* root;
    int t;//min degree
public:
    btree(int t){
        this->t = t;
        root = NULL;
    }

    void traverse(){
        if(root == NULL)
            return;
        root->traverse();
    }

    btreenode* search(int item){
        if(root ==NULL)
            return NULL;
        return root->search(item);
    }

    void insertion(int item){
        if(root == NULL){
            root = new btreenode(t,true);
            root->keys[0] = item;
            root->n = 1;
        }
        else{
            if(root->n == (2*t-1)){
                btreenode *newnode = new btreenode(t,false);
                newnode->c[0]=root;
                newnode->splitchild(0,root);
                int i = 0;
                if(newnode->keys[0] < item)
                    i++;
                newnode->c[i]->insertnotful(item);

                root = newnode;
            }
        

            else 
                root->insertnotful(item);
    
        }
    }

};

int main(){
    int i;
    btree b1(3);
    b1.insertion(8);
    b1.traverse();
    b1.insertion(7);
    b1.traverse();
    b1.insertion(1);
    b1.traverse();
    b1.insertion(6);
    b1.traverse();
    b1.insertion(2);
    b1.traverse();
    b1.insertion(4);
    b1.traverse();
    cin>>i;
    return 0;
}