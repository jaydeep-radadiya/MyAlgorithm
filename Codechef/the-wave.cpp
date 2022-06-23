#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> x(q);
	for(int i=0;i<q;i++)
		cin>>x[i];

	sort(a.begin(),a.end());
	for(int i=0;i<q;i++){
		// return true if present else false
		if(binary_search(a.begin(),a.end(),x[i])) 
			cout<<0<<"\n";
		else{
			auto it = upper_bound(a.begin(),a.end(),x[i]);
			if((a.end()-it)%2==0)
				cout<<"POSITIVE"<<"\n";
			else
				cout<<"NEGATIVE"<<"\n";
		}
	}

	return 0;
}