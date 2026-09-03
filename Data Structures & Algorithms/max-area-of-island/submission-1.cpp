class Solution {
public:
// up - i-- | down i++ | left j-- | right j++
    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return false;
        }
        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area){
        area++;
        visited[i][j] = true;
        int n = grid.size(), m = grid[0].size();
        for(int k = 0; k < 4; k++){
            int n_i = i + di[k], n_j = j + dj[k];
            if(isSafe(n_i, n_j, n, m) && grid[n_i][n_j] == 1 && !visited[n_i][n_j]){
                dfs(n_i, n_j, grid, visited, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 0){
            return -1;
        }

        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int area = 0;
                    dfs(i, j, grid, visited, area);
                    if(area > maxArea){
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }
};
