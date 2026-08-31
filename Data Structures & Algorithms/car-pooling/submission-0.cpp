class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;

        for(auto& trip : trips){
            int load = trip[0], start = trip[1], end = trip[2];
            events[start] += load;
            events[end] -= load;
        }

        int totalLoad = 0;
        for(auto event : events){
            auto& [position, loadChange] = event;
            totalLoad += loadChange;

            if(totalLoad > capacity){
                return false;
            }
        }

        return true;
    }
};