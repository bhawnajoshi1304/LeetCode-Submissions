class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for (int i = nums.size() - 1; i >= 0; --i){
            if(s.find(nums[i])!=s.end()){
                return (i+3)/3;
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};