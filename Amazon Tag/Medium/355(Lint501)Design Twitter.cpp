#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

1.postTweet(userId, tweetId): Compose a new tweet.
2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3.follow(followerId, followeeId): Follower follows a followee.
4.unfollow(followerId, followeeId): Follower unfollows a followee.
*/


//Lint Version
class Node
{
  public:
    int order;
    Tweet tweet;
    Node(int o, Tweet t)
    {
        order = o, tweet = t;
    }

    bool operator<(const Node &o) const
    {
        return order > o.order;
    }
};

class MiniTwitter {
public:
    map<int, set<int>> friends;
    map<int, vector<Node>> users_tweets;
    int order;
    
    
    MiniTwitter() {
        // do intialization if necessary
        order = 0;
        friends.clear();
        users_tweets.clear();
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        // write your code here
        Tweet newTweet = Tweet::create(user_id, tweet_text);
        
        if (users_tweets.find(user_id) == users_tweets.end())
            users_tweets[user_id] = vector<Node>();
        
        users_tweets[user_id].push_back(Node(order,newTweet));
        
        order++;
        
        return newTweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
     

    vector<Tweet> getNewsFeed(int user_id) {
        // write your code here
        
        vector<Node> temp;
        
        if(users_tweets.find(user_id)!=users_tweets.end()){
            temp = getTen(users_tweets[user_id]);
        }
        
        if(friends.find(user_id)!=friends.end()){
            for(auto user : friends[user_id]){
                if(users_tweets.find(user)!=users_tweets.end()){
                    vector<Node> friendTweets = getTen(users_tweets[user]);
                    
                    for(auto item : friendTweets){
                        temp.push_back(item);
                    }
                }
            }
        }
        
        
        sort(temp.begin(),temp.end());
        
        vector<Tweet> result;
        
        for (int i = 0; i < temp.size(); ++i){
            if (i >= 10)
                break;
            result.push_back(temp[i].tweet);
        }
        
        return result;
    }
    
    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        // write your code here
        
        vector<Tweet> result;
        
        if(users_tweets.find(user_id)==users_tweets.end()){
            return result;
        }
        
        vector<Node> temp = getTen(users_tweets[user_id]);
        
        sort(temp.begin(),temp.end());
        
        int count = 0;
        
        for(auto item : temp){
            count++;
            if(count>10){
                break;
            }
            result.push_back(item.tweet);
        }
        
        return result;
        
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        // write your code here
        // Write your code here
        friends[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        // write your code here
        if (friends.find(from_user_id) == friends.end())
            return;
        friends[from_user_id].erase(to_user_id);
    }
    
    vector<Node> getTen(vector<Node> &tmp)
    {
        int count = 0;
        vector<Node> v1;
        int n = tmp.size();
        for (int i = n - 1; i >= 0; --i)
        {
            count += 1;
            v1.push_back(tmp[i]);
            if (count >= 10)
                break;
        }
        return v1;
    }
};


//Leet Version

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        friends.clear();
        users_tweets.clear(); 
        order;
    }
    
    class Node
    {
      public:
        int order;
        int tweetId;
        Node(int o, int t)
        {
            order = o;
            tweetId = t;
        }

        bool operator<(const Node &o) const
        {
            return order > o.order;
        }
    };
    
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users_tweets[userId].push_back(Node(order,tweetId));
        order++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        vector<int> result;
        
        vector<Node> tweets;
        
        if(users_tweets.find(userId)!=users_tweets.end()){
            tweets = users_tweets[userId];
        }
        
        if(friends.find(userId) != friends.end()){
            for(auto user : friends[userId]){
                
                if(users_tweets.find(user)!=users_tweets.end()){
                    vector<Node> temp = users_tweets[user];
                    
                    for(auto item : temp){
                        tweets.push_back(item);
                    }
                }
                
            }
        }
        
        
        sort(tweets.begin(),tweets.end());
        
        while(tweets.size()>10){
            tweets.pop_back();
        }
        
        for(auto item : tweets){
            result.push_back(item.tweetId);
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            friends[followerId].insert(followeeId);
        }
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (friends.find(followerId) == friends.end())
            return;
        friends[followerId].erase(followeeId);        
    }
    
    map<int, set<int>> friends;
    map<int, vector<Node>> users_tweets;
    int order;
};