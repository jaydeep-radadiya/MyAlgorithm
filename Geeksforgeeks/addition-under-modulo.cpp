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
#define PI 3.141592653589793

ll add(ll a,ll b){
	return (a%mod+b%mod)%mod;
}

int main(){
	fastIO();
	ll a = 9223372036854775807;
	ll b = 9223372036854775807;
	cout<<add(a,b)<<"\n";
	return 0;
}