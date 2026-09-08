class Solution {
public:

    void dfs(int src, vector<int> adj[], vector<bool>& visited){
        visited[src] = true;
        for(int dest: adj[src]){
            if(!visited[dest]){
                dfs(dest, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};
