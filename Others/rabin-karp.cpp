#include<bits/stdc++.h>
#define ll long long
#define prime 119
using namespace std;

// tc : O(m)
ll createHashValue(string str,int n){
	ll result = 0;
	for(int i=0;i<n;i++){
		result += (ll)(str[i]*(ll)pow(prime,i));
	}
	return result;
}

// tc : O(1)
ll recalculateHash(string str,int oldIdx,int newIdx,ll oldHash,int patLength){
	ll newHash = oldHash-str[oldIdx];
	newHash = newHash/prime;
	newHash += (ll)(str[newIdx]*(ll)pow(prime,patLength-1));
	return newHash;
}

bool checkEqual(string str,string pat,int start1,int end1,int start2,int end2){
	if(end1-start1!=end2-start2){
		return false;
	}
	while(start1<=end1 and start2<=end2){
		if(str[start1]!=pat[start2]){
			return false;
		}
		start1++;
		start2++;
	}
	return true;
}

int main(){
	string str = "ababcabdabab";
	string pat = "abd";
	ll patHash = createHashValue(pat,pat.size());
	ll strHash = createHashValue(str,pat.size());
	for(int i=0;i<=str.size()-pat.size();i++){
		if(patHash==strHash and checkEqual(str,pat,i,i+pat.size()-1,0,pat.size()-1)){
			cout<<i<<"\n";
			return 0;
		}
		if(i<str.size()-pat.size()){
			strHash = recalculateHash(str,i,i+pat.size(),strHash,pat.size());
		}
	}

	return 0;
}