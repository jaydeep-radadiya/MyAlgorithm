#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

ll power(ll a,ll b){
	ll res = 1;
	while(b>0){
		if(b%2==1) res = (res*a)%mod;
		a = (a*a)%mod;
		b = b/2;
	}
	return res;
}

int main(){
	fastIO();

	ll t;
	cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;
		ll temp = power(2,n)-1;
		ll ans = power(temp,m);
		cout<<ans<<"\n";
	}

	return 0;
}