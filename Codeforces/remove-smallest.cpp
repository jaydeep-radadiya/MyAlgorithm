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

bool solve(vector<int> &arr){
	sort(arr.begin(),arr.end());
	for(int i=1;i<arr.size();i++){
		if(abs(arr[i]-arr[i-1])>1){
			return false;
		}
	}
	return true;
}

int main(){
	fastIO();

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		bool ans = solve(arr);
		if(ans==1)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}

	return 0;
}