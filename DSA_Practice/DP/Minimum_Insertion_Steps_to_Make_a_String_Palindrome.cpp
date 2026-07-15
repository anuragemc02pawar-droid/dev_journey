class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(n==dp[n][n]){
            return 0;
        }else{
            return n-dp[n][n];
        }
    }
};