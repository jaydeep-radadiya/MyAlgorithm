#include<bits/stdc++.h>
using namespace std;

void shortestPath(int n,int src,vector<int> adj[]){
	vector<int> dist(n,INT_MAX);
	queue<int> q;
	dist[src] = 0;
	q.push(src);

	while(not q.empty()){
		int node = q.front();
		int d = dist[node]; // shortest distance to reach node from src
		q.pop();

		for(int neighbour : adj[node]){
			if(d+1<dist[neighbour]){
				dist[neighbour] = d+1;
				q.push(neighbour);
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
}