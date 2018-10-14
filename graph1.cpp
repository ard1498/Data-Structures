#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node;

class edge
{
private:
	int weight;
	node* destination, *origin;
public:
	edge(node* org, node* dest, int wt)
	{
		destination = dest;
		origin = org;
		weight = wt;
	}
	node* getorig() { return origin; }
	node* getdest() { return destination; }
	int getwt() { return weight; }
};

class node
{
	//int data;
	string id;
	vector<edge*> adj;
public:
	node(string name)
	{
		id = name;
	}
	void addedge(node* dest, int wt)
	{
		edge *n = new edge(this, dest, wt);
		adj.push_back(n);
	}
	void printedge()
	{
		cout << id << ":" << endl;
		for (int i = 0; i < adj.size(); i++)
		{
			edge *e = adj[i];
			cout << e->getdest()->getname() << "-" << e->getwt() << endl;
		}
	}
	string getname() { return id; }
};

class graph
{
	vector<node*> nodes;
public:
	//edge* findedge(node*,node*,node*);
	void insnode(node* v)
	{
		// node *n = new node(id);
		nodes.push_back(v);
	}
	void printgraph()
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			nodes[i]->printedge();
			cout << endl;
		}
	}

	// void deledge();
	//void node();
};

int main()
{
	graph g;
	node *n1 = new node("A");
	node *n2 = new node("B");
	node *n3 = new node("C");
	node *n4 = new node("D");
	node *n5 = new node("E");
	node *n6 = new node("F");
	node *n7 = new node("G");
	node *n8 = new node("H");

	n1->addedge(n2, 50);
	n1->addedge(n3, 10);
	n1->addedge(n5, 60);
	n2->addedge(n4, 20);
	n2->addedge(n3, 40);
	n3->addedge(n6, 70);
	n4->addedge(n2, 40);
	n4->addedge(n7, 0);
	n5->addedge(n8, 50);
	n6->addedge(n1, 30);
	n6->addedge(n3, 60);
	n7->addedge(n8, 30);
	n7->addedge(n5, 20);
	n8->addedge(n2, 10);
	n8->addedge(n1, 90);

	g.insnode(n1);
	g.insnode(n2);
	g.insnode(n3);
	g.insnode(n4);
	g.insnode(n5);
	g.insnode(n6);
	g.insnode(n7);
	g.insnode(n8);

	g.printgraph();

	system("pause");
	return 0;

}