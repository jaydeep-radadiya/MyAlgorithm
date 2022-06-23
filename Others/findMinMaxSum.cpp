#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

int findMax(int *arr,int n,int k){
	int mx = 0;
	int sum = 0;
	int i = 0,j = 0;
	while(j<n){
		sum += arr[j];
		if(j-i+1<k){
			j++;
		}
		else{
			mx = max(mx,sum);
			sum -= arr[i];
			i++;
			j++;
		}
	}
	return mx;
}

int findMin(int *arr,int n,int k){
	int mn = INT_MAX;
	int sum = 0;
	int i = 0,j = 0;
	while(j<n){
		sum += arr[j];
		if(j-i+1<k){
			j++;
		}
		else{
			mn = min(mn,sum);
			sum -= arr[i];
			i++;
			j++;
		}
	}
	return mn;
}

int main(){
	fastIO();

	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<findMax(arr,n,k);
	cout<<"\n";
	cout<<findMin(arr,n,k);

	return 0;
}