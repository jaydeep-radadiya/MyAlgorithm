#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int mx = 0;
	int total = 0;

	while(n--){
		int getout,getin;
		cin>>getout>>getin;
		total = total-getout+getin;
		mx = max(mx,total);
	}

	cout<<mx<<"\n";
	return 0;
}