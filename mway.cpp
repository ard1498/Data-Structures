//dispaly not working properly.......

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

struct mnode{
    vector<int> key;
    vector<mnode*> next;

    mnode(int m,int key){
        for(int i = 0;i<m;i++){
            this->next.push_back(NULL);
        }
        this->key.push_back(key);
    }
};


class mway{
    int m,h;
    mnode* root;
public:
    mway(int m){
        root = NULL;
        this->m = m;
    }

    mnode* insertion(int item,mnode* ptr){
        if(root == NULL){
            root = new mnode(m,item);
            return root;
        }
        if(ptr == NULL){
            ptr = new mnode(m,item);
            return ptr;
        }
        mnode* newmnode = new mnode(m,item);
        if(ptr->key.size() == m-1){
            for(int i =0 ;i< m-1;i++){
                if(item < ptr->key[i]){
                    ptr->next[i] = insertion(item,ptr->next[i]);
                    break;
                }   
                else if(item > ptr->key[m-2]){
                    ptr->next[m-1] = insertion(item,ptr->next[m-1]);
                    break;
                }
            }
        }
        else{        
            ptr->key.push_back(item);
            sort(ptr->key.begin(),ptr->key.end());
        }
        return ptr;
    }

    int findsuc(mnode* ptr){
        if(ptr->next[0]==NULL){
            return ptr->key[0];
        }
        else{
            return findsuc(ptr->next[0]);
        }
    }
    mnode* deletion(int item,mnode*ptr){
        if(root == NULL){
            cout<<"\nempty tree.";
            return root;
        }
        if(ptr == NULL){
            return ptr;
        }
    
        for(int i = 0 ; i < ptr->key.size() ; i++){
            if(ptr->key[i] == item){
                if(ptr->next[i+1] != NULL){
                    int suc = findsuc(ptr->next[i+1]);
                    ptr->key[i] = suc;
                    ptr->next[i+1] = deletion(suc,ptr->next[i+1]);
                    return ptr;
                }
                else{
                    if(i < ptr->key.size()-1){
                        for(int j = i;j < ptr->key.size()-1;j++){
                            ptr->key[j] = ptr->key[j+1];
                            ptr->next[j+1] = ptr->next[j+2];
                        }
                    }
                    ptr->key.pop_back();
                    ptr->next[ptr->key.size()] = NULL;
                    return ptr;
                }
            }    
        }
        if(item < ptr->key[0]){
            ptr->next[0] = deletion(item,ptr->next[0]);
            return ptr;
        }
        for(int i =0;i<ptr->next.size();i++){
            if(i != ptr->key.size()-1){
                if(item > ptr->key[i] && item < ptr->key[i+1]){
                    ptr->next[i+1] = deletion(item,ptr->next[i+1]);
                    return ptr;
                }
            }
            else{
                if(item > ptr->key[i]){
                    ptr->next[i+1] = deletion(item,ptr->next[i+1]);
                    return ptr;
                }
            }
        }
    }

    void caldeletion(int item){
        mnode * ptr = deletion(item,root);
        if(ptr == NULL){
            cout<<"\nitem not found";
            return;
        }
        else{
            cout<<"\nitem found and deleted.";
        }
        return;
    }

    void traversal(){
        queue<mnode*> q1;
        if(root == NULL){
            cout<<"\ntree is empty.";
            return;
        }
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            mnode * ptr = q1.front();
            q1.pop();
            if(ptr == NULL){
                cout<<"\n";
                continue;
            }
            for(int i =0;i<ptr->key.size();i++){
                cout<<ptr->key[i]<<"  ";
            }
            for(int i =0;i<ptr->key.size()+1;i++){
                q1.push(ptr->next[i]);
            }
        }
        return;
    }

    int height(){
        h = 0;
        queue<mnode*> q;
        mnode * ptr = root;
        q.push(ptr);
        if(root == NULL)
            return 0;
        int nodecount;
    
        while(!q.empty()){
            nodecount=q.size();
            for(int i =0;i<nodecount;i++){
                ptr = q.front();
                q.pop();
                for( int j = 0;j < ptr->next.size();j++){
                    if(ptr->next[j] != NULL)
                        q.push(ptr->next[j]);
                }
            }
            h++;
        }
        cout<<"\nheight is:"<<h;
        return h;    
    }
    
    vector<mnode*> a;
    void getlevel(mnode * ptr,int level){
        if (level == 0) {
			a.push_back(ptr);
		}
		else {
			if (ptr != NULL) {
                for(int i =0;i<m;i++){
				    getlevel(ptr->next[i], level - 1);
                }
			}
			else {
                for(int i =0;i<m;i++){
				    getlevel(NULL, level - 1);
                }
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
                    for( int b =0;b<m-1;b++)    
                        cout << " ";
                else
                    {
                        for( int b =0;b<a[y]->key.size();b++){
                            cout << a[y]->key[b];
                        }
                        if(a[y]->key.size() < m-1){
                            int si = a[y]->key.size()-1;
                            while(si <m-1){
                                cout<<" ";
                                si++;
                            }
                        }
                    }

				//for (j = 0; j < ms ; j++)
					cout << " ";
			}

            for (j = 0; j<gl-1; j++) {
				cout << "\n";

				for (int p = 0; p < ls - j; p++)
					cout << " ";
				for (int l = t; l < a.size(); l++) {
					if (a[l] != NULL) {
                        for(int b =0;b < m-1;b++){
                            if (a[l]->next[b] != NULL)
							    cout << "/";
						    else
							    cout << " ";
						    for (int p = 0; p < (2 * j + 1); p++)
							    cout << " ";
						    if (a[l]->next[b+1] != NULL)
							    cout << "\\";
						    else
                                cout << " ";
                            for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
                                cout << " ";
                            }
                        }
						
                    }
                    else {
                        for(int b =0;b<m-1;b++){
                            cout << " ";
	    					for (int p = 0; p < (2 * j + 1); p++)
		    					cout << " ";
			    			cout << " ";
                        }
                        for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
					    	cout << " ";
                        }
                    }
                }
            }
            cout<<"\n";
            t = a.size();
        }
        a.erase(a.begin(),a.end());
    }

    void calins(int item){
        insertion(item,root);
    }

    void caltra(){
        traversal();
    }
    
};

int main(){
    int i ;
    mway t1(5);
    t1.calins(50);
    t1.calins(60);
    t1.calins(80);
    t1.calins(30);
    t1.calins(35);
    t1.calins(58);
    t1.calins(59);
    t1.calins(63);
    t1.calins(70);
    t1.calins(73);
    t1.calins(96);
    t1.calins(52);
    t1.calins(54);
    t1.calins(61);
    t1.calins(62);
    t1.calins(57);
    t1.calins(55);
    t1.calins(56);
    t1.calins(53);

    t1.caltra();
    cout<<"\n";
    t1.height();
    cout<<"\n";
    t1.printarr();
    // t1.caldeletion(63);
    // t1.caltra();
    // t1.caldeletion(62);
    // t1.caltra();
    // t1.caldeletion(96);
    // t1.caltra();
    // t1.caldeletion(52);
    // t1.caltra();
    cin>>i;
    return 0;
}


