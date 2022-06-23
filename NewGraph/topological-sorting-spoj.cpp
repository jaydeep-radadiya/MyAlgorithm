// incomplete

#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(int n,vector<int> adj[],vector<int> &ans){
	vector<int> indegree(n);
	for(int i=0;i<n;i++){
		for(int neighbour : adj[i]){
			indegree[neighbour]++;
		}
	}

	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	while(not q.empty()){
		int node = q.front();
		ans.push_back(node);
		q.pop();

		for(int neighbour : adj[node]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				q.push(neighbour);
			}
		}
	}
	return ans;
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<int> ans;
	toposort(n,adj,ans);
	if(ans.size()==n){
		for(int ele : ans){
			cout<<ele<<" ";
		}
	}
	else{
		cout<<"Sandro fails.";
	}

	return 0;
}