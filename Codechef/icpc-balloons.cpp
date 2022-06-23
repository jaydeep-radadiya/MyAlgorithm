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
		
		int cnt = 7;
		for(int i=0;i<n;i++){
			if(arr[i]>=1 && arr[i]<=7){
				cnt--;
			}
			if(cnt==0){
				cout<<i+1<<"\n";
				break;
			}
		}
	}

	return 0;
}