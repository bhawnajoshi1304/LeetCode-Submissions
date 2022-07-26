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
    int jump(vector<int>& nums) {
        vector<int> can(nums.size(),INT_MAX);
        can[0]=0;
        for(int i=0;i<nums.size();i+=1){
            for(int j=i+1;j<min(nums.size(),i+nums[i]+1);j+=1){
                can[j]=min(can[j],can[i]+1);
        }
        }
        return can[nums.size()-1];
    }
};