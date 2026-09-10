class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1){
            return {0};
        }

        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            degree[v]++;
            degree[u]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            cout << i << " :" << degree[i] << endl;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        int remainingNodes = n;

        while(remainingNodes > 2){

            int sz = q.size();

            for(int i = 0; i < sz; i++){
                int leafNode = q.front();
                q.pop();

                for(int x : adj[leafNode]){
                    degree[x]--;
                    if(degree[x] == 1){
                        q.push(x);
                    }
                }   
            }     

            remainingNodes -= sz;   
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};