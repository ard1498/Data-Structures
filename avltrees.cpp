#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	int bfact;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->bfact = 0;
	}
};

class avltree{
	int h;
	vector<node*> a;
	node * root;
public:
	avltree(){
		root = NULL;
		h = 0;
	}

	int height(node * ptr) {
		if (ptr == NULL)
			return 0;

		else
			return (1 + max(height(ptr->left), height(ptr->right)));
	}

	void getlevel(node * ptr, int t) {
		if (t == 0) {
			a.push_back(ptr);
		}
		else {
			if (ptr != NULL) {
				getlevel(ptr->left, t - 1);
				getlevel(ptr->right, t - 1);
			}
			else {
				getlevel(NULL, t - 1);
				getlevel(NULL, t - 1);
			}
		}
	}

	void printarr() {
		h = height(root);
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

				for (j = 0; j < ms; j++)
					cout << " ";
			}

			for (j = 0; j<gl - 1; j++) {
				cout << "\n";

				for (int p = 0; p < ls - j; p++)
					cout << " ";
				for (int l = t; l < a.size(); l++) {
					if (a[l] != NULL) {
						if (a[l]->left != NULL)
							cout << "/";
						else
							cout << " ";
						for (int p = 0; p < (2 * j + 1); p++)
							cout << " ";
						if (a[l]->right != NULL)
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
		a.erase(a.begin(), a.end());
	}

	node * balance(node * subroot,int item){
		subroot->bfact = height(subroot->left)-height(subroot->right);
		if(subroot->bfact > 1){
			if(item < subroot->left->data){
				subroot = rightrotate(subroot);
			}
			else{
				subroot->left = leftrotate(subroot->left);
				subroot = rightrotate(subroot);
			}
		}
		else if(subroot->bfact < -1){
			if(item > subroot->right->data){
				subroot = leftrotate(subroot);
			}
			else{
				subroot->right = rightrotate(subroot->right);
				subroot = leftrotate(subroot);
			}
		}
		else{
			return subroot;
		}
		return subroot;
	}

	node * leftrotate(node * subroot){
		node * ptr = subroot->right;
		node * y = ptr->left;
//		ptr->left = subroot;
		subroot->right = ptr->left;
		ptr->left = subroot;
		return ptr;
	}

	node * rightrotate(node * subroot){
		node * ptr = subroot->left;
		node * y = ptr->right;
	//	ptr->right = subroot;
		subroot->left = ptr->right;
		ptr->right = subroot;
		return ptr;
	}
	
	void callinsertion(int item){
		node * ptr = insertion(item,root);
	}

	node * insertion(int item , node * root){
		node * newnode = new node(item);
		if(root == NULL){
			root = newnode;
			return root;
		}
		if(item < root->data){
			root->left = insertion(item,root->left);
		}
		else if(item > root->data){
			root->right = insertion(item,root->right);
		}
		else{
			cout<<"\nduplicates not possible.";
			return root;
		}		
		root = balance(root,item);
		return root;
	}

	node* findsuc(node * ptr){
		if(ptr->left!=NULL){
			ptr = ptr->left;
			findsuc(ptr);
		}
		return ptr;
	}
	

	node * deletenode(node * ptr,int item){
		if(root == NULL){
			cout<<"\ntree is empty.";
			return root;
		}
		if(ptr == NULL){
			cout<<"\nelement not found";
			return ptr;
		}
		if(item > ptr->data){
			ptr->right = deletenode(ptr->right,item);
		}
		else if( item < ptr->data){
			ptr->left = deletenode(ptr->left,item);
		}
		else {
			if(ptr->left == NULL || ptr->right==NULL){
				node * temp = ptr->left ? ptr->left : ptr->right;
				if(temp == NULL){
					temp = ptr;
					ptr = NULL;
				}
				else
					*ptr = *temp;
				delete temp;
			}
				
			else /*if(ptr->right !=NULL && ptr->left!=NULL)*/{
				node * ptr1 = findsuc(ptr->right);
				ptr->data = ptr1->data;
				ptr->right = deletenode(ptr->right,ptr1->data);
			}
		}	
		
		if(root == NULL){
			return root;
		}

		if(ptr == NULL){
			return ptr;
		}

		ptr->bfact = height(ptr->left)-height(ptr->right);
		cout<<"\nsave->bfact:"<<ptr->bfact;
			if(ptr->bfact > 1){
				node * ptr2 = ptr->left;
				ptr2->bfact = height(ptr2->left)-height(ptr2->right);
				if(ptr2->bfact >= 0){
					ptr = rightrotate(ptr);
				}
				else{
					ptr->left = leftrotate(ptr->left);
					ptr = rightrotate(ptr);
				}
			}
			else if(ptr->bfact < -1){
				node * ptr2 = ptr->right;
				cout << "\nin -1";
				ptr2->bfact = height(ptr2->left)-height(ptr2->right);
				if(ptr2->bfact <= 0){
					ptr = leftrotate(ptr);
				}
				else{
					ptr->right = rightrotate(ptr->right);
					ptr = leftrotate(ptr);
				}				
			}
		return ptr;
	}

	void calldeletenode(int item){
		root = deletenode(root,item);
	}

};

int main() {
	int i;  
	avltree a1;
//	a1.callinsertion();
	
	a1.callinsertion(20);
	a1.callinsertion(30);
	a1.callinsertion(40);
	a1.printarr();
	//cout << a1.callinsertion(20);
	a1.callinsertion(10);
	a1.printarr();
	//cout << a1.callinsertion(40);
	a1.callinsertion(9);
	a1.printarr();
	a1.callinsertion(8);
	a1.printarr();
	//a1.callinsertion(50);
	a1.printarr();
	a1.callinsertion(90);
	a1.printarr();
	a1.callinsertion(35);
	a1.printarr();
	a1.callinsertion(55);
	a1.printarr();
	a1.callinsertion(60);
	a1.printarr();
	a1.callinsertion(66);
	// a1.callinsertion(100);
	//a1.height();
	//a1.callassignheight();
	//a1.checktree();
	a1.printarr();
	a1.calldeletenode(55);
	a1.printarr();
	//a1.calunbal();
	cin>>i;
	return 0;
}