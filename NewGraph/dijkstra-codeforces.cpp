#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

int main(){
	int n,e;
	cin>>n>>e;
	vector<int> indegree(n+1);
	indegree[1]++;
	vector<pair<int,int>> adj[n+1];
	for(int i=0;i<e;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		indegree[v]++;
		adj[u].push_back({v,wt});
	}

	for(int i=1;i<n+1;i++){
		if(e<n-1 and indegree[i]==0){
			cout<<-1<<"\n";
			return 0;
		}
	}

	priority_queue<pii,vector<pii>,greater<pii>> minh;
	minh.push({0,1});
	vector<int> dist(n+1,INT_MAX);
	dist[1] = 0;
	vector<int> parent(n+1,0);
	parent[1] = -1;


	while(not minh.empty()){
		int d = minh.top().first;
		int node = minh.top().second;
		minh.pop();

		for(auto nbr : adj[node]){
			int wt = nbr.second;
			int neighbour = nbr.first;
			if(d+wt<dist[neighbour]){
				minh.push({d+wt,neighbour});
				dist[neighbour] = d+wt;
				parent[neighbour] = node;
			}
		}
	}
	
	int x = n;
	vector<int> path;
	path.push_back(x);
	while(parent[x]!=-1){
		x = parent[x];
		path.push_back(x);
	}
	reverse(path.begin(),path.end());
	for(int ele : path){
		cout<<ele<<" ";
	}

	return 0;
}