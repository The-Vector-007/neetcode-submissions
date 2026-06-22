class Solution {
public:

    bool canShip(vector<int>& weights, int given_capacity, int maximum_days){
        int current_weight = 0, no_of_days = 0;
        for(int weight : weights){

            current_weight += weight;

            if(current_weight > given_capacity){
                no_of_days++;
                current_weight = weight;
            }
        }

        if(current_weight <= given_capacity){
            no_of_days++;
        }

        return no_of_days <= maximum_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        int ans = lo;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(canShip(weights, mid, days)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};