#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;

	int uc = 0;
	int lc = 0;

	for(int i=0;i<s.size();i++){
		if(s[i]>=65 && s[i]<=90)
			uc++;
		else
			lc++;
	}

	if(lc>=uc){
		transform(s.begin(),s.end(),s.begin(),::tolower);
		cout<<s<<"\n";
	}
	else{
		transform(s.begin(),s.end(),s.begin(),::toupper);
		cout<<s<<"\n";
	}

	return 0;
}