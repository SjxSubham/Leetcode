// 58. Length of Last Word solution

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int i = s.length() - 1;

    while (i >= 0 && s[i] == ' ')
      --i;
    const int lastIndex = i;
    while (i >= 0 && s[i] != ' ')
      --i;

    return lastIndex - i;
  }
};
