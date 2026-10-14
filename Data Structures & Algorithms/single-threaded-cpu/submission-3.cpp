class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n_tasks = tasks.size();

        if(!n_tasks){
            return {};
        }

        for(int t_idx = 0; t_idx < n_tasks; t_idx++){
            tasks[t_idx].push_back(t_idx);
        }

        sort(tasks.begin(), tasks.end());

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> ans;

        int idx = 0;
        int currentTime = 0;

        while(idx < n_tasks || !pq.empty()){

            //execute active tasks and update current time
            if(!pq.empty()){
                auto [pt, i] = pq.top();
                pq.pop();

                ans.push_back(i);

                currentTime += pt;
            }
            else{
                currentTime = max(currentTime, tasks[idx][0]);
            }

            //get active tasks as per current time
            while(idx < n_tasks && tasks[idx][0] <= currentTime){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
        }

        return ans;
    }
};