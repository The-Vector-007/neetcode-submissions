class Solution {
public:

    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n -1 || j < 0 || j > m - 1){
            return false;
        }
        return true;
    }

    bool isPacific(int i, int j){
        if(i == 0 || j == 0){
            return true;
        }

        return false;
    }

    bool isAtlantic(int i, int j, int n, int m){
        if(i == n - 1 || j == m - 1){
            return true;
        }

        return false;
    }

    void dfs(int i, int j, int n, int m, vector<vector<bool>>& visited, vector<vector<int>>& heights, bool& atlantic, bool& pacific){
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int n_i = i + di[k], n_j = j + dj[k];
            if(isSafe(n_i, n_j, n, m) && heights[i][j] >= heights[n_i][n_j] && !visited[n_i][n_j]){
                atlantic |= isAtlantic(n_i, n_j, n, m);
                pacific |= isPacific(n_i, n_j);
                dfs(n_i, n_j, n, m, visited, heights, atlantic, pacific);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n == 0){
            return {};
        }

        int m = heights[0].size();

        vector<vector<int>> ans;

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                bool atlantic = isAtlantic(i, j, n, m);
                bool pacific  = isPacific(i, j);
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(i, j, n, m, visited, heights, atlantic, pacific);
                if(atlantic && pacific){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
