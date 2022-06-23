#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;

	if(s.size()==1){
		transform(s.begin(),s.end(),s.begin(),::toupper);
		cout<<s<<"\n";
		return 0;
	}

	bool flag = true;
	for(int i=1;i<s.size();i++){
		if(s[i]>=65 && s[i]<=90){
			continue;
		}
		else{
			flag = false;
		}
	}

	if(flag==true){
		transform(s.begin(),s.end(),s.begin(),::tolower);
		s[0] = s[0]-32;
		cout<<s<<"\n";
	}
	else if(flag==false){
		cout<<s<<"\n";
	}

	return 0;
}