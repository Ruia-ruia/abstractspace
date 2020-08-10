#include <iostream>
#include <map>
#include <vector>

#include "headers/spacetypes.h"

using namespace std;

int main() {

	Node *n1 = new Node("AKAC");
	Node *n2 = new Node("Everlyn Russ");
	Node *n3 = new Node("ITAC");

	Graph *g1 = new Graph();
	g1->set_edge(n1, n3);
	g1->set_edge(n1, n2);

	for (auto output : g1->get_edges(n1)) {
		cout << output << endl;
	}
}
