class Solution {
  public:
  const int MOD =1e9+7;
    int modSum(vector<int>& arr,int target, int n,vector<vector<int>>& dp){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i==0){
                    dp[0][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(j>=arr[i-1]){
                    dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j])%MOD;
                }else{
                    dp[i][j]=dp[i-1][j]%MOD;
                }
            }
        }
        return dp[n][target];
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        return modSum(arr,target,n,dp);
        
    }
};