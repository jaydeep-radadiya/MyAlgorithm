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

int solve(vector<int> &arr){
	int police = 0; // free police
	int crime = 0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==-1 and police>0)
			police--;
		else if(arr[i]==-1 and police<=0)
			crime++;
		else
			police += arr[i];
	}
	return crime;
}

int main(){
	fastIO();

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<solve(arr);

	return 0;
}