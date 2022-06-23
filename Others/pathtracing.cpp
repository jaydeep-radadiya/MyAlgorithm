#include<bits/stdc++.h>
using namespace std;

int main(){
	string instr;
	vector<string> v;
	v.push_back("*");
	int start_x = 0, start_y = 0;
	int curr_x = 0, curr_y = 0; 

	while(cin>>instr){
		if(instr=="down"){
			curr_y++;
			if(curr_y>=v.size()){
				string temp(v[0].size(),' ');
				v.push_back(temp);
			}
		}
		if(instr=="up"){
			curr_y--;
			if(curr_y<0){
				curr_y++;
				start_y++;
				string temp(v[0].size(),' ');
				v.insert(v.begin(),temp);
			}
		}
		if(instr=="left"){
			curr_x--;
			if(curr_x<0){
				curr_x++;
				start_x++;
				for(auto &row : v){
					row.insert(row.begin(),' ');
				}
			}
		}
		if(instr=="right"){
			curr_x++;
			if(curr_x>=v.size()){
				for(auto &row : v){
					row.push_back(' ');
				}
			}
		}
		// add a star
		v[curr_y][curr_x] = '*';
	}
	v[curr_y][curr_x] = 'E';
	v[start_y][start_x] = 'S';

	// append hast in string
	for(auto &row : v){
		row.insert(row.begin(),'#');
		row.push_back('#');
	}
	string str(v[0].size(),'#');
	v.insert(v.begin(),str);
	v.push_back(str);

	// print the path
	for(auto row : v){
		cout<<row<<"\n";
	}

	return 0;
}