#include<bits/stdc++.h>
using namespace std;

int main(){
	int que,travel;
	cin>>que>>travel;
	int rem = 240-travel;

	int cnt = 0;
	for(int i=1;i<=que;i++){
		if(rem>=5*i){
			cnt++;
			rem -= 5*i;
		}
		else{
			break;
		}
	}

	cout<<cnt<<"\n";
	return 0;
}