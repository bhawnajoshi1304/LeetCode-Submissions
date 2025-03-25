
    bool comparex(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    bool comparey(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int ans=0;
        sort(rectangles.begin(),rectangles.end(),comparex);
        int cuts = 0, prev = -1;
        for(auto r: rectangles){
            if(r[0]>=prev) cuts++;
            prev=max(prev,r[2]);
        }
        if(cuts>=3) ans+=1;
        sort(rectangles.begin(),rectangles.end(),comparey);
        cuts = 0, prev = -1;
        for(auto r: rectangles){
            if(r[1]>=prev) cuts++;
            prev=max(prev,r[3]);
        }
        if(cuts>=3) ans+=1;
    return ans>0;
    }
};