#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
	vector<int> parent, size;

public:
	DSU(int n){
		for(int i=0;i<=n;i++){
			parent.push_back(i);
			size.push_back(1);
		}
	}

	void Union(int u,int v){
		int pu = findParent(u);
		int pv = findParent(v);
		if(pu==pv){
			return;
		}
		if(size[pu]<size[pv]){
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else{
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}

	int findParent(int node){
		if(parent[node]==node){
			return node;
		}
		// path compression -> O(logn)
		// path compression and size -> O(4*alpha) (alpha is very small like 1)
		return parent[node] = findParent(parent[node]);
	}
};

struct node{
	int u,v,wt;
	node(int u,int v,int wt){
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
}

bool comp(node &first,node &second){
	if(first.wt<=second.wt) return true;
	else return false;
}

void kruskal(int n,vector<node> &edges){
	sort(edges.begin(),edges.end(),comp);
	
	DSU dsu(n);
	int cost = 0;
	// vector<node> mst;
	for(auto &it : edges){
		int u = it.u;
		int v = it.v;
		int wt = it.wt;
		if(dsu.findParent(u)!=dsu.findParent(v)){
			dsu.Union(u,v);
			// mst.push_back(it);
			cost += wt;
		}
	}
	cout<<cost<<"\n";
}

int main(){


	return 0;
}