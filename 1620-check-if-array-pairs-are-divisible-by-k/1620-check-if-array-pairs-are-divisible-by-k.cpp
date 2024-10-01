class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> m;
        for (int i = 0; i < k; i += 1) {
            m[i] = 0;
        }
        for (auto i : arr) {
            if(i%k<0)
            m[k+i%k]+=1;
            else
            m[i % k] += 1;
            cout<<i%k<<"\n";
        }
        if (m[0] % 2 != 0)
            return false;
        for (int i = 1; i < (k-1) / 2 +1; i += 1) {
            cout<<i<<" "<<k-i<<" "<<m[i]<<" "<<m[k-i]<<"\n";
            if (m[i] != m[k - i])
                return false;
        }
        if (k % 2 == 0 && m[k / 2] % 2 != 0)
            return false;
        return true;
    }
};