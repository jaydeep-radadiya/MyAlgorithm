#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int>> dp(3,vector<int> (n,0));

	int a,b,c;
	cin>>a>>b>>c;
	dp[0][0] = a;
	dp[1][0] = b;
	dp[2][0] = c;

	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dp[0][i] = a+max(dp[1][i-1],dp[2][i-1]);
		dp[1][i] = b+max(dp[0][i-1],dp[2][i-1]);
		dp[2][i] = c+max(dp[0][i-1],dp[1][i-1]);
	}

	cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
	return 0;
}