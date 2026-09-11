class Solution {
public:

    vector<string> get_neighbors(string word, unordered_set<string>& wordSet){
        vector<string> neighbors;
        int start = 97;

        for(int charIdx = 0; charIdx < word.size(); charIdx++){
            string tempWord = word;
            for(int i = start; i <= start + 25; i++){
                char ch = char(i);
                if(word[charIdx] != ch){
					tempWord[charIdx] = ch;
					if(wordSet.count(tempWord)){
						neighbors.push_back(tempWord);
					}
				}
            }
        }

        return neighbors;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for(auto word : wordList){
            wordSet.insert(word);
        }

        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;
        q.push({beginWord, 1});
        visited[beginWord] = true;

        while(!q.empty()){
            auto [currWord, distance] = q.front();
            q.pop();

            if(currWord == endWord){
                return distance;
            }

            vector<string> neighbors = get_neighbors(currWord, wordSet);

            for(string neighbor: neighbors){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    wordSet.erase(neighbor);
                    q.push({neighbor, distance + 1});
                }
            }
        }

        return 0;
    }
};
