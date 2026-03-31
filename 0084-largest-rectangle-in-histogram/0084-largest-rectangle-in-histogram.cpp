class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size(),ans=0;
        for(int i=0;i<=n;i+=1){
            int h= (i==n)?0:heights[i];
            while(!s.empty() && h<heights[s.top()]){
                int he=heights[s.top()];
                s.pop();
                int w=s.empty()?i:i-s.top()-1;;
                ans=max(ans,he*w);
            }
            s.push(i);
        }
        return ans;
    }
};