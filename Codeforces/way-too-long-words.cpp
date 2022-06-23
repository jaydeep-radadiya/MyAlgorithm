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

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		if(n>10)
			cout<<s[0]<<n-2<<s[n-1]<<"\n";
		else
			cout<<s<<"\n";
	}

	return 0;
}