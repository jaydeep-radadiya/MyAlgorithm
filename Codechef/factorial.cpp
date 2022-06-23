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
		int n;
		cin>>n;

		int i = 5;
		int cnt = 0;
		while(n/i>=1){
			cnt += n/i;
			i = i*5;
		}
		cout<<cnt<<"\n";
	}

	return 0;
}