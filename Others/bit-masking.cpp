#include<bits/stdc++.h>
using namespace std;

// filter character according to mask and print
void filter(string s,int mask){
	int i = 0;
	while(mask>0){
		if(mask&1)
			cout<<s[i];
		else
			cout<<"";
		i++;
		mask = mask>>1;
	}
	cout<<"\n";
}

void solve(string s){
	int n = s.size();
	int range = (1<<n)-1;

	for(int i=0;i<=range;i++){
		filter(s,i); // i act as mask
	}
}

int main(){
	string s;
	cin>>s;
	solve(s);

	return 0;
}