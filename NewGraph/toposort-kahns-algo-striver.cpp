// n --> number of nodes
// adj --> adjacency list
void toposort(int n,vector<int> adj[]){
	vector<int> indegree(n,0);

	for(int i=0;i<n;i++){
		for(int neighbour : adj[i]){
			// i --> neighbour
			indegree[neighbour]++;
		}
	}

	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	vector<int> final_ans;
	while(not q.empty()){
		int u = q.front();
		final_ans.push_back(u);
		q.pop();

		for(int neighbour : adj[u]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				q.push(neighbour);
			}
		}
	}
	return final_ans;
}