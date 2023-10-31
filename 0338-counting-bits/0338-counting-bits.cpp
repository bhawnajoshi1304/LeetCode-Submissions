class Solution {
public:
    static int countSetBits(int n)
    {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i+=1){
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};