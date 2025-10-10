// Problem: 242. Valid Anagram
// Language: C++
// Approach: Frequency Counting using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(1) (since alphabet size is constant - 26)
// Explanation:
// Two strings are anagrams if they contain the same characters with the same frequency.
// We use an array of size 26 to count character occurrences in both strings
// and compare the counts.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
            return false;

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int i : count)
            if (i != 0) return false;
        return true;
    }
};

/*
Example:
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/
