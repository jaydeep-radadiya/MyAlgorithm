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

int main(){
	fastIO();

	ll t;
	cin>>t;

	while(t--){
		ll xa,xb,XA,XB;
		cin>>xa>>xb>>XA>>XB;
		cout<<XA/xa+XB/xb<<"\n";
	}

	return 0;
}