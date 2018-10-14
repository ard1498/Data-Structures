#include<iostream>
#include<queue>
#include<math.h>
#include<stack>
#include<vector>
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

class tree{
    node * root;
    vector<node*> a;
    stack<node*> path;
    int h ;
public:
    tree(){
        root = NULL;
        h = 0;
    }

    void insertion(){
        root = new node(8);
        root->leftnode = new node(7);
        root->rightnode = new node(9);
        root->leftnode->rightnode = new node(2);
        root->rightnode->rightnode = new node(6);
        root->rightnode->leftnode = new node(5);
        root->leftnode->rightnode->rightnode = new node(1);
        root->leftnode->leftnode = new node(3);
    }

    void height(){
        h = 0;
        queue<node*> q;
        node * ptr = root;
        q.push(ptr);
        if(root == NULL)
            return;
        int nodecount;

        while(!q.empty()){
            nodecount=q.size();
            for(int i =0;i<nodecount;i++){
                ptr = q.front();
                q.pop();
                if(ptr->leftnode!=NULL)
                    q.push(ptr->leftnode);
                if(ptr->rightnode!=NULL)
                    q.push(ptr->rightnode);
            }
            h++;
        }
        cout<<"\nheight is:"<<h;
        return;    
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
		int n = h, j;
		cout << "in print tree\n";

		for (int i = 0; i < h; i++) {

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
    
    bool findpath(node * ptr,int item){
        
        if(ptr==NULL)
            return false;
        if(ptr->data == item){
            path.push(ptr);
            return true;
        }
        else{
            path.push(ptr);
            if(findpath(ptr->leftnode,item)==true){
                return true;
            }   
            else if(findpath(ptr->rightnode,item)==true){
                return true;
            }
            else{
                path.pop();
                return false;
            }
        }
    }

    void finding(int item){
        bool t = findpath(root,item);
        if(t==true){
            while(!path.empty()){
                if(path.size()==1)
                    cout<<path.top()->data;
                else{
                    cout<<path.top()->data<<"<-";
                }
                path.pop();
            }
        }
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
        cout<<root->data;
    }

    void maxwidth(){
        int nodecount,width = 0;
        node * ptr = root;
        queue<node*> q;
        q.push(ptr);
        while(!q.empty()){
            nodecount = q.size();
            width = max(width,nodecount);
            for(int i =0;i<nodecount;i++){
                ptr = q.front();
                q.pop();
                if(ptr->leftnode!=NULL)
                    q.push(ptr->leftnode);
                if(ptr->rightnode!=NULL)
                    q.push(ptr->rightnode);
            }
        }
        cout<<"width is:"<<width;
        return;
    }

    void mirrorimage(const tree& t1){
        tree t2 = t1;
        nodeswap(t2.root);
        t2.printarr();
        return;
    }

    void nodeswap(node* root){
        if(root == NULL){
            return;
        }
        else{
            node * temp = root->leftnode;
            root->leftnode = root->rightnode;
            root->rightnode = temp;
            nodeswap(root->leftnode);
            nodeswap(root->rightnode);
        }
    }

};

int main(){
    tree t1;
    t1.insertion();
    t1.height();
    t1.printarr();
    t1.finding(5);
    //t1.calldeletion();
    //t1.height();
    //t1.printarr();
    t1.maxwidth();
    t1.mirrorimage(t1);
    system("pause");
    return 0 ;
}