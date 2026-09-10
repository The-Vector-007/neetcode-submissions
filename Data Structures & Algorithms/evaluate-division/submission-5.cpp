class Solution {
public:

    bool dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, bool>& visited, double product, double& result){

        if(src == dest){
            result = product;
            return true;
        }

        visited[src] = true;

        for(auto& [nei, w] : adj[src]){

            if(visited[nei])
                continue;

            if(dfs(nei, dest, adj, visited, product * w, result))
                return true;
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int idx = 0;
        for(auto& eq : equations){
            string u = eq[0], v = eq[1];
            double w = values[idx];
            double inv = 1.0 / w;
            cout << w << " " << inv << endl;
            adj[u].push_back({v, w});
            adj[v].push_back({u, inv});
            idx++;
        }

        for(auto [a, b] : adj){
            cout << a << " :";
            for(auto [v, w] : b){
                cout << "{" << v << " ," << w <<"}" << " ";
            }
            cout << endl;
        }

        vector<double> ans;

        for(auto q : queries){
            string u = q[0], v = q[1];
            if(!adj.count(u) || !adj.count(v)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_map<string, bool> visited;

            double result = -1.0;
            bool found = dfs(u, v, adj, visited, 1.0, result);

            if(found){
                ans.push_back(result);
            }
            else{
                ans.push_back(-1.0);
            }

        }

        return ans;
    }
};