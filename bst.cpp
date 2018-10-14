#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct node {
	int data;
	node* leftnode;
	node* rightnode;

	node(int data) {
		this->data = data;
		this->leftnode = NULL;
		this->rightnode = NULL;
	}
};

class tree {
	vector<node *> a;
	node * current, *root;

public:
	tree() {
		current = NULL;
		root = NULL;
	}

	int insertion(int item) {
		if (root == NULL) {
			root = new node(item);
			return 1;
		}
		node *newnode = new node(item);
		node *n1 = findloc(item, root);
		if (n1->data<item)
			n1->rightnode = newnode;
		else
			n1->leftnode = newnode;
		return 1;
	}

	node *findloc(int item, node *node1) {
		if (item < node1->data) {
			if (node1->leftnode != NULL)
				return findloc(item, node1->leftnode);
			else
				return node1;
		}
		else {
			if (node1->rightnode != NULL)
				return findloc(item, node1->rightnode);
			else
				return node1;

		}
	}

	void inorder(node * node1) {
		if (node1 == NULL)
			return;
		inorder(node1->leftnode);
		cout<<node1->data<<"\t";
		inorder(node1->rightnode);
		return;
	}

	void preorder(node * node1) {
		if (node1 == NULL)
			return;
		cout << node1->data << "\t";
		//q3.push(node1->data);
		preorder(node1->leftnode);
		preorder(node1->rightnode);
		return;
	}

	void postorder(node * node1) {
		if (node1 == NULL)
			return;
		postorder(node1->leftnode);
		postorder(node1->rightnode);
		cout << node1->data << "\t";
		return;
	}

	void display() {
		cout << "\n--------INORDER--------\n";
		inorder(root);
		cout << "\n-----------POSTORDER-----\n";
		postorder(root);
		cout << "\n--------PREORDER-------\n";
		preorder(root);
		return;
	}


	int calheight(node * ptr) {
		int k, j;
		if (ptr == NULL)
			return 0;

		return (1+max(calheight(ptr->leftnode),calheight(ptr->rightnode)));
		/*
		if (k >= j) {
			return k + 1;
		}
		else
			return j + 1;
		*/
	}

	void height() {
		cout << calheight(root);
	}

	void getlevel(node * ptr, int t) {
		if (t == 0) {
			a.push_back(ptr);
		}
		else {
			if (ptr != NULL) {
				getlevel(ptr->leftnode, t - 1);
				getlevel(ptr->rightnode, t - 1);
			}
			else {
				getlevel(NULL, t - 1);
				getlevel(NULL, t - 1);
			}
		}
	}

	void printarr() {
		int k = 0, gl, ls, ms, t = 0;
		int n = calheight(root), j;
		cout << "in print tree\n";

		for (int i = 0; i < calheight(root); i++) {

			ls = pow(2, n - i) - 1;
			ms = pow(2, n - i + 1) - 1;
			gl = pow(2, max(0, n - i - 1));

			for (j = 0; j < ls; j++)
				cout << " ";

			getlevel(root, i);

			for (int y = t; y < a.size(); y++) {
				if (a[y] == NULL)
					cout << " ";
				else
					cout << a[y]->data;

				for (j = 0; j < ms ; j++)
					cout << " ";
			}

			for (j = 0; j<gl-1; j++) {
				cout << "\n";

				for (int p = 0; p < ls - j; p++)
					cout << " ";
				for (int l = t; l < a.size(); l++) {
					if (a[l] != NULL) {
						if (a[l]->leftnode != NULL)
							cout << "/";
						else
							cout << " ";
						for (int p = 0; p < (2 * j + 1); p++)
							cout << " ";
						if (a[l]->rightnode != NULL)
							cout << "\\";
						else
							cout << " ";
						for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
							cout << " ";
						}
					}
					else {
						cout << " ";
						for (int p = 0; p < (2 * j + 1); p++)
							cout << " ";
						cout << " ";
						for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
							cout << " ";
						}
					}
				}
			}
			cout << "\n";
			t = a.size();
		}
		a.erase(a.begin(),a.end());
	}

	int c=0;
	void getlevel2(node * ptr,int level){
        if(level==0){
            if(ptr!=NULL)
                c++;
        }
        else{
            if(ptr!=NULL){
                getlevel2(ptr->leftnode,level-1);
                getlevel2(ptr->rightnode,level-1);
            }
        }
    }

	void getwidth(){
        int ct;
        for(int i =0;i<calheight(root);i++){
            getlevel2(root,i);
            if(i!=0){
                if(c>=ct){
                    ct=c;
                }
            }
            else{
                ct=c;
            }
            c=0;
        }

        cout<<"\nwidth of the tree is:"<<ct;
        return;
	}

	void deletion(node * ptr,node * save){
        if(ptr->leftnode==NULL && ptr->rightnode==NULL){
            cout<<"\nnode to be deleted is:"<<ptr->data;
            if(save->leftnode==ptr)
                save->leftnode=NULL;
            else
                save->rightnode=NULL;
            delete ptr;
            return;
        }
        else{
            if(ptr->leftnode!=NULL)
                deletion(ptr->leftnode,ptr);
            if(ptr->rightnode!=NULL)
                deletion(ptr->rightnode,ptr);
        }
    }

    void calldeletion(){
        deletion(root,NULL);
    }

	//deletion working perfectly......

	node* findsuc(node * ptr){
		if(ptr->leftnode!=NULL){
			ptr = ptr->leftnode;
			findsuc(ptr);
		}
		return ptr;
	}
	
	void deletenode(node * ptr,node * save,int item){
		if(root == NULL){
			cout<<"\ntree is empty.";
			return;
		}
		
		if(ptr!=NULL){

			if(item > ptr->data){
				deletenode(ptr->rightnode,ptr,item);
			}
			else if( item < ptr->data){
				deletenode(ptr->leftnode,ptr,item);
			}
			else if(item == ptr->data){
				if(ptr->leftnode == NULL && ptr->rightnode!=NULL){
					cout<<"\n in first..";
					if(save->leftnode == ptr){
						save->leftnode = ptr->rightnode;
					}
					else{
						save->rightnode = ptr->rightnode;
					}
				}
				else if(ptr->rightnode == NULL && ptr->leftnode!=NULL){
					cout<<"\n in second if..";
					if(save->leftnode == ptr)
						save->leftnode = ptr->leftnode;
					else
						save->rightnode = ptr->leftnode;
				}
				else if(ptr->rightnode !=NULL && ptr->leftnode!=NULL){
					cout<<"\n in third if..";
					node * ptr1 = findsuc(ptr->rightnode);
					ptr->data = ptr1->data;
					cout<<"\n ptr->data:"<<ptr->data;
					deletenode(ptr->rightnode,ptr,ptr1->data);
				}
				else {
					cout<<"\n in else..";
					if(save->leftnode == ptr){
						save->leftnode = NULL;
					}
					else{
						save->rightnode = NULL;
					}
					delete ptr;
				}
			
			}
		}
		else{
			cout<<"\nitem not found/";
			return;
		}
		return;
	}
	
	void calldeletenode(int item){
		deletenode(root,NULL,item);
	}


    void getroot(){
        cout<<root->data;
        cout<<root->leftnode->data;
        cout<<root->rightnode->data;
    }

};

int main() {
	int i;
	tree t1;
	
	cout << t1.insertion(50);
	cout << t1.insertion(30);
	cout << t1.insertion(70);
	cout << t1.insertion(20);
	cout << t1.insertion(60);
	cout << t1.insertion(40);
	cout << t1.insertion(80);
	cout << t1.insertion(10);
	cout << t1.insertion(25);
	cout << t1.insertion(90);
	cout << t1.insertion(05);
	cout << t1.insertion(15);
	cout << t1.insertion(28);
	cout << t1.insertion(88);
	cout << t1.insertion(100);
	cout << "\n";
	t1.height();
	cout << "\n";
	t1.printarr();
	cout << "\n";
	t1.getwidth();
	cout<<"\n";
	//t1.calldeletion();
	cout<<"\n";
	t1.height();
	cout<<"\n";
	t1.printarr();
	//t1.getroot();
	
	t1.calldeletenode(50);
	cout<<"\n";
	t1.printarr();
	cout<<"\n";
	cin >> i;
	return 0;
}
