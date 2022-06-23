#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

ll cost(double x,vi &h,vi&c){
	int n = h.size();
	ll cost = 0;
	for(int i=0;i<n;i++){
		cost += abs(h[i]-x)*c[i];
	}
	return cost;
}

// l & r represent height
ll solve(vi &h,vi &c,int n){
	double l = 0.0;
	double r = 1e8;
	// double r = *max_element(h.begin(),h.end());

	for(int i=0;i<150;i++){
		double m1 = l+(r-l)/3;
		double m2 = r-(r-l)/3;

		if(cost(m1,h,c)>cost(m2,h,c))
			l = m1;
		else
			r = m2;
	}
	return min(cost(ceil(l),h,c),cost(floor(r),h,c));
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> h(n),c(n);
		for(int i=0;i<n;i++)
			cin>>h[i];
		for(int i=0;i<n;i++)
			cin>>c[i];
		cout<<solve(h,c,n)<<"\n";
	}

	return 0;
}