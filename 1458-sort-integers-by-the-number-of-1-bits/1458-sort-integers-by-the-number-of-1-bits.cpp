class Solution {
public:
static int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    static bool comparator(int a,int b){
        int ca=countSetBits(a),cb=countSetBits(b);
        return(ca==cb)?a<b:ca<cb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};