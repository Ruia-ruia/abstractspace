#include "headers/spacetypes.h"
/* Implementation of Space Types */

/* Globals */
ostream& operator << (ostream& out, const Node* n) {
	set<string> n_data = n->get_data();

	out << "Record\t\tEntry\n";
	out << "------\t\t-----\n";

	int i = 0;
	for (auto search : n_data) {
		out << i << "\t\t" << search << endl;
		i++;
	}

	return out;
}

bool operator == (Node &n, Node &m) {
	if (n.get_data() == m.get_data()) {
		return true;
	}

	return false;
}

//fix this later - should be more precise about equivalence
bool operator == (Graph &g, Graph &h) {
	if (&g == &h) return true;

	return false;
}

/* Node */
set<string> Node::get_data() const {
	return data;
}

Status Node::set_data(string d) {
	Status stat("Node::set_data(T d)");

	data.insert(d);
	stat.note("Added new data to Node");
	stat.no(0);

	return stat;
}

/* Graph */

/* Return reference to vector of neighbouring Nodes given Node n */

vector<Node*>& Graph::get_edges(Node* n) {
	auto iter = edges.find(n);

	if (iter != edges.end()) {
		return iter->second;
	}
}


bool Graph::check_edge(Node* n, Node* m) {
	auto tmp_n = get_edges(n);
	auto tmp_m = get_edges(m);

	for (auto search : tmp_n) {
		if (search == m) return true;
	}

	for (auto search : tmp_m) {
		if (search == n) return true;
	}

	return false;
}

Status Graph::set_edge(Node* n, Node* m) {
	Status stat("Graph::set_edge(Node& n, Node& m)");

	if (check_edge(n, m)) {
		stat.note("Already adjacent");
		stat.no(1);
		return stat;
	}

	auto iter_n = edges.find(n);
	auto iter_m = edges.find(m);

	if (iter_n != edges.end()) {
		vector<Node*>& n_adj = iter_n->second;
		n_adj.push_back(m);

		stat.note("Node n is not new to Graph");
	} else {
		vector<Node*> new_edge;
		new_edge.push_back(m);
		edges.insert(pair<Node*, vector<Node*> >(n, new_edge));

		stat.note("Node n is new to Graph");
	}

	if (iter_m != edges.end()) {
		vector<Node*>& m_adj = iter_m->second;
		m_adj.push_back(n);

		stat.note("Node m is not new to Graph");
	} else {
		vector<Node*> new_edge;
		new_edge.push_back(n);
		edges.insert(pair<Node*, vector<Node*> >(m, new_edge));

		stat.note("Node m is new to Graph");
	}

	stat.no(0);
	return stat;
}


/* Space */

//Return a vector of Graphs which are linked to given Graph g
vector<Graph*>& Space::get_links(Graph* g) {
	auto iter = links.find(g);

	if (iter != links.end())
		return iter->second;

}

bool Space::check_link(Graph* g, Graph* h) {
	auto tmp_g = get_links(g);
	auto tmp_h = get_links(h);

	for (auto search : tmp_g) {
		if (search == h) return true;
	}

	for (auto search : tmp_h) {
		if (search == g) return true;
	}

	return false;
}

//Attempt search for Graphs g and h in links map and link them
Status Space::set_link(Graph* g, Graph* h) {
	Status stat("Space::set_link(Graph& g, Graph& h)");

	if (check_link(g, h)) {
		stat.note("Already linked");
		stat.no(1);
		return stat;
	}

	auto iter_g = links.find(h);
	auto iter_h = links.find(g);

	if (iter_g != links.end()) {
		vector<Graph*> g_linked = iter_g->second;
		g_linked.push_back(h);

		stat.note("Graph g is not new to Space");
	} else {
		vector<Graph*> new_link;
		new_link.push_back(h);
		links.insert(pair<Graph*, vector<Graph*> >(g, new_link));

		stat.note("Graph g is new to Space");
	}

	if (iter_h != links.end()) {
		vector<Graph*> h_linked = iter_h->second;
		h_linked.push_back(g);

		stat.note("Graph h is not new to Space");
	} else {
		vector<Graph*> new_link;
		new_link.push_back(g);
		links.insert(pair<Graph*, vector<Graph*> >(h, new_link));

		stat.note("Graph h is new to Space");
	}

	stat.no(0);
	return stat;
}
