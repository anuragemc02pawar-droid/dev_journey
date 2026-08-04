class Solution {
public:
    void lcs(string &s, string &t, vector<vector<int>>& dp){
    int n=t.size();
    int m=s.size();

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[j-1]==t[i-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    }
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        lcs(s,t,dp);
        
        if(dp[n][m]==m) return true;
        return false;

    }
};