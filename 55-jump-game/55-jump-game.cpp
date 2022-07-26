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
        vector<bool> can(nums.size(),false);
        can[0]=true;
        int tmp=0;
        for(int i=0;i<nums.size();i+=1){
            for(int j=max(tmp,i+1);j<min(nums.size(),i+nums[i]+1);j+=1){
                tmp=j;
                can[j]=can[i];
        }
        }
        return can[nums.size()-1];
    }
};