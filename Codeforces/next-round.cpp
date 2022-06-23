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

	int n,k;
	cin>>n>>k;
	int cnt = 0;

	vector<int> arr(n+1);
	for(int i=1;i<arr.size();i++)
		cin>>arr[i];

	for(int i=1;i<arr.size();i++){
		if(arr[i]>0 && arr[i]>=arr[k]){
			cnt++;
		}
	}

	cout<<cnt<<"\n";
	return 0;
}