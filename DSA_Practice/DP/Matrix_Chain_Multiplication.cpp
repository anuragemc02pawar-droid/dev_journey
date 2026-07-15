class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int>& arr, int i, int j){
        if(i>=j) return 0;
        
        int ans=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        
        for(int k=i;k<=j-1;k++){
           int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
           
           if(temp<ans){
               ans=temp;
           }
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        int i=1;
        int j=n-1;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(arr,i,j);
        

    }
};