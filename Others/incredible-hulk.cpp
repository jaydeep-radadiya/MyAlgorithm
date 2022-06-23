#include<iostream>
using namespace std;

int solve(int n){
	int moves = 0;
	while(n>0){
		if(n&1){
			moves++;
		}
		n = n>>1;
	}
	return moves;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<"\n";
		// cnt the set bits in number
		// cout<<__builtin_popcount(n)<<"\n";
	}

	return 0;
}