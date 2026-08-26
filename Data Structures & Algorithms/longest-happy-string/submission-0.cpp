class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;

        priority_queue<pair<int, char>> pq;

        if(a){
            pq.push({a, 'a'});
        }

        if(b){
            pq.push({b, 'b'});
        }
        
        if(c){
            pq.push({c, 'c'});
        }
        
        while(!pq.empty()){
            auto [cnt, ch] = pq.top();
            pq.pop();

            //cout << cnt << " " << ch << endl;

            if(ans.size() < 2){
                ans.push_back(ch);
                cnt--;
            }
            else{
                int sz = ans.size();
                string lastTwo;
                lastTwo.push_back(ans[sz-1]);
                lastTwo.push_back(ans[sz-2]);
                string gate;
                gate.append(3, ch);

                //cout << lastTwo << endl;
                //cout << gate << endl;

                if(ch + lastTwo == gate){
                    
                    if(pq.empty()){
                        return ans;
                    }

                    auto [nxtCnt, nxtCh] = pq.top();
                    pq.pop();

                    ans.push_back(nxtCh);
                    nxtCnt--;
                    if(nxtCnt){
                        pq.push({nxtCnt, nxtCh});
                    }
                }
                else{
                    ans.push_back(ch);
                    cnt--;
                }
            }

            if(cnt){
                pq.push({cnt, ch});
            }
        }

        return ans;
    }
};