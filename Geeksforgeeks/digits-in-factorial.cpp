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

int digitsInFactorial(int n){
	double logval = 0;
	for(int i=1;i<=n;i++){
		logval += log10(i);
	}
	return floor(logval)+1;
}

int main(){
	fastIO();
	int n;
	cin>>n;
	cout<<digitsInFactorial(n);
	return 0;
}