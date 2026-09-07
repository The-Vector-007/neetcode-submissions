class Solution {
public:

    void dfs(int src, int parent, vector<vector<int>>& adj, vector<bool>& visited, bool& hasCycle){
        visited[src] = true;
        for(int x : adj[src]){

            if(!visited[x]){
                dfs(x, src, adj, visited, hasCycle);
            }
            else if(x != parent){
                hasCycle = true;
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(n <= 1){
            return true;
        }

        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        unordered_map<int, int> parent;
        bool hasCycle = false;
        
        dfs(0, -1, adj, visited, hasCycle);

        for(bool check : visited){
            if(!check){
                return false;
            }
        }

        return !hasCycle;
    }
};
