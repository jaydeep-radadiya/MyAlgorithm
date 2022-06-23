#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	double temp = 0.0;
	for(int i=0;i<n;i++){
		temp += arr[i]/100.0;
	}

	double ans = (temp/n)*100;
	cout<<fixed<<setprecision(12)<<ans<<"\n";
	return 0;
}