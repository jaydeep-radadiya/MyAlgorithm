#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	string name;
	list<string> nbrs;

	Node(string name) {
		this->name = name;
	}
};

class Graph {
	unordered_map<string, Node*> ump;

public:
	Graph(vector<string> &cities) {
		for (auto city : cities) {
			ump[city] = new Node(city);
		}
	}

	void add_edge(string u, string v, bool bidir = false) {
		ump[u]->nbrs.push_back(v);
		if (bidir) {
			ump[v]->nbrs.push_back(u);
		}
	}

	void print() {
		for (auto cityPair : ump) {
			string city = cityPair.first;
			Node *node = cityPair.second;
			cout << city << " --> ";
			for (auto nbr : node->nbrs) {
				cout << nbr << ", ";
			}
			cout << "\n";
		}
	}
};

int main() {
	vector<string> cities = {"delhi", "london", "paris", "new york"};
	Graph g(cities);
	g.add_edge("delhi", "london");
	g.add_edge("new york", "london");
	g.add_edge("delhi", "paris");
	g.add_edge("paris", "new york");
	g.print();
	return 0;
}