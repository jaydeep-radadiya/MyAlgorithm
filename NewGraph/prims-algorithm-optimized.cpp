#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
// tc : O(nlogn)

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

	priority_queue<pii,vector<pii>,greater<pii>> minh;
	minh.push({0,0}); // (key,index)

	while(not minh.empty()){
		int u = minh.top().second;
		minh.pop();

		mstSet[u] = true;
		for(auto nbr : adj[u]){
			int v = nbr.first;
			int wt = nbr.second;
			if(mstSet[v]==false and wt<key[v]){
				parent[v] = u;
				key[v] = wt;
				minh.push({key[v],v});
			}
		}
	}

	int sum = accumulate(key.begin(),key.end(),0);

	return 0;
}