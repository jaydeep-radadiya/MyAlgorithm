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

int findgcd(int a,int b){
	if(b==0)
		return a;
	else
		return findgcd(b,a%b);
}

int main(){
	fastIO();

	ll t;
	cin>>t;

	while(t--){
		ll a,b;
		cin>>a>>b;

		ll gcd = findgcd(a,b);
		ll lcm = (a*b)/gcd;
		cout<<gcd<<" "<<lcm<<"\n";
	}

	return 0;
}