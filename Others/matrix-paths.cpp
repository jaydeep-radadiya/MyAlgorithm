int getNumPaths(int rows, int columns) {
	vector<vector<int>> arr(rows+1,vector<int>(columns+1,1));
	for(int i=rows-1;i>=1;i--){
		for(int j=columns-1;j>=1;j--){
			arr[i][j] = arr[i+1][j]+arr[i][j+1];
		}
	}
	return arr[1][1];
}