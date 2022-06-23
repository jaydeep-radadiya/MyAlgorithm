#include<bits/stdc++.h>
using namespace std;

int main(){
	// string tokenizer
	string str;
	cin>>str;

	// char *token = strtok(&str[0],"-");
	// while(token!=NULL){
	// 	cout<<token<<"\n";
	// 	token = strtok(NULL,"-");
	// }

	istringstream is(str);
	// istringstream var(str);
	string token;
	while(getline(is,token,'-')){
		cout<<token<<"\n";
	}

	return 0;
}