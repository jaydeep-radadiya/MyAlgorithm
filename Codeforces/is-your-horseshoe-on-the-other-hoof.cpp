#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_set<int> s;
	for(int i=0;i<4;i++){
		int x;
		cin>>x;
		s.insert(x);
	}

	cout<<4-s.size()<<"\n";
	return 0;
}