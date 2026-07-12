class Solution {
public:
    bool subSetSum(vector<int>& nums, int sumSet, int n, vector<vector<int>>& dp){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sumSet;j++){
                if(i==0){
                    dp[0][j]=false;
                }
                if(j==0){
                    dp[j][0]=true;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sumSet;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sumSet];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int sumSet=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sumSet+1,-1));
        if(sum%2!=0){
            return false;
        }else{
            return subSetSum(nums,sumSet,n,dp);
        }
        
    }
};