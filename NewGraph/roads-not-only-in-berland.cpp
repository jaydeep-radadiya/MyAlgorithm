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

void roadsInBerland(){
	int n;
	cin>>n;
	int e = n-1;
	DSU dsu(n+1);
	vector<pair<int,int>> extraRoad;

	// step 1: store old roads
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		if(dsu.findParent(u)==dsu.findParent(v)){
			extraRoad.push_back({u,v});
		}
		else{
			dsu.Union(u,v);
		}
	}

	// step 2: figure out number of component by storing altimate aprent
	set<int> ss;
	for(int i=1;i<=n;i++){
		ss.insert(dsu.findParent(i));
	}

	int noc = ss.size()-1; // number of component
	cout<<noc<<"\n";
	// vec contain altimate parent of component
	vector<int> vec(ss.begin(),ss.end());
	int j = 0;
	for(int i=1;i<=noc;i++){
		cout<<extraRoad[j].first<<" "<<extraRoad[j].second<<" "<<vec[i]<<" "<<vec[i-1]<<"\n";
		j++;
	}
}

int main(){
	roadsInBerland();
	return 0;
}