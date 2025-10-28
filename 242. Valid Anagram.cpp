class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        int count[26] = {0};
        
        for(int i = 0; i < s.length(); i++) {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) return false;
        }
        
        return true;
    }
};
