#include<bits/stdc++.h>
using namespace std;

int tin[1000005], low[1000005], vis[1000005];
int timer = 0;

void dfs(int node,int par){
	tin[node] = low[node] = timer++;
	vis[node] = 1;

	for(auto neighbour : adj[node]){
		if(neighbour==par) continue;
		
		if(not vis[neighbour]){
			dfs(neighbour,node);
			low[node] = min(low[node],low[neighbour]);
			if(low[neighbour] > tin[node]){
				cout<<node<<" -> "<<neighbour<<"\n";
			}
		}
		else{
			low[node] = min(low[node],low[neighbour]);
		}
	}
}

int main(){


	return 0;
}