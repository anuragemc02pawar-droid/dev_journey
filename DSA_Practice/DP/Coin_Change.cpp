class Solution {
public:
    int coinSub(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0){
                    dp[0][j]=INT_MAX-1;
                }
                if(j==0){
                    dp[i][0]=0;
                }
                if(i==1){
                    if((j%coins[0])==0){
                        dp[1][j]=j/coins[0];
                    }else{
                        dp[1][j]=INT_MAX-1;
                    }
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j>=coins[i-1]){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        return coinSub(coins,amount,n,dp);
    }
};