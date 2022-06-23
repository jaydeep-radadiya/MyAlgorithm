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

class Solution {
public:
    vector<int> numIslands2(int r, int c, vector<Point> &operators) {
        DSU dsu(r*c+1);
        int cnt = 0;
        vector<vector<int>> grid(r,vector<int> (c,0));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vector<int> ans;

        for(auto &it : operators){
        	int x = it[0];
        	int y = it[1];
        	if(grid[x][y]==1){
        		ans.push_back(cnt);
        		continue;
        	}

        	grid[x][y] = 1;
        	int idx1 = x*c+(y+1); // 1d coordinate
        	cnt++;
        	
        	for(int dir=0;dir<4;dir++){
        		int new_x = x+dx[dir];
        		int new_y = y+dy[dir];
        		int idx2 = new_x*c+(new_y+1);

        		if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && grid[new_x][new_y]==1 && dsu.findParent(idx1)!=dsu.findParent(idx2)){
        			cnt--;
        			dsu.Union(idx1,idx2);
        		}
        	}
        	ans.push_back(cnt);
        }
        return ans;
    }
};