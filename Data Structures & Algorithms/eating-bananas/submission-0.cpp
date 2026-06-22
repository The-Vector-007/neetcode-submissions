class Solution {
public:
    bool canFinish(vector<int>& bananas, int rate, int threshold) {
        long long total_hours = 0;
        for (int banana : bananas) {
            total_hours += (banana + rate - 1) / rate;
        }
        return total_hours <= threshold;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canFinish(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};