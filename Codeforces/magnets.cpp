#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,nc;
	cin>>n;
	nc = n;

	string s;
	while(n--){
		string temp;
		cin>>temp;
		s += temp;
	}

	if(nc==1){
		cout<<1<<"\n";
		return 0;
	}

	int gp = 1;
	for(int i=2;i<s.size();i+=2){
		if(s[i]==s[i-1]){
			gp++;
		}
	}

	cout<<gp<<"\n";
	return 0;
}