class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> arr(2 * n);
        copy(colors.begin(), colors.end(), arr.begin());
        copy(colors.begin(), colors.end(), arr.begin() + n);
        int l = 0, r = 1, flag = colors[0], count = 0;
        while (r < arr.size() && l < n) {
            if (arr[r] == flag) l = r;
            else flag = arr[r];
            if ((r - l + 1) == k) {
                count++;
                l++;
            }
            r++;
        }
        return count;
    }
};
