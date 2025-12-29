class Solution {
public:
    int table[256];

    Solution() { buildTable(); }

    void buildTable() {
        for (int i = 0; i < 256; i++) {
            int v = i, r = 0;
            for (int j = 0; j < 8; j++) {
                r = (r << 1) | (v & 1);
                v >>= 1;
            }
            table[i] = r;
        }
    }
    int reverseBits(int n) {
        int b0 = n & 255;
        int b1 = (n >> 8) & 255;
        int b2 = (n >> 16) & 255;
        int b3 = (n >> 24) & 255;
        return (table[b0] << 24) | (table[b1] << 16) | (table[b2] << 8) |
               (table[b3]);
    }
};
