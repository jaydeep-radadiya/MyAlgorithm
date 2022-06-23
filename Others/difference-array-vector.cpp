#include<bits/stdc++.h>
using namespace std;
#define ll long long

// int main(){
// 	int n,q;
// 	cin>>n>>q;
// 	vector<int> arr(n,0);
// 	while(q--){
// 		int l,r;
// 		cin>>l>>r;
// 		arr[l]++;
// 		if(r+1<n)
// 			arr[r+1]--;
// 	}
// 	for(int i=1;i<n;i++)
// 		arr[i] = arr[i]+arr[i-1];
// 	for(int ele : arr)
// 		cout<<ele<<" ";

// 	return 0;
// }

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	vector<int> idx(n,0);
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;r--; // to shift 1 based indexing to 0 based 
		idx[l]++;
		if(r+1<n)
			idx[r+1]--;
	}
	for(int i=1;i<n;i++)
		idx[i] = idx[i]+idx[i-1];

	sort(idx.begin(),idx.end());
	sort(arr.begin(),arr.end());

	ll ans = 0;
	for(int i=0;i<n;i++)
		ans += (ll)(idx[i]*arr[i]);
	cout<<ans<<"\n";

	return 0;
}