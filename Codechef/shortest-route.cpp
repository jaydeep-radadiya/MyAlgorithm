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

	ll t;
	cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<int> train(n+1);
		for(int i=1;i<n+1;i++)
			cin>>train[i];

		vector<int> left,right;
		for(int i=1;i<n+1;i++){
			if(train[i]==1)
				right.push_back(i);
			else if(train[i]==2)
				left.push_back(i);
		}

		while(m--){
			ll destination;
			cin>>destination;
			int dis1 = INT_MAX;
			int dis2 = INT_MAX;

			auto it1 = lower_bound(left.begin(),left.end(),destination);
			if(it1!=left.end()){
				dis1 = (*it1)-destination;
			}

			auto it2 = lower_bound(right.begin(),right.end(),destination);
			if(it2!=right.end() && (*it2)==destination){
				dis2 = *it2;
			}
			else if(it2!=right.begin()){
				it2--;
				dis2 = destination-(*it2);
			}

			ll ans = min(dis1,dis2);
			if(ans==INT_MAX)
				ans = -1;
			if(destination==1)
				ans = 0;
			cout<<ans<<" ";
		}
		cout<<"\n";
	}

	return 0;
}