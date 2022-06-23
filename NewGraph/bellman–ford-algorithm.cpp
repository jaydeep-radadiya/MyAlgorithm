#include<bits/stdc++.h>
using namespace std;

// bf is n^2 algo while dijkshra is nlogn
void bellmanFord(int n,vector<node> &edges){
	vector<int> dist(n+1,INT_MAX); // 1 based

	for(int i=1;i<n;i++){
		for(auto &it : edges){
			int u = it.u;
			int v = it.v;
			int wt = it.wt;
			if(dist[u]+wt<dist[v]){
				dist[v] = dist[u]+wt;
			}
		}
	}

	// perform 1 more iteration to check distance reduce or not
	for(auto &it : edges){
		int u = it.u;
		int v = it.v;
		int wt = it.wt;
		if(dist[u]+wt<dist[v]){
			dist[v] = dist[u]+wt;
			cout<<"Negative cycle exist"<<"\n";
			return;
		}
	}

	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}

int main(){


	return 0;
}