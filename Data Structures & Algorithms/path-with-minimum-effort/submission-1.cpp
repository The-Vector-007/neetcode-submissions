class Solution {
public:

    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || i > n-1 || j < 0 || j > m-1){
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.empty()){
            return -1;
        }
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> bestEffort(n, vector<int>(m, INT_MAX));
        bestEffort[0][0] = 0;

        using P = tuple<int, int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> di = {1, -1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};

        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto [currentEffort, i, j] = pq.top();
            pq.pop();

            if(currentEffort > bestEffort[i][j]){
                continue;
            }

            for(int k = 0; k < 4; k++){
                int ni = i + di[k], nj = j + dj[k];
                if(isSafe(ni, nj, n, m)){
                    int candidateEffort = max(currentEffort, abs(heights[ni][nj] - heights[i][j]));
                    if(candidateEffort < bestEffort[ni][nj]){
                        bestEffort[ni][nj] = candidateEffort;
                        pq.push({candidateEffort, ni, nj});
                    }
                }
            }
        }

        return bestEffort[n-1][m-1];
    }
};