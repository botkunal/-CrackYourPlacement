class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // DP table initialization
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Iterate over each string in strs
        for (const auto& s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            // Update the DP table in reverse to avoid overwriting
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        // Return the maximum subset size
        return dp[m][n];
    }
};
