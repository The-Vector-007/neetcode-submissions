class Solution {
public:
    int numDecodings(const string& s) {
        const int n = s.size();
        if (n == 0) return 0;

        int prev2 = 1;                          // dp[i-2]
        int prev1 = (s[0] != '0') ? 1 : 0;      // dp[i-1]

        for (int i = 2; i <= n; ++i) {
            int curr = 0;

            // Single digit
            if (s[i - 1] != '0') {
                curr += prev1;
            }

            // Two digits
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};