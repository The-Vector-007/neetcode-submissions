class Solution {
public:

    vector<int> parent, sz;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb){
            return false;
        }

        if(sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent = vector<int>(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        sz = vector<int>(n, 1);

        //email to account index
        unordered_map<string, int> emailMap;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(!emailMap.count(email)){
                    emailMap[email] = i;
                }
                else{
                    int prev = emailMap[email];
                    unite(prev, i);
                }
            }
        }

        //group by root
        unordered_map<int, set<string>> rootEmail;

        for(int i = 0; i < n; i++){
            int root = find(i);
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                rootEmail[root].insert(email);
            }
        }


        vector<vector<string>> ans;

        for(auto& [root, emailSet] : rootEmail){
            vector<string> merged;
            merged.push_back(accounts[root][0]);
            for(auto email : emailSet){
                merged.push_back(email);
            }
            ans.push_back(merged);
        }

        return ans;
    }
};