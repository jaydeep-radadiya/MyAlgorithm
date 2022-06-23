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

ll solve(string &s1,string &s2){
	unordered_map<char,ll> ump;
	ll n1 = s1.size();
	for(ll i=0;i<n1;i++)
		ump[s1[i]] = i;

	ll n2 = s2.size();
	ll cnt = 0;
	for(ll i=1;i<n2;i++){
		cnt += abs(ump[s2[i]]-ump[s2[i-1]]);
	}
	return cnt;
}

int main(){
	fastIO();

	ll t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<solve(s1,s2)<<"\n";
	}

	return 0;
}