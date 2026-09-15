class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //use vector adjaceny - vertices can be duplicate
        unordered_map<string, vector<string>> adj;
        for(auto& t: tickets){
            adj[t[0]].push_back(t[1]);
        }

        //sort each vector in descending order;
        for(auto& [u, list] : adj){
            sort(list.rbegin(), list.rend());
        }

        vector<string> route;
        function<void(string)> dfs = [&](string u){
            auto& list = adj[u];
            while(!list.empty()){
                string v = list.back();
                list.pop_back();
                dfs(v);
            }
            route.push_back(u);
        };

        dfs("JFK");
        reverse(route.begin(), route.end());

        return route;
    }
};
