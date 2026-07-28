class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return (a.second * a.second) + (a.first * a.first) < (b.second * b.second) + (b.first * b.first);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for(auto point : points){
            minHeap.push({point[0], point[1]});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while(minHeap.size()){
            ans.push_back({minHeap.top().first, minHeap.top().second});
            minHeap.pop();
        }

        return ans;
    }
};
