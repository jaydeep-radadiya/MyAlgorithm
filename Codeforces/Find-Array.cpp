#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1,j=2;i<=n;i++){
			cout<<j++<<" ";
		}
		cout<<"\n";
	}

	return 0;
}