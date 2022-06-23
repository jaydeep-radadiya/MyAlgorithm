#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int cnt = 0;
	while(n--){
		int present,capacity;
		cin>>present>>capacity;

		if(capacity-present>=2)
			cnt++;
	}

	cout<<cnt<<"\n";
	return 0;
}