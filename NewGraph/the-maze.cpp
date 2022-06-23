// bfs solution
class Solution {
public:
	bool hasPath(vector<vector<int>> &maze,vector<int> &start,vector<int> &dest){
		int r = maze.size();
		int c = maze[0].size();

		int vis[r][c];
		memset(vis,0,sizeof(vis));
		queue<pair<int,int>> q;
		q.push({start[0],start[1]});
		vis[start[0]][start[1]] = 1;

		while(not q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if(x==dest[0] && y==dest[1]) return true;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

			for(int i=0;i<4;i++){
				int new_x = x;
				int new_y = y;
				while(new_x>=0 && new_x<r && new_y>=0 && new_y<c && maze[new_x][new_y]==0){
					new_x += dx[i];
					new_y += dy[i];
				}

				// either you crossed boundry or stopped at 1
				new_x -= dx[i];
				new_y -= dy[i];
				if(vis[new_x][new_y]==0){
					vis[new_x][new_y] = 1;
					q.push({new_x,new_y});
				}
			}
		}
		return false;
	}
};