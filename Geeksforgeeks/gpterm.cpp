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

double nthterm(int a,int b,int n){
	double r = (double)b/a;
	return a*pow(r,n-1);
}

int main(){
	fastIO();
	int a = 2;
	int b = 4;
	int n = 7;
	cout<<nthterm(a,b,n);
	return 0;
}