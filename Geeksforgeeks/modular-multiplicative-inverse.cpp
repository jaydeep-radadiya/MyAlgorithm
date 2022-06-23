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

int modInverse(int a,int m){
	// mmi belongs to [0,m-1]
	for(int i=0;i<m;i++){
		if((a*i)%m==1){
			return i;
		}
	}
	return -1;
}

int main(){
	fastIO();
	int a = 3;
	int m = 11;
	cout<<modInverse(a,m);
	return 0;
}