// magic numbers : geeksforgeeks

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

ll product(vector<int> &arr,int n){
	ll ans = 1;
	for(int i=0;i<n;i++)
		ans = (ans*arr[i])%mod;
	return ans;
}

ll findgcd(vector<int> &arr,int n){
	ll ans = __gcd(arr[0],arr[1]);
	for(int i=2;i<n;i++)
		ans = __gcd(ans,arr[i]);
	return ans;
}

ll power(int a,int b){
	ll ans = 1;
	while(b>0){
		if(b&1) ans = ans*a;
		a = a*a;
		b = b/2;
	}
	return ans;
}

ll solve(vector<int> &arr,int n){
	if(n==1) return power(arr[0],arr[0]);
	ll pro = product(arr,n);
	ll gcd = findgcd(arr,n);
	ll ans = power(pro,gcd);
	return ans;
}

int main(){
	fastIO();

	int t;
	cin>>t;
	whiel(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<solve(arr,n)<<"\n";
	}

	return 0;
}