class Solution {
public:
    int dp[101][10001];

    int solve(int k, int n) {
        if (n == 0 || n == 1)
            return n;

        if (k == 1)
            return n;

        if (dp[k][n] != -1)
            return dp[k][n];

        int l = 1, r = n;
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int low = solve(k - 1, mid - 1); // egg breaks
            int high = solve(k, n - mid);    // egg survives

            ans = min(ans, 1 + max(low, high));

            if (low < high)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};