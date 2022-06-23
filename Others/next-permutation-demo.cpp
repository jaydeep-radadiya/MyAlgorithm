#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr {11,22,33};
	do{
		for(int i=0;i<arr.size();i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}while(next_permutation(arr.begin(),arr.end()));
	// same for prev_permutation(arr.begin(),arr.end())

	return 0;
}