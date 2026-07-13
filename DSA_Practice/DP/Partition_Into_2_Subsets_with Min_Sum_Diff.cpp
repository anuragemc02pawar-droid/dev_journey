class Solution {
  public:
    void subSum(vector<int>& arr,int n,int range,vector<vector<bool>>& dp){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<range+1;j++){
                if(i==0){
                    dp[0][j]=false;
                }
                if(j==0){
                    dp[i][0]=true;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<range+1;j++){
                if(j>=arr[i-1]){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        int range=0;
        for(int i=0;i<n;i++){
            range+=arr[i];
        }
        vector<vector<bool>> dp(n+1,vector<bool>(range+1,false));
        subSum(arr,n,range,dp);
        
        int ans=INT_MAX;
        for(int j=0;j<=range/2;j++){
            if(dp[n][j]){
                ans=min(ans,range-2*j);
            }
        }
        return ans;
    }
};
