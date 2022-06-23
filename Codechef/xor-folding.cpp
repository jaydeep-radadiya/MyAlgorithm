#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int r,c;
		cin>>r>>c;

		int cnt = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				char n; cin>>n;
				if(n=='1') cnt++;
			}
		}

		if(cnt%2==1)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}

	return 0;
}