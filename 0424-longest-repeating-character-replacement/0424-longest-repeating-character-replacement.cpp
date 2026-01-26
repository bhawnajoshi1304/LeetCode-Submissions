class Solution {
public:
    int mostFreq(map<char,int> &mp){
        int ans=0;
        for(auto i:mp){
            ans=max(ans,i.second);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, mf = 0, ans = 0;
        map<char, int> m;
        while (right < s.size()) {
            if (right >= left) {
                m[s[right]] += 1;
                if (m[s[right]] > mf) {
                    mf = m[s[right]];
                }
                while (right + 1 - left - mf > k) {
                    m[s[left]] -= 1;
                    mf = mostFreq(m);
                    left+=1;
                }
            }
            ans=max(right-left+1,ans);
            right += 1;
        }
        return ans;
    }
};