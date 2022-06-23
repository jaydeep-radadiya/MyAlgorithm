#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
	int r,c;
	cin>>r>>c;
	vector<vector<char>> grid(r+1, vector<char> (c+1,'$'));
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>grid[i][j];
		}
	}

	vector<vector<int>> dp(r+1, vector<int> (c+1,0));
	dp[r][c] = 1;

	for(int i=r;i>=1;i--){
		for(int j=c;j>=1;j--){
			if(i==r and j==c){
				continue;
			}
			else if(grid[i][j]=='#'){
				dp[i][j] = 0;
				continue;
			}
			else{
				dp[i][j] = (((i==r)?0:dp[i+1][j])%mod + ((j==c)?0:dp[i][j+1])%mod)%mod;
			}
		}
	}

	cout<<dp[1][1];
	return 0;
}