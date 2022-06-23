#include<bits/stdc++.h>
using namespace std;

bool ss(int arr[],int sum,int n){
	bool t[n+1][sum+1];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)
				t[i][j] = false;
			if(j==0)
				t[i][j] = true;
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	return t[n][sum];
}

int main(){
	int arr[] = {3,34,4,12,5,2};
	int sum = 9;
	int n = sizeof(arr)/sizeof(int);
	cout<<ss(arr,sum,n);
	return 0;
}