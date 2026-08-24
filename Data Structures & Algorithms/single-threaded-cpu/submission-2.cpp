class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int idx = 0;
        long long currentTime = 0;
        int idxLimit = tasks.size();

        vector<int> ans;

        while(idx < idxLimit || !pq.empty()){
            if(!pq.empty()){
                auto [processingTime, originalIdx] = pq.top();
                pq.pop();
                ans.push_back(originalIdx);
                currentTime += processingTime;
            }
            else{
                currentTime = max(currentTime, (long long)tasks[idx][0]);
            }

            while(idx < idxLimit && tasks[idx][0] <= currentTime){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
        }

        return ans;
    }
};