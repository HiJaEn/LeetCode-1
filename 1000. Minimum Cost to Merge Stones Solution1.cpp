class Solution {
public:
    // dp[i][j]: the min cost to merge stones from i to j into the least number of piles
    // divide dp[i][j] according to what is the last stone index of the first pile,
    // which can only be i, i + k - 1, i + 2(k - 1) ...
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1))
            return -1;
        
        vector<int> sums(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            sums[i] += sums[i - 1] + stones[i - 1];
        }
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = K; len <= n; ++len) {
            for (int i = 0; i + len - 1 <= n - 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
                }
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += sums[j + 1] - sums[i];
            }
        }
        return dp[0][n - 1];
    }
};
