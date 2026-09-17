class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int step = 1; step <= k + 1; step++){
            vector<int> next = dist;
            for(auto f : flights){
                int u = f[0], v = f[1], w = f[2];
                if(dist[u] == INT_MAX) continue;
                next[v] = min(next[v], dist[u] + w);
            }
            dist = next;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
