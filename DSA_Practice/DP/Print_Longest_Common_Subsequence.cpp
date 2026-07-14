string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	int i=n,j=m;
	string s="";
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			s.push_back(s1[i-1]);
			i--;
			j--;
		}else{
			if(dp[i][j-1]>dp[i-1][j]){
				j--;
			}else{
				i--;
			}
		}
	}
	reverse(s.begin(),s.end());
	return s;
}