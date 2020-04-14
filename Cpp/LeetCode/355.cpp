#include "usual.h"

struct Tweet {
    int time;
    int id;
    Tweet(int t, int i) : time(t), id(i) {}
};

bool operator<(const Tweet& t1, const Tweet& t2) {
    return t1.time > t2.time;
}

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : time(0) {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (tweets.find(userId) == tweets.end())
            tweets.insert({userId, list<Tweet>()});
        auto& l = tweets[userId];
        if (l.size() >= 10)
            l.pop_back();
        l.push_front(Tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        if (following.find(userId) == following.end())
            following.insert({userId, set<int>()});
        auto& fs = following[userId];
        priority_queue<Tweet> pq;
        for (auto p = fs.begin(); p != fs.end(); ++p) {
            if (tweets.find(*p) == tweets.end())
                tweets.insert({*p, list<Tweet>()});
            auto &l = tweets[*p];
            for (auto q = l.begin(); q != l.end(); ++q) {
                if (pq.size() < 10)
                    pq.push(*q);
                else if (q->time > pq.top().time) {
                    pq.pop();
                    pq.push(*q);
                }
            }
        }
        while (!pq.empty()) {
            v.push_back(pq.top().id);
            pq.pop();
        }
        return v;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (following.find(followerId) == following.end())
            following.insert({followerId, set<int>()});
        following[followerId].insert(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) == following.end())
            return;
        following[followerId].erase(followeeId);
    }
private:
    int time;
    unordered_map<int, set<int>> following;
    unordered_map<int, list<Tweet>> tweets;
};

int main(int argc, char const *argv[])
{
    Twitter twitter = Twitter();
    // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    twitter.postTweet(1, 5);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    twitter.getNewsFeed(1);

    // 用户1关注了用户2.
    twitter.follow(1, 2);

    // 用户2发送了一个新推文 (推文id = 6).
    twitter.postTweet(2, 6);

    // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
    // 推文id6应当在推文id5之前，因为它是在5之后发送的.
    twitter.getNewsFeed(1);

    // 用户1取消关注了用户2.
    twitter.unfollow(1, 2);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    // 因为用户1已经不再关注用户2.
    twitter.getNewsFeed(1);
    return 0;
}
