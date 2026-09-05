class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(int y : adj[x]){
                indegree[y]--;

                if(indegree[y] == 0){
                    q.push(y);
                }
            }
        }

        for(int x : indegree){
            if(x){
                return false;
            }
        }

        return true;
    }
};
