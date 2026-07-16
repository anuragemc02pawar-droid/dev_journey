class Solution {
public:
    long long dp[205][205][2];

    long long solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        long long ans = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {

            long long lt = solve(s, i, k - 1, true);
            long long lf = solve(s, i, k - 1, false);
            long long rt = solve(s, k + 1, j, true);
            long long rf = solve(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue)
                    ans += lt * rt;
                else
                    ans += lt * rf + lf * rt + lf * rf;
            }
            else if (s[k] == '|') {
                if (isTrue)
                    ans += lt * rt + lt * rf + lf * rt;
                else
                    ans += lf * rf;
            }
            else if(s[k]=='^'){ 
                if (isTrue)
                    ans += lt * rf + lf * rt;
                else
                    ans += lt * rt + lf * rf;
            }
        }

        return dp[i][j][isTrue] = ans;
    }

    long long countWays(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1, true);
    }
};