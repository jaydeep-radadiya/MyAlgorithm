#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int p;
	cin>>p;
	vector<int> arr1(p);
	for(int i=0;i<p;i++)
		cin>>arr1[i];

	int q;
	cin>>q;
	vector<int> arr2(q);
	for(int i=0;i<q;i++)
		cin>>arr2[i];

	unordered_set<int> s;
	for(int i=0;i<p;i++)
		s.insert(arr1[i]);
	for(int i=0;i<q;i++)
		s.insert(arr2[i]);

	if(s.size()==n)
		cout<<"I become the guy."<<"\n";
	else
		cout<<"Oh, my keyboard!"<<"\n";

	return 0;
}