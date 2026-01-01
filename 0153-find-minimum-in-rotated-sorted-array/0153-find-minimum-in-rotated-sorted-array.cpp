class Solution {
public:
    int findMin(vector<int>& a) {
        int low =0,high=a.size()-1,mid;
        if(a[low]<=a[high]) return a[0];
        while(low<high){
            mid = low+(high-low)/2;
            if(a[mid]>a[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return a[low];
    }
};