class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> degree;

        for(auto edge : trust){ 
            int u = edge[0], v = edge[1];
            degree[u]--;
            degree[v]++;
        }

        for(auto& [label, deg] : degree){
            if(deg == n - 1){
                return label;
            }
        }

        return -1;
    }
};