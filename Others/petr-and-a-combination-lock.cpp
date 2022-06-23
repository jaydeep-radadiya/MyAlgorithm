#include<bits/stdc++.h>
using namespace std;

bool printSubset(int n,vector<int> &arr){
	vector<int> temp;

	for(int idx=0;idx<arr.size();idx++,n=n/2){
		if(n&1)
			temp.push_back(arr[idx]);
		else
			temp.push_back(-1*arr[idx]);
	}

	int sum = accumulate(temp.begin(),temp.end(),0);
	sum = sum%360;
	if(sum==0) return true;
	else return false;
}

void generateSubsets(vector<int> &arr){
	int n = arr.size();
	int range = 1<<n;
	for(int i=0;i<range;i++){
		if(printSubset(i,arr)==true){
			cout<<"YES"<<"\n";
			return;
		}
	}
	cout<<"NO"<<"\n";
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	generateSubsets(arr);
	return 0;
}