class SeatManager {
public:
    priority_queue<int> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i+=1)
        pq.push(-i);
    }
    
    int reserve() {
        int ans=-1*pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(-1*seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */