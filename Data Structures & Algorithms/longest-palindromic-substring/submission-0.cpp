class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int bestLen = INT_MIN, bestStart = -1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j; i++){
                int strLen = j - i + 1;

                if(strLen == 1){
                    dp[i][j] = true;
                }

                if(strLen == 2 && s[i] == s[j]){
                    dp[i][j] = true;
                }

                if(strLen >= 3){
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] && strLen > bestLen){
                    bestLen = strLen;
                    bestStart = i;
                }
            }
        }

        if(bestStart == -1){
            return "";
        }

        return s.substr(bestStart, bestLen);
    }
};
