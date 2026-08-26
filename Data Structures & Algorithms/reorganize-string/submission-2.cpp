class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }

        int maxFreq = (n + 1) / 2;

        priority_queue<pair<int, char>> pq;

        for(auto& [ch, count] : freq){
            if(count > maxFreq){
                return "";
            }

            pq.push({count, ch});
        }

        string ans;

        while(!pq.empty()){
            auto [count, ch] = pq.top();
            pq.pop();

            if(ans.empty()){
                ans.push_back(ch);
                count--;
            }
            else{
                char prevChar = ans.back();
                if(ch == prevChar){
                    auto [nxtCount, nxtCh] = pq.top();
                    pq.pop();
                    ans.push_back(nxtCh);

                    nxtCount--;
                    if(nxtCount){
                        pq.push({nxtCount, nxtCh});
                    }

                }
                else{
                    ans.push_back(ch);
                    count--;
                }
            }
            
            if(count){
                pq.push({count, ch});
            }
        }

        return ans;
    }
};