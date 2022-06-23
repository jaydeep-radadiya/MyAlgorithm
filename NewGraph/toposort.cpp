#include<bits/stdc++.h>
using namespace std;
int vis[100005];

void toposortHelper(int node,stack<int> &st){
	vis[node] = 1;

	for(int neighbour : adj[node]){
		if(vis[neighbour]==0){
			toposortHelper(neighbour,st);
		}
	}
	st.push(node);
}

void toposort(){
	stack<int> st; // if we take vector instead of stack then reverse the vector
	for(int i=1;i<=n;i++){ // 1 based indexing
		if(vis[i]==0){
			toposortHelper(i,st);
		}
	}

	while(not st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}