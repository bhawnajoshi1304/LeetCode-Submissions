class Solution {
public:
    static int heightChecker(vector<int>& heights) {
        // reuse heights, no other container
        const int n=heights.size();
        for(int i=0; i<n; i++)//pack value for heights[i] & i in an int
            heights[i]=(heights[i]<<8)+i;
        sort(heights.begin(), heights.end());
        int ans=0;
        for(int i=0; i<n; i++){
            //unpack heights[i] & index j. check if heights[j]==heights[i]
            ans+=(heights[(heights[i]&255)]>>8!=heights[i]>>8);
        }
        return ans;
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();