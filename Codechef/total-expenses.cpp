#include<bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// order_of_key(val) : returns number of values less than than val
// find_by_order(k) : returns the kth largest element (0 based)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<string> tokenizer(string str,char ch){
    istringstream var((str));
    vector<string> vec;
    string temp;
    
    while(getline((var)), temp, (ch)){
        vec.push_back(temp);
    }
    return vec;
}

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define mid(l,r) (l+(r-l)/2)
#define PI 3.141592653589793

int main(){
	fastIO();

	cout<<<"hello world";

	return 0;
}