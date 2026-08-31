class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) { 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        sort(trips.begin(), trips.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });

        int totalLoad = 0;

        for(const auto& trip: trips){
            int load = trip[0], start = trip[1], end = trip[2];
            while (!pq.empty() && pq.top().first <= start){
                auto [end, minLoad] = pq.top();
                pq.pop();

                totalLoad -= minLoad;
            }

            totalLoad += load;

            if(totalLoad > capacity){
                return false;
            }

            pq.push({end, load});
        }

        return true;
    }
};