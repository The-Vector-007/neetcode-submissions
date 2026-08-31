class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> combined;
        int n = max(profits.size(), capital.size());
        for(int i = 0; i < n; i++){
            combined.push_back({capital[i], profits[i]});
        }

        sort(combined.begin(), combined.end());

        int totalCapital = w;
        int ans = w;

        priority_queue<int> pq;

        for(int i = 0; i < combined.size(); i++){
            auto [requiredCapital, pureProfit] = combined[i];
            if(requiredCapital <= totalCapital){
                pq.push(pureProfit);
            }
            else{

                if(pq.empty()){
                    return ans;
                }

                int maxProfit = pq.top();
                pq.pop();
                ans += maxProfit;
                totalCapital += maxProfit;
                k--;

                if(requiredCapital <= totalCapital){
                    pq.push(pureProfit);
                } 
            }

            if(k == 0){
                break;
            }
        }

        while(!pq.empty() && k){
            if(k){
                ans += pq.top();
                pq.pop();
                k--;
            }
        }

        return ans;
    }
};