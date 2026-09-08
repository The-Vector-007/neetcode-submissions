class Solution {
public:

    vector<string> get_neighbors(string s){
        vector<string> ans;
        
        for(int i = 0; i < 4; i++){
            string t1 = s;
            string t2 = s;

            t1[i] = (s[i] == '9') ? '0' : s[i] + 1;
            ans.push_back(t1);

            t2[i] = (s[i] == '0') ? '9' : s[i] - 1;
            ans.push_back(t2);
        }

        return ans;
    }

    int openLock(vector<string>& deadends, string target) {

        unordered_map<string, bool> visited;
        for(string s : deadends){
            visited[s] = true;
        }

        string start = "0000";

        if(visited[start]){
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while(!q.empty()){
            auto [s, moves] = q.front();
            q.pop();

            if(s == target){
                return moves;
            }

            vector<string> neighbors = get_neighbors(s);
            for(string neighbor: neighbors){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, moves + 1});
                }
            }
        }

        return -1;
    }
};