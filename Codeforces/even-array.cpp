#include<bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define mid(l,r) (l+(r-l)/2)
#define PI 3.141592653589793

ll solve(vector<ll> &arr,ll n){
	if(n<2) return -1;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]%2==i%2)
			continue;
		else
			cnt++;
	}
	return cnt/2;
}

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<solve(arr,n)<<"\n";
	}

	return 0;
}