#include<bits/stdc++.h>

using namespace std;

struct node {
	int freq;
	string letter;
	node *left, *right;

	node(int f, string s) {
		this->freq = f;
		this->letter = s;
		this->left = NULL;
		this->right = NULL;
	}
};

class hcode {
	int h;
	vector<node*> n, a;
	vector<node*> heap;
	node* root;
public:

	hcode(vector<node*> &nodes) {
		this->root = NULL;
		this->n = nodes;
	}

	void genheap() {
		for (int i = 0; i < n.size(); i++) {
			heap.push_back(n[i]);
			heapifyup(heap.size() - 1);
		}
	}

	void insertion(node* n) {
		heap.push_back(n);
		heapifyup(heap.size() - 1);
	}

	void heapifyup(int index) {
		int i = (index - 1) / 2;
		if(i > -1) {
			if (heap[i]->freq > heap[index]->freq) {
				swap(heap[i], heap[index]);
				heapifyup(i);
			}
            else
                return;
		}
		return;
	}

    void codes(){
        for(int i =0;i<n.size();i++){
            vector<int> code;
            bool t = codegenerate(n[i]->letter,root,code);
            if( t == true){
                cout<<"\ncode for "<<n[i]->letter<<" is:";
                for(int i =code.size()-1;i>-1;i--)
                    cout<<code[i];
            }
            else{
                cout<<"\nthis letter is not present.";
            }
            cout<<"\n";
        }
        return;
    }

    bool codegenerate(string s,node* n,vector<int>&code){
        if(n != NULL){
        
            if(n->letter == s){
                return true;
            }
            else{
                if(codegenerate(s,n->left,code) == true){
                    code.push_back(1);
                }
                else if(codegenerate(s,n->right,code)){
                    code.push_back(0);
                }
                else{
                    return false;
                }
            }
        }
        else{
            return false;
        }
    }

	node* deletion() {
		if (heap.size() < 1) {
			return NULL;
		}

		node* temp = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		heapifydown(0);
		return temp;
	}

    void display() {
		for (int i = 0; i <heap.size(); i++) {
			cout << heap[i]->freq << "\t";
		}
		cout << "\n";
	}


	void heapifydown(int index) {
		int i = 2 * index + 1, j = 2 * index + 2, ptr = -1;
		if (i < heap.size())
			ptr = i;
		if (j < heap.size()) {
			if (heap[j]->freq < heap[i]->freq) {
				ptr = j;
			}
		}
        if(ptr != -1)
		    if (heap[ptr]->freq < heap[index]->freq) {
			    swap(heap[ptr], heap[index]);
			    heapifydown(ptr);
		    }
		return;
	}

	void hufftree() {
		node *n1, *n2;

		while (heap.size() != 1) {
			n1 = deletion();
			n2 = deletion();
			
			int f = n1->freq + n2->freq;
			string s = "$";
			node* rot = new node(f, s);
			rot->left = n1;
			rot->right = n2;
			insertion(rot);
		}

		root = heap[0];
		return;
	}

	void height() {
		h = 0;
		queue<node*> q;
		node * ptr = root;
		q.push(ptr);
		if (root == NULL)
			return;
		int nodecount;

		while (!q.empty()) {
			nodecount = q.size();
			for (int i = 0; i<nodecount; i++) {
				ptr = q.front();
				q.pop();
				if (ptr->left != NULL)
					q.push(ptr->left);
				if (ptr->right != NULL)
					q.push(ptr->right);
			}
			h++;
		}
		return;
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
					cout << a[y]->freq;

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

};

int main() {
	vector<node*> n;
	n.push_back(new node(22, "a"));
	n.push_back(new node(5, "b"));
	n.push_back(new node(11, "c"));
	n.push_back(new node(19, "d"));
	n.push_back(new node(2, "e"));
	n.push_back(new node(11, "f"));
    n.push_back(new node(25, "g"));
    n.push_back(new node(5, "h"));
	hcode h1(n);
	h1.genheap();
    cout<<"\n";
    h1.display();
	h1.hufftree();
	h1.height();
	cout << "\n";
    h1.printarr();
    cout<<"\n";
    h1.codes();
	system("pause");
	return 0;
}