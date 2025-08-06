class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        unordered_map<char, int> freq;
        int maxFreq = 0, countMax = 0;

        for (char task : tasks) {
            int f = ++freq[task];
            if (f > maxFreq) {
                maxFreq = f;
                countMax = 1;
            } else if (f == maxFreq) {
                countMax++;
            }
        }
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int emptySlots = partCount * partLength + countMax;
        return max((int)tasks.size(), emptySlots);
    }
};
