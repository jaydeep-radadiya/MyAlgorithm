#include<bits/stdc++.h>
using namespace std;

// cs : O(r*c) all oranges are rotten
int orangesRotting(vector<vector<int>> &grid){
	int r = grid.size();
	int c = grid[0].size();
	queue<pair<int,pair<int,int>>> q;

	int oranges = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(grid[i][j]==2)
				q.push({0,{i,j}});
			if(grid[i][j]==1 or grid[i][j]==2)
				oranges++;
		}
	}

	int cnt = 0;
	int mn_time = 0;
	while(not q.empty()){
		int time = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		cnt++;

		mn_time = max(mn_time,time);
		int dx[] = {-1,0,1,0};
		int dy[] = {0,1,0,-1}; 
		for(int i=0;i<4;i++){
			int new_x = x+dx[i];
			int new_y = y+dy[i];
			if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && grid[new_x][new_y]==1){
				q.push({time+1,{new_x,new_y}});
				grid[new_x][new_y] = 2;
			}
		}
	}
	if(oranges==cnt) return mn_time;
	else return -1;
}

// another way
// redable code
class Node {
public:
    int x, y, time;
    Node(int x,int y,int time){
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        int oranges = 0; // cnt oranges
        queue<Node> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==2)
                    q.push(Node(i,j,0));
                if(arr[i][j]!=0)
                    oranges++;
            }
        }
        
        int ans = 0;
        int cnt = 0;
        while(not q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            cnt++;
            
            ans = max(ans,time);
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && arr[new_x][new_y]==1){
                    q.push(Node(new_x,new_y,time+1));
                    arr[new_x][new_y] = 2;
                }
            }
        }
        if(oranges==cnt) return ans;
        else return -1;
    }
};

int main(){

	return 0;
}