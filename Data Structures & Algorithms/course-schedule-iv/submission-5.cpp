class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<bool>> reachable(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            reachable[i][i] = true;
        }

        for(auto p : prerequisites){
            int u = p[0], v = p[1];
            reachable[u][v] = true;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(reachable[i][k] && reachable[k][j]){
                        reachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for(auto q : queries){
            int u = q[0], v = q[1];
            if(reachable[u][v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};