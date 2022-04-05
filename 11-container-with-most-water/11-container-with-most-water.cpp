class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),l=0,r=n-1;
        int m=min(height[0],height[n-1])*(n-1);
        while(l<r){
            if(height[l]<height[r])
                l+=1;
            else
                r-=1;
            m=max(m,min(height[l],height[r])*(r-l));
        }
        return m;
    }
};