#include<bits/stdc++.h>
using namespace std;

// similar to lcm
long long getSmallestDivNum(long long n){
	long long ans = 1;
	for(long long i=1;i<=n;i++)
		ans = (ans*i)/(__gcd(ans,i));
	return ans;
}

int main(){
	int n = 6;
	cout<<getSmallestDivNum(n)<<"\n";
	return 0;
}