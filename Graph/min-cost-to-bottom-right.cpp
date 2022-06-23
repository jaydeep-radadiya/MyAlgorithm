#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int nextNode(int i, int j, int d, int r, int c) {
	if (d == 1) {
		// left
		j--;
	}
	else if (d == 2) {
		// right
		j++;
	}
	else if (d == 3) {
		// up
		i--;
	}
	else if (d == 4) {
		// down
		i++;
	}

	if (not (i >= 0 and j >= 0 and i < r and j < c)) {
		return -1;
	}
	else {
		return i * r + j;
	}
}

int zeroOneBFS(vector<pair<int, int>> *graph, int src, int dest, int r, int c) {
	vector<int> dist(r * c, INT_MAX);
	deque<int> dq;
	dist[src] = 0;
	dq.push_back(src);

	while (not dq.empty()) {
		int curr = dq.front();
		dq.pop_front();
		for (auto neighbour : graph[curr]) {
			if (dist[neighbour.ff] > dist[curr] + neighbour.ss) {
				dist[neighbour.ff] = dist[curr] + neighbour.ss;
				if (neighbour.ss == 0)
					dq.push_front(neighbour.ff);
				else
					dq.push_back(neighbour.ff);
			}
		}
	}
	return dist[dest];
}

int minCost(vector<vector<int>> &grid) {
	int r = grid.size();
	int c = grid[0].size();
	vector<pair<int, int>> graph[r * c];

	// go to all the cell
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int nodeVal = i * r + j;
			for (int d = 1; d <= 4; d++) {
				int next = nextNode(i, j, d, r, c);
				if (d == grid[i][j]) {
					graph[nodeVal].push_back(make_pair(next, 0));
				}
				else {
					graph[nodeVal].push_back(make_pair(next, 1));
				}
			}
		}
	}
	return zeroOneBFS(graph, 0, (r - 1) * r + c - 1, r, c);
}

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			grid[i][j] = x;
		}
	}

	cout << minCost(grid);

	return 0;
}