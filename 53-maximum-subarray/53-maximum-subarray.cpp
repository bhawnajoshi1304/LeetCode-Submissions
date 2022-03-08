class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int curr=nums[0];
        for(int i=1;i<nums.size();i+=1){
            if(curr<0) curr=nums[i];
            else if(curr+nums[i]>0)
                curr+=nums[i];
            else
                curr=nums[i];
            cout<<curr<<" ";
            sum=max(sum,curr);
        }
        return sum;
    }
};