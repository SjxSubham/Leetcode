#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            if (isVowel(c)) {
                mp[c]++;
            }
        }
        string total_vow = "AEIOUaeiou", ans;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) ans += s[i];
            else {
                while(mp[total_vow[j]] == 0) j++;
                ans += total_vow[j];
                mp[total_vow[j]]--;
            }
        }
        return ans;
    }
};