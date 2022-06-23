#include<bits/stdc++.h>
using namespace std;

void toposort(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
	vis[node] = 1;
	for(auto neighbour : adj[node]){
		if(vis[neighbour.first]==0){
			toposort(neighbour.first,vis,adj,st);
		}
	}
	st.push(node);
}

void shortestPath(int n,int src,vector<int> adj[]){
	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			toposort(i,vis,adj,st);
		}
	}

	vector<int> dist(n,INT_MAX);
	dist[src] = 0;

	while(not st.empty()){
		int node = st.top();
		st.pop();

		// if the node has been reached previously
		if(dist[node]!=INT_MAX){
			for(auto neighbour : adj[node]){
				if(dist[node]+neighbour.second<dist[neighbour.first]){
					dist[neighbour.first] = dist[node]+neighbour.second;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
}