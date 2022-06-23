#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool win(vector<string> arr,vector<string> arr_t,char ch){
	bool ans = false;
	for(auto row : arr)
		ans = ans || count(row.begin(),row.end(),'X')==3;
	for(auto col : arr_t)
		ans = ans || count(col.begin(),col.end(),'O')==3;
	ans = ans || arr[0][0]==ch and arr[1][1]==ch and arr[2][2]==ch;
	ans = ans || arr[0][2]==ch and arr[1][1]==ch and arr[2][0]==ch;
	return ans;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		vector<string> arr,arr_t;
		for(int i=0;i<3;i++){
			string x;
			cin>>x;
			arr.push_back(x);
		}
		
		arr_t = arr;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i>j)
					swap(arr_t[i][j],arr_t[j][i]);
			}
		}
		
		ll x_cnt = 0;
		ll o_cnt = 0;
		for(auto row : arr){
			x_cnt += count(row.begin(),row.end(),'X');
			o_cnt += count(row.begin(),row.end(),'O');
		}
		
		bool x_win = win(arr,arr_t,'X');
		bool o_win = win(arr,arr_t,'O');
		
		int fans = 2;
		if((x_win and o_win) or !(x_cnt==o_cnt or x_cnt==o_cnt+1) or (x_win and !(x_cnt==o_cnt+1)) or (o_win and !(o_cnt==x_cnt)))
			fans = 3;
		else if((x_cnt==o_cnt or x_cnt==o_cnt+1) and ((x_win+o_win==1) or (x_cnt+o_cnt==9)))
			fans = 1;
		cout<<fans<<"\n";
	}
	
	return 0;
}