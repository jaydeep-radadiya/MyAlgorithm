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

ll solve(ll x,ll n){
	for(ll i=1;i<=n;i++){
		if(x%2==0){
			x = x-i;
		}
		else{
			x = x+i;
		}
	}
	return x;
}

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		ll x,n;
		cin>>x>>n;
		cout<<solve(x,n)<<"\n";
	}

	return 0;
}