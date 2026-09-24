class Solution {
public:
    int numDecodings(const string& s) {
        const int n = s.size();
        if (n == 0) return 0;

        // dp[i] = number of ways to decode s[0..i-1]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;

        for (int i = 2; i <= n; ++i) {
            // Single digit decode (s[i-1])
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two digit decode (s[i-2..i-1])
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};