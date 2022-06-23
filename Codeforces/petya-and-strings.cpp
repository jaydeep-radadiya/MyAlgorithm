#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)

int main(){
	fastIO();

	string s1,s2;
	cin>>s1>>s2;

	transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	transform(s2.begin(),s2.end(),s2.begin(),::tolower);

	if(s1.compare(s2)==0){
		cout<<0<<"\n";
		return 0;
	}

	int flag = false;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>s2[i]){
			cout<<1<<"\n";
			flag = true;
			break;
		}
		else if(s1[i]<s2[i]){
			cout<<-1<<"\n";
			flag = true;
			break;
		}
	}

	return 0;
}