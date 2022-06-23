#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr(4);
	for(int i=0;i<4;i++)
		cin>>arr[i];

	int n;
	cin>>n;
	vector<bool> ans(n+1,false);

	for(int i=0;i<4;i++){
		int x = arr[i];
		for(int j=x;j<ans.size();j=j+x){
			if(ans[j]==false){
				ans[j] = true;
			}
		}
	}

	int cnt = 0;
	for(int i=1;i<ans.size();i++){
		if(ans[i]==true){
			cnt++;
		}
	}

	cout<<cnt<<"\n";
	return 0;
}