class Solution {
	public:
	bool SS(vector<int>& arr, int sum, int n, vector<vector<int>>& dp){
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0){
	                dp[0][j]=false;
	            }
	            if(j==0){
	                dp[i][0]=true;
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return dp[n][sum];
	}
	bool isSubsetSum(vector<int>& arr, int sum) {
		int n = arr.size();
		vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
		return SS(arr,sum,n,dp);
	}
};
