class Solution {
public:

    int solve(int i, vector<int>& memo, vector<int>& nums){
        if(i == 0){
            return memo[0] = nums[0];
        }
        if(i == 1){
            return memo[i] = max(nums[i-1], nums[i]);
        }
        if(memo[i] != -1) return memo[i];
        return memo[i] = max(nums[i] + solve(i-2, memo, nums), solve(i-1, memo, nums));
    }

    int rob(vector<int>& nums){
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(n-1, memo, nums);
    }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     if(n == 0){
    //         return 0;
    //     }

    //     if(n == 1){
    //         return nums[0];
    //     }

    //     vector<int> dp(n);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     for(int i = 2; i < n; i++){
    //         int skip = dp[i-1];
    //         int take = nums[i] + dp[i-2];
    //         dp[i] = max(take, skip);
    //     }

    //     return dp[n-1];
    // }
};
