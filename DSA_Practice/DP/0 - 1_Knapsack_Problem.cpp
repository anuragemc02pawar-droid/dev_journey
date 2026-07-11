class Solution {
  public:
    int KS(vector<int>& val,vector<int>& wt,int W,int n,vector<vector<int>>& dp){
        if(W==0 || n==0) return 0;
        
        if(dp[n][W]!=-1)return dp[n][W];
        
        if(wt[n-1]<=W){
            return dp[n][W]=max(val[n-1]+KS(val,wt,W-wt[n-1],n-1,dp),KS(val,wt,W,n-1,dp));
        }
        else{
            return dp[n][W]= KS(val,wt,W,n-1,dp);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return KS(val,wt,W,n,dp);
    }
};