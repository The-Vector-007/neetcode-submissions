class Solution {
public:

    int find(int x, vector<int>& parent){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    bool unite(int a, int b, vector<int>& parent, vector<int>& sz){
        int ra = find(a, parent), rb = find(b, parent);
        if(ra == rb){
            return false;
        }

        //ra is always larger
        if(sz[ra] < sz[rb]){
            swap(ra, rb);
        }

        parent[rb] = ra;
        sz[ra] += sz[rb];

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), sz(n+1, 1);

        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }

        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            if(!unite(u, v, parent, sz)){
                return {u, v};
            }
        }

        return {};
    }

};
