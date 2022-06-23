// unique number 1
// all numbers are present twice except one number find that number
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int val = 0;
	for(int i=0;i<n;i++)
		val = val^arr[i];
	cout<<val;

	return 0;
}

// unique number 2
// all numbers are present twice except two numbers which are present only once find that
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr,int n){
	int res = 0;
	for(int i=0;i<n;i++)
		res = res^arr[i];

	int temp = res;
	// find the last set bit
	int i = 0;
	while(temp>0){
		if(temp&1){
			break;
		}
		temp = temp>>1;
		i++;
	}

	int mask = 1<<i;
	int first = 0;
	for(int i=0;i<n;i++){
		if(mask&arr[i]){
			first = first^arr[i];
		}
	}

	int second = res^first;

	if(first<second)
		return {first,second};
	else
		return {second,first};
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	vector<int> ans = solve(arr,n);
	cout<<ans[0]<<" "<<ans[1];
	return 0;
}

// unique number 3
// all the numbers are present thrice except for one number
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int n){
	vector<int> arr(64,0);

	for(int j=0;j<n;j++){
		int ele = nums[j];
		
		// extract ith bit of ele
		// add ith bit val in arr
		int i = 0;
		while(ele>0){
			arr[i] = (ele&1); // in ele we goes right to left & in arr left to right
			ele = ele>>1;
			i++;
		}
	}

	for(int &ele : arr)
		ele = ele%3;

	int p = 1;
	int number = 0;
	for(int i=0;i<64;i++){
		number += arr[i]*p;
		p = p*2;
	}
	return number;
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];

	cout<<solve(nums,n);
	return 0;
}