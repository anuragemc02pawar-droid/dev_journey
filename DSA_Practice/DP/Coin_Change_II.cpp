class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long CAP = 2'000'000'000'000'000'000LL; // 2e18, well under LLONG_MAX (~9.2e18)
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j] + dp[j - coin], CAP);
                // capping is safe: dp[j] + dp[j-coin] <= 2*CAP = 4e18, which fits in long long.
                // Any cell this large can never legitimately be part of a chain
                // that produces a final answer small enough to fit in int32,
                // so clamping it doesn't corrupt the guaranteed-correct final result.
            }
        }

        return (int)dp[amount];  // guaranteed to fit int32 by problem constraints
    }
};