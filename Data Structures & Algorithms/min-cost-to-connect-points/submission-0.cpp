class Solution {
public:

    vector<int> parent, sz;

    int manhattanDistance(vector<int> p1, vector<int> p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb) return false;

        if(ra < rb) swap(ra, rb);

        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        parent = vector<int>(n);
        sz = vector<int>(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        vector<array<int, 3>> edges;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int w = manhattanDistance(points[i], points[j]);
                edges.push_back({w, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int cost = 0, used = 0;

        for(auto [w, u, v] : edges){
            if(unite(u, v)){
                cost += w;
                used++;
            }
        }

        return used == n-1 ? cost : -1;
    }
};
