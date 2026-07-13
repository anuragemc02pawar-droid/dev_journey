class Solution {
public:
    int cntSub(vector<int>& nums, int target, int n, int s1, vector<vector<int>>& dp){
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            if(nums[i-1]==0){
                dp[i][0]=2*dp[i-1][0];
            }else{
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s1+1;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(abs(target)>sum) return 0;
        if((target+sum)%2!=0) return 0;
        int s1=(target+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(s1+1,0));
        return cntSub(nums,target,n,s1,dp);
    }
};