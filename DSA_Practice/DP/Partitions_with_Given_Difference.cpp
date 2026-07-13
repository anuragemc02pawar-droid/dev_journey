class Solution {
	public:
	int cntSub(vector<int>& arr, int diff, int n, int s1, vector<vector<int>> & dp) {
	    dp[0][0]=1;
		for (int i = 1; i<n + 1; i++) {
			if(arr[i-1]==0){
			    dp[i][0]=2*dp[i-1][0];
			}else{
			    dp[i][0]=dp[i-1][0];
			}
		}
		for (int i = 1; i<n + 1; i++) {
			for (int j = 1; j<s1 + 1; j++) {
				if (j >= arr[i - 1]) {
					dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n][s1];
	}
	int countPartitions(vector<int>& arr, int diff) {
		int n = arr.size();
		int sum = 0;
		for (int i = 0; i<n; i++) {
			sum += arr[i];
		}
		int s1 = (sum + diff)/2;
		if (sum < diff)
			return 0;
		if ((sum + diff) % 2 != 0)
			return 0;
		vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
		return cntSub(arr, diff, n, s1, dp);
		
	}
};
