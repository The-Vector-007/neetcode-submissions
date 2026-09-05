class Solution {
public:

    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n-1 || j < 0 || j > m-1){
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<bool>>& visited){
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int ni = i + di[k], nj = j + dj[k];
            if(isSafe(ni, nj, n, m) && board[ni][nj] == 'O' && !visited[ni][nj]){
                dfs(ni, nj, n, m, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(auto r : {0, n-1}){
            for(int c = 0; c < m; c++){
                if(board[r][c] == 'O' && !visited[r][c]){
                    dfs(r, c, n, m, board, visited);
                }
            }
        }

        for(auto c : {0, m-1}){
            for(int r = 0; r < n; r++){
                if(board[r][c] == 'O' && !visited[r][c]){
                    dfs(r, c, n, m, board, visited);
                }
            }
        }

        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
