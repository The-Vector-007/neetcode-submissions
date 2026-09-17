class Solution {
public:
    vector<int> parent, sz;
    const int INF = INT_MAX;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb) return false;

        if(sz[rb] > sz[ra]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }

    int kruskal(int n, vector<vector<int>>& edges, int skipEdge, int forceEdge){

        parent = vector<int>(n);
        sz = vector<int>(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        //sorting taken care of in parent function
        int cost = 0, used = 0;

        if(forceEdge != -1){
            for(auto e : edges){
                int u = e[0], v = e[1], w = e[2], idx = e[3];
                if(idx == forceEdge){
                    if(unite(u, v)){
                        cost += w;
                        used++;
                    }
                }
            }
        }

        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2], idx = e[3];

            if(idx == skipEdge || idx == forceEdge) continue;

            if(unite(u, v)){
                cost += w;
                used++;
            }
        } 

        return used == n - 1 ? cost : INF;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        //transform edges
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });


        vector<vector<int>> ans(2);

        int bestCost = kruskal(n, edges, -1, -1);

        if(bestCost == INF){
            return ans;
        }
        
        for(auto e: edges){

            int u = e[0], v = e[1], w = e[2], idx = e[3];

            //Exclude Test
            int skipCost = kruskal(n, edges, idx, -1);
            if(skipCost == INF || skipCost > bestCost){
                ans[0].push_back(idx);
                continue;
            }

            //Include Test
            int forceCost = kruskal(n, edges, -1, idx);
            if(forceCost == bestCost){
                ans[1].push_back(idx);
            }
        }

        return ans;
    }
};