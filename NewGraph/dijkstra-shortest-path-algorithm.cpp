#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

void dijkstra(int src){
	priority_queue<pii,vector<pii>,greater<pii>> minh;
	vector<int> dist(n,INT_MAX);
	dist[src] = 0;
	minh.push({0,src});

	while(not minh.empty()){
		int d = minh.top().first;
		int node = minh.top().second;
		minh.pop();

		for(auto nbr : adj[node]){
			// please confirm below 2 lines
			int wt = nbr.first;
			int neighbour = nbr.second;

			if(d+wt<dist[neighbour]){
				minh.push({d+wt,neighbour});
				dist[neighbour] = d+wt;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
}

int main(){

	return 0;
}