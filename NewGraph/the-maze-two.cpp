class Solution {
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int r = maze.size();
        int c = maze[0].size();
        vector<int> dist(r*c+1,INT_MAX);
        dist[start[0]*c+start[1]] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minh;
        minh.push({0,{start[0],start[1]}});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(not minh.empty()){
            int d = minh.top().first;
            int x = minh.top().second.first;
            int y = minh.top().second.second;
            minh.pop();

            for(int i=0;i<4;i++){
                int cnt = 0; // cnt the steps
                int new_x = x;
                int new_y = y;
                while(new_x>=0 && new_x<r && new_y>=0 && new_y<c && maze[new_x][new_y]==0){
                    new_x += dx[i];
                    new_y += dy[i];
                    cnt++;
                }
                new_x -= dx[i];
                new_y -= dy[i];
                cnt--;

                if(d+cnt<dist[new_x*c+new_y]){
                    dist[new_x*c+new_y] = d+cnt;
                    minh.push({d+cnt,{new_x,new_y}});
                }
            }
        }
        if(dist[destination[0]*c+destination[1]]==INT_MAX)
            return -1;
        else
            return dist[destination[0]*c+destination[1]];
    }
};