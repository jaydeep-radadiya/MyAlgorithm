#include<bits/stdc++.h>
using namespace std;

// only applicable when 2 different weights like (0,1) (0,5) (0,8)
// one has to be 0, second is any
void bfszeroone(int src){
	deque<pair<int,int>> dq;
	vector<int> dist(n,INT_MAX);
	dist[src] = 0;
	dq.pop_front({src,dist[src]});

	while(not dq.empty()){
		int node = dq.front().first;
		int d = dq.front().second;
		dq.pop_front();

		for(auto nbr : adj[node]){
			int neighbour = nbr.first;
			int wt = nbr.second;
			if(d+wt<dist[neighbour]){
				if(wt==0) dq.push_front({neighbour,wt+d}); // +0
				else dq.push_back({neighbour,wt+d}); // +1
				dist[neighbour] = wt+d;
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