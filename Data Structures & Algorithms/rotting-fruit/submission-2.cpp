class Solution {
public:

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return false;
        }

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};

        queue<tuple<int, int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        int ans = 0;

        while(!q.empty()){
            auto [i, j, d] = q.front();
            q.pop();

            ans = max(ans, d);
            d++;

            for(int k = 0; k < 4; k++){
                int n_i = i + di[k], n_j = j + dj[k];
                if(isSafe(n_i, n_j, n, m) && !visited[n_i][n_j] && grid[n_i][n_j] == 1){
                    visited[n_i][n_j] = true;
                    grid[n_i][n_j] = 2;
                    q.push({n_i, n_j, d});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
