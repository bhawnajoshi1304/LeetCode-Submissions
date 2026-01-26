class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans= INT_MAX;
        for(int i=k-1;i<nums.size();i+=1)
        ans=min(ans,nums[i]-nums[i-k+1]);
        return ans==INT_MAX?0:ans;
    }
};