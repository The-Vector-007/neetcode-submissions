class Solution {
public:
    bool dfs(char node,
             unordered_map<char, int> &state,
             unordered_map<char, vector<char>> &adj,
             string &order) {
        state[node] = 1; // visiting
        for (char nei : adj[node]) {
            if (state[nei] == 1) return false;          // cycle
            if (state[nei] == 0 && !dfs(nei, state, adj, order))
                return false;
        }
        state[node] = 2; // visited
        order.push_back(node);
        return true;
    }

    string foreignDictionary(vector<string> &words) {
        if (words.empty()) return "";

        // 1. Collect all unique characters
        unordered_set<char> allChars;
        for (auto &w : words)
            for (char c : w) allChars.insert(c);

        // 2. Build adjacency list
        unordered_map<char, vector<char>> adj;
        for (char c : allChars) adj[c] = {};

        for (int i = 0; i < (int)words.size() - 1; i++) {
            string &first = words[i];
            string &second = words[i + 1];
            int len = min(first.size(), second.size());
            int j = 0;
            while (j < len && first[j] == second[j]) j++;
            if (j < len) {
                adj[first[j]].push_back(second[j]);
            } else {
                // invalid if second is prefix of first
                if (second.size() < first.size()) return "";
            }
        }

        // 3. Topological sort with cycle detection
        unordered_map<char, int> state; // 0=unvisited,1=visiting,2=visited
        for (char c : allChars) state[c] = 0;

        string order;
        for (char c : allChars) {
            if (state[c] == 0) {
                if (!dfs(c, state, adj, order)) return ""; // cycle
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};