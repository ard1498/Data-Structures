#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

struct node{
    int data,bfact;
    node *left,*right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->bfact = 0;
    }
};

class avltree{
    node * root;
    vector<node*> a;
public:
    avltree(){
        root = NULL;
    }

    int height(node * ptr){
        if(ptr == NULL)
            return 0;
        return (1 + max(height(ptr->left),height(ptr->right)));
    }

    node* insertion(node* ptr,int item){
        if(root == NULL){
            root = new node(item);
            cout<<"\nitem inserted is:"<<root->data<<"\n";
            return root;
        }
        if(ptr == NULL){
            ptr = new node(item);
            cout<<"\nitem inserted is:"<<ptr->data<<"\n";
            return ptr;
        }
        if(item < ptr->data){
            ptr->left = insertion(ptr->left,item);
        }
        else{
            ptr->right = insertion(ptr->right,item);
        }

        ptr->bfact = height(ptr->left) - height(ptr->right);
        if(ptr->bfact < -1){
            ptr = leftrotate(ptr);
        }
        return ptr;
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
        int n = height(root), j;
        cout << "in print tree\n";
    
        for (int i = 0; i < height(root); i++) {
    
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
        a.erase(a.begin(),a.end());
    }
    
    node* leftrotate(node * ptr){
        node * ptrr = ptr->right;
        ptrr->left = ptr;
        ptr->right = NULL;
        return ptrr;
    }

    int calinsert(int item){
        root = insertion(root,item);
        return 1;
    }

    
};

int main(){
    int i;
    avltree a1;
    cout<<a1.calinsert(1);
    cout<<a1.calinsert(2);
    cout<<a1.calinsert(3);
    cout<<a1.calinsert(4);
    cout<<a1.calinsert(5);
    cout<<a1.calinsert(6);
    cout<<a1.calinsert(7);
    cout<<a1.calinsert(8);
    cout<<a1.calinsert(9);
    a1.printarr();
    cin>>i;
    return 0;
}