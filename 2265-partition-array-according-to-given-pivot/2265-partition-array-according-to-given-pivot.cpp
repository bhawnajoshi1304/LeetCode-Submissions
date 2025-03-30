class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left =0,right=nums.size()-1,mid=nums.size()-1;
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i+=1){
            if(nums[i]<pivot){
                result[left++] = nums[i];
            }else if(nums[i]==pivot){
                result[mid--] = pivot;
            }else{
                result[mid--]=result[right];
                result[right--] = nums[i];
            }
        }
        reverse(result.begin()+right+1,result.end());
        return result;
    }
};