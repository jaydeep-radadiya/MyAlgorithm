#include<bits/stdc++.h>
using namespace std;

// this is not memoization this is kind of hashing
// tc : O((end-start+1)*arrsize)
// in worst case we visit each node -> (end-start+1)
int findMinSteps(int start,int end,int arr[],int n){
	int vis[end+1] = {0};
	vis[start] = 1;
	queue<pair<int,int>> q;
	q.push({start,0});

	while(not q.empty()){
		int node = q.front().first;
		int steps = q.front().second;
		q.pop();

		if(node==end) return steps;

		for(int i=0;i<n;i++){
			int dest = node*arr[i];
			if(dest<=end and not vis[dest]){
				q.push({dest,steps+1});
				vis[dest] = 1;
			}
		}
	}
	return -1;
}

int main(){
	int arr[] = {2,5,10};
	int start = 2;
	int end = 100;
	int n = sizeof(arr)/sizeof(int);
	cout<<findMinSteps(start,end,arr,n);
	return 0;
}