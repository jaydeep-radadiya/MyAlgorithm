#include<bits/stdc++.h>
using namespace std;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<string> split(string s,char ch){
	istringstream var(s);
	vector<string> arr;
	string temp;
	while(getline(var,temp,ch)){
		arr.push_back(temp);
	}
	return arr;
}

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define mid(l,r) (l+(r-l)/2)
#define PI 3.141592653589793

void printArray(int *arr,int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void generateAllBinaryStrings(int *arr,int n,int i){
	if(i==n){
		printArray(arr,n);
		return;
	}
	arr[i] = 0;
	generateAllBinaryStrings(arr,n,i+1);
	arr[i] = 1;
	generateAllBinaryStrings(arr,n,i+1);
}

void generateAllStrings(int *arr,int n,int i){
	if(i==n){
		printArray(arr,n);
		return;
	}
	arr[i] = 1;
	generateAllStrings(arr,n,i+1);
	arr[i] = 2;
	generateAllStrings(arr,n,i+1);
	arr[i] = 3;
	generateAllStrings(arr,n,i+1);
}

int main(){
	fastIO();

	int n = 3;
	int *arr = new int[n];
	// int n = sizeof(arr)/sizeof(int);
	generateAllStrings(arr,n,0);

	return 0;
}