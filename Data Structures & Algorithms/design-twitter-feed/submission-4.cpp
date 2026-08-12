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
        vector<int> ans;
        vector<pair<int, int>> feed;
        vector<vector<pair<int, int>>> feeds;

        unordered_set<int> userFollowees = following[userId];
        for(int followee : userFollowees){
            if(followee != userId){
                feeds.push_back(tweets[followee]);
            }
        }

        feeds.push_back(tweets[userId]);

        for(auto v : feeds){
            for(auto p : v){
                feed.push_back(p);
            }
        }

        sort(feed.begin(), feed.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int cnt = 1;
        for(auto p : feed){
            if(cnt > 10){
                break;
            }
            ans.push_back(p.second);
            cnt++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
