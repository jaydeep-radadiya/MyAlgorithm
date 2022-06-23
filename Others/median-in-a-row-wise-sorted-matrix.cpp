int median(vector<vector<int>> &matrix, int r, int c){
    vector<int> arr;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr.push_back(matrix[i][j]);
        }
    }
    
    sort(arr.begin(),arr.end());
    int n = arr.size();
    return arr[(n+1)/2-1];
}