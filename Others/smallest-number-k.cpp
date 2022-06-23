// smallest number k such that the product of digits of k is equal to n

#include<bits/stdc++.h>
using namespace std;
#define ll long long

string smallestNumber(ll n){
	if(n<10) return to_string(n);

	stack<ll> st;
	for(int i=9;i>=2;i--){
		while(n%i==0){
			st.push(i);
			n = n/i;
		}
	}

	if(n!=1) return "-1"; // in the case of prime number > 10
	string ans = "";
	while(st.size()>0){
		ans += to_string(st.top());
		st.pop();
	}
	return ans;
}

int main(){
	cout<<smallestNumber(12);
	return 0;
}