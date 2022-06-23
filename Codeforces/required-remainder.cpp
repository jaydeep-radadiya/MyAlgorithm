#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int x,y,n;
		cin>>x>>y>>n;

		bool flag = false;
		for(int k=n;k>0;k--){
			if(k%x==y){
				cout<<k<<"\n";
				flag = true;
				break;
			}
		}
		if(flag==false){
			cout<<0<<"\n";
		}
	}

	return 0;
}