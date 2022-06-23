#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

bool checkForCycle(vector<list<int>> &graph,int curr,vi &visited,vi &dfsVisited){
	visited[curr] = 1;
	dfsVisited[curr] = 1;
	for(int neighbour : graph[curr]){
		if(not visited[neighbour]){
			if(checkForCycle(graph,neighbour,visited,dfsVisited)){
				return true;
			}
		}
		else if(dfsVisited[neighbour]){
			return true;
		}
	}
	dfsVisited[curr] = 0;
	return false;
}

bool isCycle(vector<list<int>> &graph){
	int n = graph.size();
	vi visited(n,0);
	vi dfsVisited(n,0);

	for(int i=1;i<n;i++){
		if(not visited[i]){
			if(checkForCycle(graph,i,visited,dfsVisited)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<list<int>> graph(n+1);

	while(e--){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v); // directed graph
	}

	cout<<isCycle(graph);

	return 0;
}