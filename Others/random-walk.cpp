#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ld find_dist(ll x1,ll y1,ll x2,ll y2){
	return sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		vector<ld> x(n);
		vector<ld> y(n);
		for(ll i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		ll qx,qy,rx,ry;
		cin>>qx>>qy>>rx>>ry;
		ld max_dist = find_dist(qx,qy,rx,ry);

		ll idx = -1;
		for(ll i=0;i<n;i++){
			if(rx==x[i] and ry==y[i]){
				idx = i;
				break;
			}
		}
		if(idx!=-1){
			x.erase(x.begin()+idx);
			y.erase(y.begin()+idx);
			n--;
		}

		// vector of index
		vector<int> perm(n);
		for(ll i=0;i<n;i++){
			perm[i] = i;
		}

		ld ans = 0.0;
		ll count = 0;
		ll valid_dist_count = 0;

		do{
			for(ll i=1;i<n;i++){
				ans += find_dist(x[perm[i]],y[perm[i]],x[perm[i-1]],y[perm[i-1]]);
			}
			ans += find_dist(rx,ry,x[perm[0]],y[perm[0]]);
			if(ans<=max_dist)
				valid_dist_count++;
			count++;
			ans = 0.0;
		}while(next_permutation(perm.begin(),perm.end()));
		// next_permutation on index vector

		ld result = (ld)valid_dist_count/count;
		cout<<fixed<<setprecision(8)<<result<<"\n";
	}

	return 0;
}