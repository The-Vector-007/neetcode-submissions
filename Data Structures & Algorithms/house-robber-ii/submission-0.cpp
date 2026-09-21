class Solution {
public:

    int houseRobberHelper(vector<int> nums){
        int n = nums.size();

        if(n == 0){
            return 0;
        }

        if(n == 1){
            return nums[0];
        }

        //dp[i] = maximum sum from 0..i while following adjacency constraint
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int skip = dp[i-1];
            int take = nums[i] + dp[i-2];
            dp[i] = max(take, skip);
        }


        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0){
            return 0;
        }

        if(n == 1){
            return nums[0];
        }

        vector<int> nums1(nums.begin(), nums.begin() + n - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(houseRobberHelper(nums1), houseRobberHelper(nums2));
    }
};
