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

void reverse(vector<int> &arr,int left,int right){
	while(left<right){
		swap(arr[left++],arr[right--]);
	}
}

void reverseInGroups(vector<int> &arr,int n,int k){
	for(int i=0;i<n;){
		if(i+k-1<n){
			reverse(arr,i,i+k-1);
			i = i + k;
		}
		else{
			reverse(arr,i,n-1);
			i = i + k;
		}
	}
}

int main(){
	fastIO();
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	reverseInGroups(arr,n,k);
	for(int ele : arr)
		cout<<ele<<" ";

	return 0;
}