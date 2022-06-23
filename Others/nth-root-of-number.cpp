#include<iostream>
#include<cmath>
using namespace std;

double multiply(double number,int n){
	double ans = 1;
	for(int i=1;i<=n;i++){
		ans = ans*number;
	}
	return ans;
}

void getNthRoot(int n,int m){
	double left = 0;
	double right = m;
	double eps = 1e-6;

	while((right-left)>eps){
		double mid = left+(right-left)/2;

		if(multiply(mid,n)<m)
			left = mid;
		else
			right = mid;
	}
	cout<<left<<" "<<right<<"\n";
	cout<<pow(m,1.0/n);
}

int main(){
	int n,m;
	cin>>n>>m;
	getNthRoot(n,m);
	return 0;
}