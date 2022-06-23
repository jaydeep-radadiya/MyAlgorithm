int maximumSumSubarray(vector<int> &arr,int k){
	int n = arr.size();
	int mx_sum = 0;
	int sum = 0;
	int i = 0;
	int j = 0;

	while(j<n){
		sum += arr[j];
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			mx_sum = max(mx_sum,sum);
			sum -= arr[i];
			i++;
			j++;
		}
	}
	return mx_sum;
}

int bruteforce(vector<int> &arr, int k){
	int n = arr.size()
    int mx_sum = 0;
    
    for(int i=0;i<=n-k;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
            sum += arr[j];
        }
        mx_sum = max(mx_sum,sum);
    }
    return mx_sum;
}