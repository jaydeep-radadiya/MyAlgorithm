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

// e3d : exactly3divisors
int e3d(int n){
	vector<bool> prime(n+1,true);
	prime[0] = prime[1] = false;

	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				prime[j] = false;
			}
		}
	}

	int cnt = 0;
	for(int i=2;i<=sqrt(n);i++){
		if(prime[i]==true){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	fastIO();
	int n;
	cin>>n;
	cout<<e3d(n);
	return 0;
}