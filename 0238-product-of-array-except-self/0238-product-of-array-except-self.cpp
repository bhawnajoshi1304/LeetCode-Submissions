class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size(),p=1;
        vector<int> left(n,1), right(n,1),ans(n);
        for(int i=1;i<n;i+=1){
            left[i]=p*nums[i-1];
            p=left[i];
        }
        p=1;
        for(int i=n-2;i>=0;i-=1){
            right[i]=p*nums[i+1];
            p=right[i];
        }
        for(int i=0;i<n;i+=1){
            ans[i] = left[i]*right[i];
        }
        return ans;
    }
};