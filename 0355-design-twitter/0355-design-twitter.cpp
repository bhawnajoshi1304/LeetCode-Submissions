class Twitter {
public:
    unordered_map<int,priority_queue<pair<int,int>>> tweet;
    unordered_map<int,set<int>> followers;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        cout<<"****\n";
        priority_queue<pair<int,int>> pq;
        get10(pq,tweet[userId]);
        for(auto i:followers[userId]){
            get10(pq,tweet[i]);
        }
        vector<int> nf;
        int c=10;
        while(!pq.empty() && c>0){
            nf.push_back(pq.top().second);
            c--;
            pq.pop();
        }
        return nf;
    }
    void get10(priority_queue<pair<int,int>>& pq,priority_queue<pair<int,int>> &t){
        int c=0;
        vector<pair<int,int>> temp;
        while(!t.empty() && c<10){
            pq.push(t.top());
            temp.push_back(t.top());
            cout<<t.top().first<<" "<<t.top().second<<"\n";
            t.pop();
            c++;
        }
        while(temp.size()>0){
            t.push(temp.back());
            temp.pop_back();
        }
        // while(pq.size()>10){
        //     pq.pop();
        // }return pq;
    }
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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