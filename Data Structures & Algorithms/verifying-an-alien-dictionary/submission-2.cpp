class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orderMap;
        for(int i = 0; i < order.size(); i++){
            orderMap[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++){
            string first = words[i];
            string second = words[i+1];

            int j;
            for(j = 0; j < min(first.size(), second.size()); j++){
                int pos_first = orderMap[first[j]];
                int pos_second = orderMap[second[j]];

                if(pos_first < pos_second){
                    break;
                }

                if(pos_first > pos_second){
                    return false;
                }
            }

            if(j == second.size() && first.substr(0, j) == second.substr(0, j) && first.size() > second.size()){
                return false;
            }
        }

        return true;
    }
};