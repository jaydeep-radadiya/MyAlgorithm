#include<bits/stdc++.h>
using namespace std;
// tc : O(n^2)

int main(){
	int n,e;
	cin>>n>>e;
	vector<pair<int,int>> adj[n];
	for(int i=0;i<e;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}

	vector<int> key(n,INT_MAX);
	vector<bool> mstSet(n,false);
	vector<int> parent(n,-1);
	key[0] = 0;

	// we have (n-1) edges in MST so we iterate (n-1) times
	for(int cnt=1;cnt<n;cnt++){
		int min_key = INT_MAX;
		int u;

		for(int v=0;v<n;v++){
			if(mstSet[v]==false and key[v]<min_key){
				u = v;
				min_key = key[v];
			}
		}

		mstSet[u] = true;
		for(auto nbr : adj[u]){
			int v = nbr.first;
			int wt = nbr.second;
			if(mstSet[v]==false and wt<key[v]){
				key[v] = wt;
				parent[v] = u;
			}
		}
	}

	// this will print edges of MST
	for(int i=1;i<n;i++){
		cout<<parent[i]<<" -- "<<i<<"\n";
	}

	// total cost of MST
	int sum = accumulate(key.begin(),key.end(),0);

	return 0;
}