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
#define PI 3.141592653589793

vector<int> roots(int a,int b,int c){
	vector<int> ans;
	int d = b*b-4*a*c;

	if(d>=0){
		int r1 = floor((-b+sqrt(d))/(2*a));
		int r2 = floor((-b-sqrt(d))/(2*a));
		ans.push_back(r1);
		ans.push_back(r2);
	}
	else{
		return {-1};
	}
	sort(ans.begin(),ans.end(),greater<int>());
	return ans;
}

int main(){
	fastIO();
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> ans = roots(a,b,c);
	for(int ele : ans)
		cout<<ele<<" ";
	return 0;
}