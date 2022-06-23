#include<bits/stdc++.h>
using namespace std;

void printSubset(int n,vector<int> &arr){
	vector<int> temp;
	int idx = 0;

	while(n>0){
		if(n&1){
			temp.push_back(arr[idx]);
		}
		n = n/2;
		idx++;
	}

	for(int ele : temp){
		cout<<ele<<" ";
	}
	cout<<"\n";
}

void generateSubsets(vector<int> &arr){
	int n = arr.size();
	int range = 1<<n;
	for(int i=0;i<range;i++){
		printSubset(i,arr);
	}
}

int main(){
	vector<int> arr = {11,22,33};
	generateSubsets(arr);
	return 0;
}