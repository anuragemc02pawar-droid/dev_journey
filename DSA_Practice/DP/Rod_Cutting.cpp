class Solution {
  public:
    int unbounded(vector<int>& price, vector<int>& length, int n, vector<vector<int>>& dp){
        for(int i=0;i<=n;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(j>=length[i-1]){
                    dp[i][j]=max((price[i-1]+dp[i][j-length[i-1]]),dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int> length(n,0);
        for(int i=0;i<n;i++){
            length[i]=i+1;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return unbounded(price,length,n,dp);
    }
};