class Solution {
public:
    int waysToSplitArray(vector<int>& arr) {
        vector<long long> nums(arr.begin(),arr.end());
        int ans=0,n=nums.size();
        for(int i=1;i<n;i+=1){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n-1;i+=1){
            cout<<nums[i]<<" "<<nums[n-1]<<"\n";
            if(2*nums[i]>=nums[n-1])
            ans+=1;
        }
        return ans;
    }
};