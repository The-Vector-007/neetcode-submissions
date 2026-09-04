class Solution {
public:

    const int INF = 2147483647;
    // up - i-- | down - i++ | left - j-- | right - j++
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return false;
        }
        return true;
    }

    void bfs(int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        queue<tuple<int, int, int>> q;

        for(int a = 0; a < n; a++){
            for(int b = 0; b < m; b++){
                if(grid[a][b] == 0){
                    q.push({a, b, 0});
                }
            }
        }
        
        while(!q.empty()){
            auto [x, y, d] = q.front();
            q.pop();

            if(d < grid[x][y]){
                grid[x][y] = d;
            }

            d++;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(isSafe(nx, ny, n, m) && grid[nx][ny] > 0 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny, d});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return;
        }

        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        bfs(n, m, grid, visited);

    }
};
