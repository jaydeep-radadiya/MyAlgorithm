#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int sum = accumulate(arr.begin(),arr.end(),0);

	if(sum==0)
		cout<<"EASY"<<"\n";
	else
		cout<<"HARD"<<"\n";


	return 0;
}