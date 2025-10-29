class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> temp(n + 1, 0);
        temp[0] = startTime[0] - 0;
        temp[n] = eventTime - endTime[n - 1];
        for (int i = 1; i < n; i++) {
            temp[i] = startTime[i] - endTime[i - 1];
        }
        int l = 0, r = 0, tempsum = 0, maxsum = 0;
        while (r < temp.size()) {
            tempsum += temp[r];
            if ((r - l) == k) {
                maxsum = max(maxsum, tempsum);
                tempsum -= temp[l];
                l++;
            }
            r++;
        }
        return maxsum;
    }
};
