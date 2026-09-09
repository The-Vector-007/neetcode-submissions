class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& sz) {
        int ra = find(a, parent);
        int rb = find(b, parent);
        if (ra == rb) return;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), sz(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;

        // Map email -> account index
        unordered_map<string, int> emailToIndex;

        // 1) Build DSU
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < (int)accounts[i].size(); ++j) {
                string &email = accounts[i][j];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = i;
                } else {
                    int prev = emailToIndex[email];
                    unite(prev, i, parent, sz);
                }
            }
        }

        // 2) Group emails by root
        unordered_map<int, set<string>> rootEmails;
        for (int i = 0; i < n; ++i) {
            int root = find(i, parent);
            for (int j = 1; j < (int)accounts[i].size(); ++j) {
                rootEmails[root].insert(accounts[i][j]);
            }
        }

        // 3) Build result
        vector<vector<string>> ans;
        for (auto &p : rootEmails) {
            int root = p.first;
            auto &emails = p.second;
            vector<string> merged;
            merged.push_back(accounts[root][0]); // name
            for (auto &email : emails) {
                merged.push_back(email);
            }
            ans.push_back(move(merged));
        }

        return ans;
    }
};