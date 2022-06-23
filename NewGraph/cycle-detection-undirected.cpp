#include<bits/stdc++.h>
using namespace std;

bool bfsCycleChecked(int node,int par,vector<int> &vis,vector<int> adj[]){
	queue<pair<int,int>> q; // store (node,parent)
	q.push({node,par});
	vis[node] = 1;

	while(not q.empty()){
		int curr = q.front().first;
		int par = q.front().second;
		q.pop();

		for(int neighbour : adj[curr]){
			if(vis[neighbour]==0){
				q.push({neighbour,curr});
				vis[neighbour] = 1;
			}
			else if(vis[neighbour]==1 && neighbour!=par){
				return true;
			}
		}
	}
	return false;
}

// cycle detection using bfs in undirected graph
bool isCycle(int n,vector<int> adj[]){
	vector<int> vis(n);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			if(bfsCycleChecked(i,-1,vis,adj)==true){
				return true;
			}
		}
	}
	return false;
}

/*
// cycle detection using dfs in undirected graph
bool dfsCycleChecked(int node,int par,vector<int> &vis,vector<int> adj[]){
	vis[node] = 1;
	for(int neighbour : adj[node]){
		if(vis[neighbour]==false){
			if(dfsCycleChecked(neighbour,node,vis,adj)==true){
				return true;
			}
		}
		else if(vis[neighbour]==true && neighbour!=par){
			return true;
		}
	}
	return false;
}

bool isCycle(int n,vector<int> adj[]){
	vector<int> vis(n);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			if(dfsCycleChecked(i,-1,vis,adj)==true){
				return true;
			}
		}
	}
	return false;
}
*/

int main(){

	return 0;
}