/*
Problem: 125. Valid Palindrome (Easy)
Link: https://leetcode.com/problems/valid-palindrome/

Concepts: Two Pointers, String Manipulation
Difficulty: Easy

Problem Statement:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: After removing non-alphanumeric characters, s becomes an empty string "" 
which is a palindrome.

Approach - Two Pointers:
1. Use two pointers: left starting from beginning, right starting from end.
2. Skip non-alphanumeric characters from both sides.
3. Compare characters (case-insensitive).
4. If characters don't match, return false.
5. If pointers cross without finding mismatch, return true.

Time Complexity: O(n) - Single pass through the string
Space Complexity: O(1) - Only using two pointers, no extra space
*/

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // Two pointers approach
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move both pointers
            left++;
            right--;
        }
        
        return true;
    }
};

/*
Helper Functions Used:
1. isalnum(c) - Returns true if c is alphanumeric (letter or digit)
2. tolower(c) - Converts character to lowercase

Example Walkthrough:
s = "A man, a plan, a canal: Panama"

After filtering: "amanaplanacanalpanama"

Two pointers comparison:
left  right
  ↓     ↓
a m a n a p l a n a c a n a l p a n a m a
  ↑                                     ↑
Both 'a' == 'a' ✓

  ↓   ↓
a m a n a p l a n a c a n a l p a n a m a
    ↑                                 ↑
Both 'm' == 'm' ✓

... continues until pointers meet ...

Result: true

Alternative Approach (Not Recommended for Interviews):
You could create a new filtered string and compare it with its reverse,
but this uses O(n) extra space and is less efficient.

class SolutionAlternative {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());
        
        return filtered == reversed;
    }
};

Why Two Pointers is Better:
- O(1) space instead of O(n)
- Can return early if mismatch found
- More efficient as it doesn't create new strings

Test Cases:
1. s = "A man, a plan, a canal: Panama" → Output: true
2. s = "race a car" → Output: false
3. s = " " → Output: true
4. s = "a" → Output: true
5. s = "ab" → Output: false
6. s = "0P" → Output: false
7. s = ".,!" → Output: true (all non-alphanumeric)
*/
