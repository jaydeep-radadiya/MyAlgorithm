#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	transform(s.begin(),s.end(),s.begin(),::tolower);
	unordered_set<char> ss;

	for(int i=0;i<n;i++){
		ss.insert(s[i]);
	}

	if(ss.size()==26)
		cout<<"YES"<<"\n";
	else
		cout<<"NO"<<"\n";

	return 0;
}