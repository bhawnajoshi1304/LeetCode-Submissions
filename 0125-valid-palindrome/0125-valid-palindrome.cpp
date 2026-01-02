class Solution {
public:
    int numOfC(char c) {
        if (c <= 'z' && c >= 'a')
            return c - 'a';
        else if (c <= 'Z' && c >= 'A')
            return c - 'A';
        else if(c>='0' && c<='9')
            return 26+c-'0';
        else
            return -1;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1, c = 0, cr = 0;
        while (left < right && right >= 0 && left < s.size()) {
            c = numOfC(s[left]);
            while (c == -1 && left < s.size()-1) {
                left += 1;
                c = numOfC(s[left]);
            }
            cr = numOfC(s[right]);
            while (cr == -1 && right > 0) {
                right -= 1;
                cr = numOfC(s[right]);
            }
            if (c != cr)
                return false;
            cout << c << " " << cr << "\n";
            left += 1;
            right -= 1;
        }
        return true;
    }
};