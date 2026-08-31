class Twitter {
    int timestamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap; // {time, tweetId}

        auto addUser = [&](int uid) {
            auto& t = tweets[uid];
            for (int i = max(0, (int)t.size() - 10); i < t.size(); i++)
                maxHeap.push(t[i]);
        };

        addUser(userId);
        for (int f : following[userId]) addUser(f);

        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */