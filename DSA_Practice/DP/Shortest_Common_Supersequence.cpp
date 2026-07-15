class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s="";
        for(int i=0;i<n;i++){
        s.push_back(s1[i]);
        }
        for(int i=0;i<m;i++){
        s.push_back(s1[i]);
        }
        
        return s.size()-dp[n][m];
        
    }
};