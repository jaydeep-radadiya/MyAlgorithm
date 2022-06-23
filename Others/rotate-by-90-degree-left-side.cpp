void rotate(vector<vector<int>> &arr){
	int n = arr.size();
	vector<int> temp;
	for(int j=n-1;j>=0;j--){
		for(int i=0;i<n;i++){
			temp.push_back(arr[i][j]);
		}
	}

	int idx = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j] = temp[idx++];
		}
	}
}

// inplace
void rotate(vector<vector<int>> &arr){
	int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            swap(arr[i][j],arr[n-1-j][n-1-i]);
        }
    }
    
    for(auto &it : arr){
        reverse(it.begin(),it.end());
    }
}