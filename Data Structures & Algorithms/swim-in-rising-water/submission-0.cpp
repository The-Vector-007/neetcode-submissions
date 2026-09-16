class Solution {
public:

    bool isSafe(int i, int j, int n){
        if(i < 0 || i > n-1 || j < 0 || j > n-1){
            return false;
        }
        return true;
    }

    //pattern - BFS + min heap greedy
    int swimInWater(vector<vector<int>>& grid) {
       int n  = grid.size();
       if(!n){
        return 0;
       }

       vector<int> di = {1, -1, 0, 0};
       vector<int> dj = {0, 0, -1, 1};

       vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
       dist[0][0] = grid[0][0];

       using P = tuple<int, int, int>;
       priority_queue<P, vector<P>, greater<P>> pq;
       pq.push({grid[0][0], 0, 0});

       while(!pq.empty()){
        auto [maxSoFar, i, j] = pq.top();
        pq.pop();

        if(maxSoFar > dist[i][j]){
            continue;
        }

        if(i == n-1 && j == n-1){
            break;
        }

        for(int k = 0; k < 4; k++){
            int ni = i + di[k], nj = j + dj[k];
            if(isSafe(ni, nj, n)){
                int candidate = max(maxSoFar, grid[ni][nj]);
                if(candidate < dist[ni][nj]){
                    dist[ni][nj] = candidate;
                    pq.push({candidate, ni, nj});
                }
            }
        }
       }

       return dist[n-1][n-1];
    }
};
