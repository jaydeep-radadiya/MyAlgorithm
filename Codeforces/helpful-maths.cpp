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

	string s;
	cin>>s;

	vector<char> arr;

	for(int i=0;i<s.size();i++){
		if(i%2==0){
			arr.push_back(s[i]);
		}
	}

	sort(arr.begin(),arr.end());

	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
		if(i!=arr.size()-1)
			cout<<"+";
	}

	return 0;
}