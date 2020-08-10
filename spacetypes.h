/* Declarations for Space Types */
/* Declared in order of abstraction */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include "status.h"
using namespace std;


/* Class declaration for a Node which embeds data of type T */
class Node {
public:
	//ctors, dtors
	Node(string d) { this->data.insert(d); }

	//operators
	friend ostream& operator<< (ostream& out, const Node* n);
	friend bool operator== (Node &n, Node &m);

	//getters
	set<string> get_data() const;

	//setters
	Status set_data(string d);
	Status clear_data();

private:
	set<string> data;
};

/* Class declaration for a Graph which embeds Nodes */
class Graph {
public:

	//operators
	friend bool operator== (Graph &n, Graph &m);

	//checkers
	bool check_edge(Node* n, Node* m);

	//getters
	vector<Node*>& get_edges(Node* n);

	//setters
	Status set_edge(Node* n, Node* m);

private:
	map<Node*, vector<Node*> > edges;
};


/* Class declaration for a Space which embeds Graphs */
class Space {
public:

	//ctors, dtors
	Space();
	~Space();

	//checkers
	bool check_link(Graph* g, Graph* h);

	//getters
	vector<Graph*>& get_links(Graph* g);

	//setters
	Status set_link(Graph* g, Graph* h);

private:
	map<Graph*, vector<Graph*> >  links;
};
