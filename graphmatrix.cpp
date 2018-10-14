#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class graphs{
    int no_of_nodes;
    vector<vector<int>> adjac;
    vector<vector<int>> path;
    vector<vector<int>> weights;
    vector<vector<int>> shortpath;
public:
    graphs(int no_of_nodes){
        this->no_of_nodes = no_of_nodes;
        adjac.resize(no_of_nodes,vector<int>(no_of_nodes));
        path.resize(no_of_nodes,vector<int>(no_of_nodes));
        weights.resize(no_of_nodes,vector<int>(no_of_nodes));
        shortpath.resize(no_of_nodes,vector<int>(no_of_nodes));
    }

    bool inrange(int t){
        if(t<no_of_nodes && t>-1)
            return true;
        else 
            return false;
    }

    void getpaths(int r,int c,int weight){
        if( inrange(r) && inrange(c)){
            if(adjac[r][c]!=1){
                adjac[r][c] = 1;
                weights[r][c] = weight;
            }
            else
                cout<<"\nalready exists.";
        }
        else{
            int m = inrange(r)? c : r;
            cout<<"\nnode-"<<m<<" not present..";
        }
    }

    void generatepathmatrix(){
        path = adjac;
        for(int k = 0;k < no_of_nodes;k++){
            for(int i = 0;i < no_of_nodes;i++){
                for(int j = 0;j < no_of_nodes;j++){
                    path[i][j]=((path[i][j])| (path[i][k] & path[k][j]) );
                }
            }
        }

        cout<<"\n-------PATH MTRIX---------";
        displaymatrix(path);
    }

    void shortestpath(){
        for(int i = 0;i < no_of_nodes;i++){
            for(int j = 0;j < no_of_nodes;j++){
                if(weights[i][j]!=0){
                    shortpath[i][j] = weights[i][j];
                }
                else{
                    shortpath[i][j] = INT_MAX/(no_of_nodes);
                }
            }
        }       

        for(int k = 0;k < no_of_nodes;k++){
            for(int i = 0;i < no_of_nodes;i++){
                for(int j = 0;j < no_of_nodes;j++){
                    shortpath[i][j] = min((shortpath[i][j]),(shortpath[i][k] + shortpath[k][j]) );
                }
            }
        }

        cout<<"\n--------------weights matrix-----------";
        displaymatrix(weights);
        cout<<"\n----------shortest path matrix---------";
        displaymatrix(shortpath);
        return;
    }


    void displaymatrix(vector<vector<int>> adjac){
        cout<<"\n";
        for(int i = 0 ;i < no_of_nodes;i++){
            for(int j = 0;j < no_of_nodes;j++){
                cout<<adjac[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }

    void display(){
        displaymatrix(adjac);
    }
};

int main(){
    graphs g1(4);
    g1.getpaths(0,0,7);
    g1.getpaths(1,0,7);
    g1.getpaths(3,0,4);
    g1.getpaths(0,1,5);
    g1.getpaths(2,1,3);
    g1.getpaths(3,2,1);
    g1.getpaths(1,3,2);
    g1.display();
    cout<<"\n"<<INT_MAX<<"\n";
    g1.generatepathmatrix();
    g1.shortestpath();
    system("pause");
    return 0;
}