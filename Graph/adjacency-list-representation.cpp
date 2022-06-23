#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	int n; // # nodes
	list<int> *adj; // make array of list type
	Graph(int val) {
		this->n = val;
		this->adj = new list<int>[this->n];
	}

	void add_edge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			cout << i << " --> ";
			for (int ele : adj[i]) {
				cout << ele << ", ";
			}
			cout << "\n";
		}
	}
};

int main() {
	Graph g(6);
	g.add_edge(0, 1);
	g.add_edge(0, 4);
	g.add_edge(2, 1);
	g.add_edge(3, 4);
	g.add_edge(4, 5);
	g.add_edge(2, 3);
	g.add_edge(3, 5);
	g.print();
	return 0;
}