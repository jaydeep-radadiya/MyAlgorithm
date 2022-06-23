#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int left,int mid,int right){
	int inv_cnt = 0;
	int i = left;
	int j = mid+1;
	int k = 0;
	// unique_ptr<int[]> temp(new int[right-left]);
	int *temp = new int[right-left]();

	while(i<=mid && j<=right){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			inv_cnt += (mid+1-i);
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}

	k = 0;
	for(int i=left;i<=right;i++){
		arr[i] = temp[k++];
	}
	delete [] temp;
	return inv_cnt;
}

int mergesort(int arr[],int left,int right){
	int inv_cnt = 0;
	if(left>=right) return inv_cnt; // i mean return 0
	int mid = left+(right-left)/2;
	inv_cnt += mergesort(arr,left,mid);
	inv_cnt += mergesort(arr,mid+1,right);
	inv_cnt += merge(arr,left,mid,right);
	return inv_cnt;
}

int inversionCount(int arr[],int left,int right){
	return mergesort(arr,left,right);
}

int main(){
	int arr[] = {2,4,1,3,5};
	int n = sizeof(arr)/sizeof(int);
	cout<<inversionCount(arr,0,n-1);
	return 0;
}