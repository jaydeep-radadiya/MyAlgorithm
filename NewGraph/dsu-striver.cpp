#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
	vector<int> parent, size;

	DSU(int n){
		for(int i=0;i<=n;i++){
			parent.push_back(i);
			size.push_back(1);
		}
	}

public:
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

int main(){	


	return 0;
}