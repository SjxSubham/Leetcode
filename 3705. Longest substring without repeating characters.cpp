#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        std::unordered_set<char> char_set;
        int left = 0;       
        int maxLength = 0;  
        for (int right = 0; right < n; ++right) {
            char current_char = s[right];
            while (char_set.count(current_char)) {
                char_set.erase(s[left]);
                left++;
            }
            char_set.insert(current_char);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
