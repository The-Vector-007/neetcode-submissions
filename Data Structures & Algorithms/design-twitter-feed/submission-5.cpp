class Twitter {
public:

    int clock = 0;
    unordered_map<int, unordered_set<int>> following; // key - user id, value - list of users whom user follows
    unordered_map<int, vector<pair<int, int>>> tweets; // key - user id, value - list of tweets {ts, tweetId} made by user

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({clock++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq;

        vector<int> ans;

        vector<int> relevantUsers;
        relevantUsers.push_back(userId);
        for(int followee : following[userId]){
            relevantUsers.push_back(followee);
        }

        for(int user : relevantUsers){
            if(tweets[user].size()){
                int lastIdx = tweets[user].size() - 1;
                auto [ts, tweetId] = tweets[user][lastIdx];
                pq.push({ts, tweetId, user, lastIdx});
            }
        }

        while(!pq.empty() && ans.size() < 10){
            auto [ts, tweetId, user, lastIdx] = pq.top();
            ans.push_back(tweetId);
            pq.pop();
            
            if(lastIdx > 0){
                int newIdx = lastIdx - 1;
                auto [ts, tweetId] = tweets[user][newIdx];
                pq.push({ts, tweetId, user, newIdx});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {

        if(followerId == followeeId){
            return;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return;
        }
        following[followerId].erase(followeeId);
    }
};
