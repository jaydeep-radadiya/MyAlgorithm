#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	vector<int> left(n);
	vector<int> right(n);
	vector<int> water(n);

	left[0] = arr[0];
	for(int i=1;i<n;i++)
		left[i] = max(left[i-1],arr[i]);

	right[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--)
		right[i] = max(right[i+1],arr[i]);

	for(int i=0;i<n;i++)
		water[i] = min(left[i],right[i])-arr[i];

	int total = accumulate(water.begin(),water.end(),0);
	cout<<total;

	return 0;
}