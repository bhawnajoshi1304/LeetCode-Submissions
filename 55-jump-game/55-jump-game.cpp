class Solution {
public:
    int min(int a,int b){
        if(a<b) return a;
        return b;
    }
    int max(int a,int b){
        if(a>b) return a;
        return b;
    }
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; idx < nums.size() && idx <= i; ++idx)
            i = max(idx + nums[idx], i);
        return idx == nums.size();
    }
};