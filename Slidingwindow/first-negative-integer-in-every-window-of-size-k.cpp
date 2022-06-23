vector<int> printFirstNegativeInteger(vector<int> &arr,int k){
	int n = arr.size();
	vector<int> ans;
	list<int> temp;
	int i = 0;
	int j = 0;

	while(j<n){
		if(arr[j]<0){
			temp.push_back(arr[j]);
		}
		if(j-i+1==k){
			j++;
		}
		else if(j-i+1==k){
			if(temp.size()==0)
				ans.push_back(0);
			else
				ans.push_back(temp.front());

			if(arr[i]==temp.front())
				temp.pop_front();
			i++;
			j++;
		}
	}
	return ans;
}

vector<int> bruteforce(vector<int> &arr,int k){
	int n = arr.size();
	vector<int> ans;

	for(int i=0;i<=n-k;i++){
		bool negative_present = false;
		for(int j=i;j<i+k;j++){
			if(arr[j]<0){
				ans.push_back(arr[j]);
				negative_present = true;
				break;
			}
		}
		if(negative_present==false){
			ans.push_back(0);
		}
	}
	return ans;
}