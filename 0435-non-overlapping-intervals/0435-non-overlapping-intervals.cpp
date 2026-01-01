class Solution {
public:
  static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int it=intervals[0][1],c=0;
        cout<<it<<" ";
        for(int i=0;i<intervals.size()-1;i+=1){
            if(it>intervals[i+1][0]){
                c+=1;
                it = min(it, intervals[i+1][1]); // keep best of 2
            }else{
                it=intervals[i+1][1];
                cout<<it<<" ";
            }
        }
        return c;
    }
};