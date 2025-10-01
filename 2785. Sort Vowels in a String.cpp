class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelCount(128, 0); 
        for (char c : s) {
            if (isVowel(c)) {
                vowelCount[c]++;
            }
        }
        string sortedVowels = "";
        
        string vowelOrder = "AEIOUaeiou";
        for (char v : vowelOrder) {
            while (vowelCount[v] > 0) {
                sortedVowels += v;
                vowelCount[v]--;
            }
        }
        
        int vowelIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = sortedVowels[vowelIndex++];
            }
        }
        
        return s;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

/* 
Alternative O(n) Solution using Counting Sort:
class Solution {
public:
    string sortVowels(string s) {
        // Count array for vowels (A=65, E=69, I=73, O=79, U=85, a=97, e=101, i=105, o=111, u=117)
        map<char, int> vowelCount;
        
        // Count vowels
        for (char c : s) {
            if (isVowel(c)) {
                vowelCount[c]++;
            }
        }
        
        // Create sorted vowel sequence
        string vowels = "";
        for (auto& p : vowelCount) {
            vowels += string(p.second, p.first);
        }
        
        // Replace vowels in original string
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        
        return s;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

Problem Explanation:
- Sort only the vowels in the string while keeping consonants in place
- Vowels: a, e, i, o, u (both uppercase and lowercase)
- Sort in lexicographical order (ASCII): A < E < I < O < U < a < e < i < o < u

Example: s = "lEetcOde"
- Vowels found: E, e, O, e (positions 1, 2, 5, 7)
- Sorted vowels: E, O, e, e
- Result: "lEOtcede"

Time Complexity: O(n) - two passes through string + O(1) vowel processing
Space Complexity: O(1) - fixed size arrays/maps for vowels only
*/