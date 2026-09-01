class Solution {
public:

    vector<int> dj = {1, 0, -1, 0};
    vector<int> di = {0, 1, 0, -1};
    vector<vector<bool>> visited;

    bool isSafe(int i, int j, int r, int c){
        if(i < 0 || i > r-1 || j < 0 || j > c-1){
            return false;
        }

        return true;
    }

    int calculatePerimeter(int i, int j, int r, int c, vector<vector<int>>& grid){
        int ans = (i-1 < 0) + (j - 1 < 0) + (i + 1 == r) + (j + 1 == c);
        for(int d = 0; d < 4; d++){
            if(isSafe(i + di[d], j + dj[d], r, c) && grid[i + di[d]][j + dj[d]] == 0){
                ans += 1;
            }
        }
        return ans;
    }

    void dfs(int i, int j, int r, int c, int& ans, vector<vector<int>>& grid){
        visited[i][j] = true;
        for(int d = 0; d < 4; d++){
            int new_i = di[d] + i, new_j = dj[d] + j;
            if(isSafe(new_i, new_j, r, c) && grid[new_i][new_j] && !visited[new_i][new_j]){
                ans += calculatePerimeter(new_i, new_j, r, c, grid);
                dfs(new_i, new_j, r, c, ans, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    ans += calculatePerimeter(i, j, n, m, grid);
                    dfs(i, j, n, m, ans, grid);
                }
            }
        }

        return ans;
    }
};