class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size() - 1;

        while (carry && i >= 0) {
            int num = carry + digits[i];
            digits[i] = num % 10;
            carry = num / 10;
            i--;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
