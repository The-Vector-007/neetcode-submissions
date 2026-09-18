class Solution {
public:

    //kahn's algo
    vector<int> topologicalOrder(int n, vector<vector<int>> edges){
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for(auto e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> order;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            order.push_back(u);

            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        //reverse(order.begin(), order.end());

        if(order.size() != n){
            return {};
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowIndex = topologicalOrder(k, rowConditions);
        vector<int> colIndex = topologicalOrder(k, colConditions);

        if(rowIndex.empty() || colIndex.empty()){
            return {};
        }

        unordered_map<int, int> rowMap, colMap;
        for(int i = 0; i < rowIndex.size(); i++){
            rowMap[rowIndex[i]] = i;
        }

        for(int i = 0; i < colIndex.size(); i++){
            colMap[colIndex[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int val = 1; val <= k; val++){
            int i = rowMap[val];
            int j = colMap[val];
            ans[i][j] = val;
        }

        return ans;
    }
};