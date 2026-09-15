class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, INT_MAX);
        k--;
        dis[k] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for(auto& time: times){
            int u = time[0], v = time[1], t = time[2];
            u--;
            v--;
            adj[u].push_back({v, t});
        }

        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({k, 0});

        while(!pq.empty()){
            auto [u, d] = pq.top();
            pq.pop();

            if(d > dis[u]){
                continue;
            }

            for(auto& [v, w] : adj[u]){
                if(d + w < dis[v]){
                    dis[v] = d + w;
                    pq.push({v, dis[v]});
                }
            }
        }

        int ans = *max_element(dis.begin(), dis.end());

        return ans == INT_MAX ? -1 : ans;
    }
};
