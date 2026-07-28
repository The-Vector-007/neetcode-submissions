class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char ch : tasks){
            mp[ch]++;
        }

        priority_queue<int> maxHeap;
        for(auto p : mp){
            maxHeap.push(p.second);
        }

        int t = 0;
        queue<pair<int, int>> cooldown;

        while(!maxHeap.empty() || !cooldown.empty()){
            t++;

            if(!maxHeap.empty()){
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0){
                    cooldown.push({cnt, t + n});
                }
            }

            if(!cooldown.empty() && cooldown.front().second == t){
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return t;
    }
};
