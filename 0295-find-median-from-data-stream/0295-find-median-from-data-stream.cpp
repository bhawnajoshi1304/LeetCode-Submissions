class MedianFinder {
public:
priority_queue<int> smaller;
priority_queue<int,vector<int>,greater<int>> larger;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        if(!larger.empty() && !smaller.empty() && smaller.top() > larger.top()) {
            larger.push(smaller.top());
            smaller.pop();
        }
        if(smaller.size() > larger.size()+1) {
            larger.push(smaller.top());
            smaller.pop();
        }
        if(larger.size() > smaller.size()+1) {
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if(larger.size() > smaller.size()) return larger.top();
        if(smaller.size() > larger.size()) return smaller.top();
        else return ( larger.top() + smaller.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */