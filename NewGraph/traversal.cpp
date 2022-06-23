#include<bits/stc++.h>
using namespace std;
vector<int> adj[100005];
int vis[100005];

void dfs(int node){
	cout<<node<<" ";
	vis[node] = 1;

	for(int neighbour : adj[node]){
		if(vis[neighbour]==0){
			dfs(neighbour);
		}
	}
}

void bfs(int node){
	vis[node] = 1;
	queue<int> q;
	q.push(node);

	while(not q.empty()){
		int curr = q.front();
		cout<<curr<<" ";
		q.pop();

		for(int ele : adj[curr]){
			if(vis[ele]==0){
				q.push(ele);
				vis[ele] = 1;
			}
		}
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// for every component
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			// dfs(i);
			bfs(i);
		}
	}
	return 0;
}