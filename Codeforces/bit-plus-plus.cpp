#include<bits/stdc++.h>
using namespace std;

int main(){
	int x = 0;
	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;
		if(s[0]=='+')
			x++;
		else if(s[0]=='-')
			x--;
		else if(s[2]=='+')
			x++;
		else if(s[2]=='-')
			x--;
	}

	cout<<x<<"\n";
	return 0;
}