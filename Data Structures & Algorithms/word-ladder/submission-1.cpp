class Solution {
private:
    vector<string> getNeighbors(string w, unordered_set<string>& wordSet) {
        vector<string> neighbors;
        for (int i = 0; i < w.size(); i++) {
            char original = w[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                w[i] = c;
                if (wordSet.find(w) != wordSet.end()) {
                    neighbors.push_back(w);
                }
            }
            w[i] = original;
        }
        return neighbors;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<string> queueBegin, queueEnd;
        unordered_set<string> visitedBegin, visitedEnd;
        
        queueBegin.push(beginWord);
        queueEnd.push(endWord);
        visitedBegin.insert(beginWord);
        visitedEnd.insert(endWord);
        
        int transformCount = 1;

        while (!queueBegin.empty() && !queueEnd.empty()) {
            if (queueBegin.size() > queueEnd.size()) {
                swap(queueBegin, queueEnd);
                swap(visitedBegin, visitedEnd);
            }

            int size = queueBegin.size();
            for (int i = 0; i < size; i++) {
                string word = queueBegin.front();
                queueBegin.pop();
                
                vector<string> neighbors = getNeighbors(word, wordSet);
                for (string neighbor : neighbors) {
                    // Check intersection with opposite direction
                    if (visitedEnd.find(neighbor) != visitedEnd.end()) {
                        return transformCount + 1;
                    }
                    
                    // Add to current BFS if not visited
                    if (visitedBegin.find(neighbor) == visitedBegin.end()) {
                        queueBegin.push(neighbor);
                        visitedBegin.insert(neighbor);
                    }
                }
            }
            transformCount++;
        }
        return 0;
    }
};