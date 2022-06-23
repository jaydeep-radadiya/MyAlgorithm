#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int small = find(arr.begin(),arr.end(),1)-arr.begin();
		int big = find(arr.begin(),arr.end(),n)-arr.begin();

		if(small>big)
			swap(small,big);

		cout<<min({big+1,small+1+n-big,n-small})<<"\n";
	}

	return 0;
}