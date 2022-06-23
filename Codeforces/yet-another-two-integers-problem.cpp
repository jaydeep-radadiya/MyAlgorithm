#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll t;
	cin>>t;

	while(t--){
		ll a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		cout<<fixed<<setprecision(0)<<ceil((b-a)/10.0)<<"\n";
	}

	return 0;
}