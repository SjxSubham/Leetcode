class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int count = 0;
        long long ans = 0;
        int l = 0, r = 0;
        vector<int> map2(27, 0), map1(27, 0);
        for (int i = 0; i < word2.size(); i++) {
            map2[word2[i] - 'a']++;
        }
        while (r < word1.size()) {
            map1[word1[r] - 'a']++;
            if (map1[word1[r] - 'a'] == map2[word1[r] - 'a'])
                count += map2[word1[r] - 'a'];
            while (count == word2.size()) {
                ans += (word1.size() - r);
                map1[word1[l] - 'a']--;
                if (map1[word1[l] - 'a'] < map2[word1[l] - 'a'])
                    count -= map2[word1[l] - 'a'];
                l++;
            }
            r++;
        }
        return ans;
    }
};
